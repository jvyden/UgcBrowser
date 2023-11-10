#include <iostream>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../backends/RefreshApiBackend.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::initialize() {
    auto* backend = new RefreshApiBackend;
    this->ui->listWidget->addItem(backend->GetBackendName());
}
