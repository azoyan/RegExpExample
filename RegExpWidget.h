#ifndef REGEXPWIDGET_H
#define REGEXPWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QRegExpValidator>
#include <QTextEdit>
#include <QLabel>

class RegExpWidget : public QWidget {
  Q_OBJECT  
public:
  RegExpWidget(QWidget* parent = 0);
private:
  QRegExpValidator* m_regExpValidator;
  QLineEdit*        m_regExpLineEdit;
  QTextEdit*        m_checkableTextEdit;
  QLabel*           m_stateLabel;
private slots:
  void setRegExp(const QString& regExp);
  void checkableTextEdited();
private:
  void showState(const QString& state, const QString& textBackgroundColor);
};

#endif // REGEXPWIDGET_H
