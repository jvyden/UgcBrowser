#include <iostream>
#include "QApplication"
#include "windows/MainWindow.h"

int main(int argc, char *argv[]) {
    // I told you. It's literally a hello world right now.
    // There's nothing here in this project yet. Go away.
    std::cout << "Hello, World!" << std::endl;
    
    QApplication application(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    
    return application.exec();
}
