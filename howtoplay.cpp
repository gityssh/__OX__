#include "howtoplay.h"
#include "ui_howtoplay.h"

HowToPlay::HowToPlay(QWidget *parent) :QDialog(parent), ui(new Ui::HowToPlay)
{
    ui->setupUi(this);
}

HowToPlay::~HowToPlay()
{
    delete ui;
}
