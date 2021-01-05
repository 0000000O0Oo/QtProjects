#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->newGrow, &QPushButton::clicked, this, &MainWindow::AddGrow);
    connect(ui->removeGrow, &QPushButton::clicked, this, &MainWindow::removeGrow);
    connect(ui->quitButton, &QPushButton::clicked, this, QApplication::quit);
    updateStatus();
}

char* getTime(){
    time_t timer;
    time(&timer);
    char *time_msg = ctime(&timer);
    return time_msg;
}

bool MainWindow::checkDouble(Grows strain){
    if(cStrain.size() > 0){
        for(auto iter : MainWindow::cStrain){
            if(strain.strainName == iter.strainName){
                return true;
            }
        }
    } return false;
}

void MainWindow::AddGrow(){
    bool ok;
    QString strainName = QInputDialog::getText(this, tr("New Grow"), tr("Strain name : "), QLineEdit::Normal, tr("OG Kush"), &ok);
    const char* cTime = getTime();
    //qDebug(strainName.toLatin1());
    qDebug("Grow Started at : %s", cTime);
    Grows newStrainInfos = {cTime, strainName, false, false, 0};
    if(!checkDouble(newStrainInfos)){
        cStrain.append(newStrainInfos);
        updateStatus();
    } else {
        qDebug("ERROR : strain already exists !");
    }
}

void MainWindow::removeGrow(){
    bool ok;
    bool isPresent = false;
    int numberIter = 0;
    if(cStrain.size() > 0){
        QString rStrain = QInputDialog::getText(this, tr("Remove Grow"), tr("Strain name : "), QLineEdit::Normal, tr("OG Kush"), &ok);
        for(auto iter : cStrain){
            if(iter.strainName == rStrain){
                isPresent = true;
                cStrain.remove(numberIter);
                updateStatus();
                break;
            }
            else {
                numberIter++;
            }
        }
    } else {
        qDebug("List of current strains is empty !");
    }
}

void MainWindow::updateStatus(){
    int completed = 0;
    for(auto iter : cStrain){
        completed++;
    }
    ui->currentGrows->setText(QString("Current Grows : %1").arg(completed));
}

MainWindow::~MainWindow()
{
    delete ui;
}
