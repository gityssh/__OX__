#include "historyofqt.h"
#include "ui_historyofqt.h"

HistoryOfQt::HistoryOfQt(QWidget *parent) :QDialog(parent), ui(new Ui::HistoryOfQt)
{
    ui->setupUi(this);
}

HistoryOfQt::~HistoryOfQt()
{
    delete ui;
}
