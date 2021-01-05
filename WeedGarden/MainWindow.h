#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <time.h>
#include <QDebug>
#include <QInputDialog>
#include <QtGlobal>
#include <QVector>

//Class Files
#include <MyGrows.h>

struct Grows{
    const char* initialTime;
    QString strainName;
    bool isGerminated; //If isGerminated == false ? isSprouted == false : isSprouted == true;
    bool isReady; //When plant has been harvested
    bool isSprouted;
    int currentWeek; //If currentWeek > 30 then plant is considered as done
    QString strainType;
    double THC;
    double CBD;
    double roomTemperature;
    double lamp2PlantDist; //Distance between light and plants
    int airHumidity;
    double pH;
    QString smell;
    int lightSchedule; //in hours
    double potSize;
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateStatus();
    bool checkDouble(Grows strain);
private:
    Ui::MainWindow *ui;
public slots:
    void AddGrow();
    void removeGrow();
private:
    QVector<Grows> cStrain; //Current Strain
};

#endif // MAINWINDOW_H
