#include "menuWindow.h"
#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    menuWindow window = menuWindow(nullptr);
    window.show();
    return app.exec();
}