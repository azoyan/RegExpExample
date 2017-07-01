#include "RegExpWidget.h"
#include <QFormLayout>
#include <QDebug>

RegExpWidget::RegExpWidget(QWidget *parent)
: QWidget(parent)
, m_regExpValidator  (new QRegExpValidator(this))
, m_regExpLineEdit   (new QLineEdit(this))
, m_checkableTextEdit(new QTextEdit(this))
, m_stateLabel       (new QLabel(this))
{
  QFormLayout* formLayout = new QFormLayout(this);
  formLayout->addRow(new QLabel("Regular expression"), m_regExpLineEdit);
  formLayout->addRow(new QLabel(""), m_stateLabel);
  formLayout->addRow(new QLabel("Checkable string"), m_checkableTextEdit);

  connect(m_regExpLineEdit,    &QLineEdit::textEdited,  this, &RegExpWidget::setRegExp);
  connect(m_checkableTextEdit, &QTextEdit::textChanged, this, &RegExpWidget::checkableTextEdited);
}

void RegExpWidget::setRegExp(const QString& regExp) {
  m_regExpValidator->setRegExp(QRegExp(regExp));
}

void RegExpWidget::checkableTextEdited() {
  QString checkableText = m_checkableTextEdit->toPlainText();
  if (!checkableText.isEmpty()) {
    int pos = 0;
    switch (m_regExpValidator->validate(checkableText, pos)) {
    case QValidator::Acceptable:   showState("Acceptable",   "honeydew"); break;
    case QValidator::Intermediate: showState("Intermediate", "azure");    break;
    case QValidator::Invalid:      showState("Invalid",      "pink");     break;
    }
  }
  else showState("", "white");
}

void RegExpWidget::showState(const QString& state, const QString& textBackgroundColor) {
  QString styleSheet = QString("background-color: %1").arg(textBackgroundColor);
  m_checkableTextEdit->setStyleSheet(styleSheet);
  m_stateLabel->setText(state);
}
