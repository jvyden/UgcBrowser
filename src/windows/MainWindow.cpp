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
    this->ui->apiList->addItem(label);

    this->ui->levelList->addItem(QString::fromStdString(backend->GetLevelById("1")->title));
    this->ui->levelList->addItem(QString::fromStdString(backend->GetLevelById("2")->title));
    this->ui->levelList->addItem(QString::fromStdString(backend->GetLevelById("3")->title));
}
