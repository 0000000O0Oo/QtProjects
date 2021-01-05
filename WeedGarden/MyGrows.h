#ifndef MYGROWS_H
#define MYGROWS_H

#include <QWidget>

namespace Ui {
class MyGrows;
}

class MyGrows : public QWidget
{
    Q_OBJECT

public:
    explicit MyGrows(QWidget *parent = nullptr);
    ~MyGrows();

private:
    Ui::MyGrows *ui;
};

#endif // MYGROWS_H
