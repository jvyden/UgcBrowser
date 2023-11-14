#include <iostream>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "../api/backends/RefreshApiBackend.h"
#include "../api/backends/SoundShapesApiBackend.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::showEvent(QShowEvent *event) {
    this->Initialize();
}

void MainWindow::Initialize() {
    RefreshApiBackend backend(this);
//    SoundShapesApiBackend backend(this);
    this->InitializeBackend(&backend);
}

void MainWindow::InitializeBackend(ApiBackend *backend) {
    QString label = backend->GetPrettyName()
            .append(" @ ")
            .append(backend->GetApiBaseUrl()->toString());
    this->ui->apiList->addItem(label);

    std::vector<ApiLevel> levels(100);
    backend->GetRecentLevels(0, &levels);
    
    for (auto & level : levels) {
        this->ui->levelList->addItem(level.title);
    }
}
