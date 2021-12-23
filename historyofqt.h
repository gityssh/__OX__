#ifndef HISTORYOFQT_H
#define HISTORYOFQT_H

#include <QDialog>

namespace Ui {
class HistoryOfQt;
}

class HistoryOfQt : public QDialog
{
    Q_OBJECT

    public:
        explicit HistoryOfQt(QWidget *parent = nullptr);
        ~HistoryOfQt();

    private:
        Ui::HistoryOfQt *ui;
};

#endif // HISTORYOFQT_H
