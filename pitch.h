#ifndef PITCH_H
#define PITCH_H

#include <QMainWindow>
#include <QSound>
#include "victory.h"
#include <QLabel>
#include "howtoplay.h"
#include "historyofqt.h"
#include "aboutqt.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Pitch; }
QT_END_NAMESPACE

class Pitch : public QMainWindow, public Victory
{
    Q_OBJECT

    public:
        Pitch(QWidget *parent = nullptr);
        QLabel* img;

        // Players can able to change icons. These are the array of icon files.
        char iconLink[17][100] = {
                                    {":Images/Images/cross.png"},
                                    {":Images/Images/circle.png"},
                                    {":Images/Images/doremon.png"},
                                    {":Images/Images/sizuka.png"},
                                    {":Images//Images/nobita.png"},
                                    {":Images/Images/jerry.png"},
                                    {":Images/Images/tom.png"},
                                    {":Images/Images/actioncommet.png"},
                                    {":Images/Images/shinshan.png"},
                                    {":Images/Images/shinshan1.png"},
                                    {":Images/Images/shiro.png"},
                                    {":Images/Images/hatodi.png"},
                                    {":Images/Images/shinjo.png"},
                                    {":Images/Images/shishimaru.png"},
                                    {":Images/Images/kitrekchu.png"},
                                    {":Images/Images/korosuke.png"},
                                    {":Images/Images/perman.png"}
                                };
        int sizeof_iconLink = 16;
        int P1iconPtr = 0;
        int P2iconPtr = 1;

        void davDashbar();
        void drawline();
        void celibrate();
        void countiue();
        void newGame();

        ~Pitch();

private slots:
        void on_p1Icon_clicked();

        void on_p2Icon_clicked();

        void on_but_1_clicked();

        void on_but_2_clicked();

        void on_but_3_clicked();

        void on_but_4_clicked();

        void on_but_5_clicked();

        void on_but_6_clicked();

        void on_but_7_clicked();

        void on_but_8_clicked();

        void on_but_9_clicked();

        void on_countinue_clicked();

        void on_newgame_clicked();

        void on_actionExit_triggered();

        void on_actionThe_history_of_XO_triggered();

        void on_actionHow_To_Play_triggered();

        void on_actionAbout_QT_triggered();

private:
    Ui::Pitch *ui;
};


#endif // PITCH_H
