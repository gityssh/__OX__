#ifndef ABOUTQT_H
#define ABOUTQT_H

#include <QDialog>

namespace Ui {
class aboutQt;
}

class aboutQt : public QDialog
{
    Q_OBJECT

    public:
        explicit aboutQt(QWidget *parent = nullptr);
        ~aboutQt();

    private:
        Ui::aboutQt *ui;
};

#endif // ABOUTQT_H
