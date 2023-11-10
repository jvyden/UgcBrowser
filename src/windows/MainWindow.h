#ifndef UGCBROWSER_MAINWINDOW_H
#define UGCBROWSER_MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void initialize();
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
};


#endif //UGCBROWSER_MAINWINDOW_H
