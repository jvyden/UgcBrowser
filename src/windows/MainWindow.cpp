#include <iostream>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../api/backends/RefreshApiBackend.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Initialize() {
    auto* backend = new RefreshApiBackend;
    this->InitializeBackend(backend);
}

void MainWindow::InitializeBackend(ApiBackend *backend) {
    QString label = backend->GetPrettyName()
            .append(" @ ")
            .append(backend->GetApiBaseUrl()->toString());
    this->ui->listWidget->addItem(label);

    this->ui->listWidget_2->addItem(QString::fromStdString(backend->GetLevelById("1")->title));
}
