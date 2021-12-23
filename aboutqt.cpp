#include "aboutqt.h"
#include "ui_aboutqt.h"

aboutQt::aboutQt(QWidget *parent) :QDialog(parent), ui(new Ui::aboutQt)
{
    ui->setupUi(this);
}

aboutQt::~aboutQt()
{
    delete ui;
}
