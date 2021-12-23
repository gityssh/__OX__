#ifndef HOWTOPLAY_H
#define HOWTOPLAY_H

#include <QDialog>

namespace Ui {
class HowToPlay;
}

class HowToPlay : public QDialog
{
    Q_OBJECT

    public:
        explicit HowToPlay(QWidget *parent = nullptr);
        ~HowToPlay();

    private:
        Ui::HowToPlay *ui;
};

#endif // HOWTOPLAY_H
