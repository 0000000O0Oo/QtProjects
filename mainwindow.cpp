#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), mTasks()
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->quitButton, &QPushButton::clicked, this, QApplication::quit);
    updateStatus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask(){
    bool ok = false;
    QString name = QInputDialog::getText(this, tr("Add Task"), tr("Task Name :"), QLineEdit::Normal, tr("Untitled task"), &ok);
    if(ok && !name.isEmpty()){
        qDebug() << "Adding new task";
        Task* task = new Task(name);
        mTasks.append(task);
        connect(task, &Task::removed, this, &MainWindow::removeTask);
        ui->tasksLayout->addWidget(task);
        updateStatus();
    }
}

void MainWindow::removeTask(Task* task){
    mTasks.removeOne(task);
    ui->tasksLayout->removeWidget(task);
    delete task;
    updateStatus();
}

void MainWindow::taskStatusChanged(Task* /*task*/){
    updateStatus();
}

void MainWindow::updateStatus(){
    int completed = 0;
    for(auto t : mTasks){
        if(t->isCompleted()){
            completed++;
        }
    }
    int todoCount = mTasks.size() - completed;
    ui->statusLabel->setText(
                    QString("Status: %1 todo / %2 completed")
                        .arg(todoCount)
                        .arg(completed));
}
