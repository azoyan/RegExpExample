#include "RegExpWidget.h"
#include <QApplication>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  RegExpWidget widget;
  widget.show();

  return a.exec();
}
