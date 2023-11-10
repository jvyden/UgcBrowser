#include "QApplication"
#include "windows/MainWindow.h"

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();

    return QApplication::exec();
}
