#include "pitch.h"
#include "ui_pitch.h"

Pitch::Pitch(QWidget *parent): QMainWindow(parent), ui(new Ui::Pitch)
{
    ui->setupUi(this);
    ui->p1Icon->setIcon(QIcon(iconLink[P1iconPtr]));
    ui->p2Icon->setIcon(QIcon(iconLink[P2iconPtr]));
    ui->turn2Label->setVisible(false);
    ui->newgame->setVisible(false);
    ui->countinue->setVisible(false);
}
Pitch::~Pitch()
{
    delete ui;
}

void Pitch::davDashbar()
{
    if(_Flag_Turn == true){
        if(_Flag_Dav == true){
            ui->turn1Label->setVisible(false);
            ui->turn2Label->setVisible(true);
        }

        if(_Flag_Dav == false){
            ui->turn2Label->setVisible(false);
            ui->turn1Label->setVisible(true);
        }
    }
    if(_Flag_Turn == false){
        if(_Flag_Dav == true){
            ui->turn1Label->setVisible(false);
            ui->turn2Label->setVisible(true);
        }

        if(_Flag_Dav == false){
            ui->turn2Label->setVisible(false);
            ui->turn1Label->setVisible(true);
        }
    }
}

void Pitch::drawline()
{
    // X-Horizontal
    if(_Flag_HowWin == 1){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/X.png"));
        img->setGeometry(20, 40, 260, 6);
        img->show();
    }
    if(_Flag_HowWin == 2){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/X.png"));
        img->setGeometry(20, 145, 260, 6);
        img->show();
    }
    if(_Flag_HowWin == 3){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/X.png"));
        img->setGeometry(20, 250, 260, 6);
        img->show();
    }

    // Y-Verticle
    if(_Flag_HowWin == 4){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/Y.png"));
        img->setGeometry(45, 20, 6, 260);
        img->show();
    }
    if(_Flag_HowWin == 5){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/Y.png"));
        img->setGeometry(145, 20, 6, 260);
        img->show();
    }
    if(_Flag_HowWin == 6){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/Y.png"));
        img->setGeometry(250, 20, 6, 260);
        img->show();
    }

    //cross-sectional
    if(_Flag_HowWin == 7){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/XY.png"));
        img->setGeometry(10, 0, 300, 300);
        img->show();
    }
    if(_Flag_HowWin == 8){
        img = new QLabel(ui->frame);
        img->setPixmap(QPixmap(":/Images/Images/YX.png"));
        img->setGeometry(5, 0, 300, 300);
        img->show();
    }
}

void Pitch::celibrate()
{
    if(_Flag_WhoWin == 1){
        QSound::play(":/Music/Music/win.wav");
        _Flag_P1Win++;
        ui->player1Win->setText(QString::number(_Flag_P1Win));
        drawline();
    }
    if(_Flag_WhoWin == 2){
        QSound::play(":/Music/Music/win.wav");
        _Flag_P2Win++;
        ui->player2Win->setText(QString::number(_Flag_P2Win));
        drawline();
    }
    if(_Flag_WhoWin == 3){
        QSound::play(":/Music/Music/tye.wav");
    }
    if (_Flag_WhoWin == 1 || _Flag_WhoWin == 2 || _Flag_WhoWin == 3)
    {
        ui->newgame->setVisible(true);
        ui->countinue->setVisible(true);
        QObject::disconnect(ui->but_1, SIGNAL(clicked(bool)), this, SLOT(on_but_1_clicked()));
        QObject::disconnect(ui->but_2, SIGNAL(clicked(bool)), this, SLOT(on_but_2_clicked()));
        QObject::disconnect(ui->but_3, SIGNAL(clicked(bool)), this, SLOT(on_but_3_clicked()));

        QObject::disconnect(ui->but_4, SIGNAL(clicked(bool)), this, SLOT(on_but_4_clicked()));
        QObject::disconnect(ui->but_5, SIGNAL(clicked(bool)), this, SLOT(on_but_5_clicked()));
        QObject::disconnect(ui->but_6, SIGNAL(clicked(bool)), this, SLOT(on_but_6_clicked()));

        QObject::disconnect(ui->but_7, SIGNAL(clicked(bool)), this, SLOT(on_but_7_clicked()));
        QObject::disconnect(ui->but_8, SIGNAL(clicked(bool)), this, SLOT(on_but_8_clicked()));
        QObject::disconnect(ui->but_9, SIGNAL(clicked(bool)), this, SLOT(on_but_9_clicked()));
    }
}

// Logic to select player I icon, Player I will not be able to select the icon that Player II have selected.
void Pitch::on_p1Icon_clicked()
{
    if(_Flag_MatchOn == false)
    {
        if(P1iconPtr < sizeof_iconLink)
        {
            P1iconPtr++;
            if(P1iconPtr == P2iconPtr)
            {
                if(P1iconPtr < sizeof_iconLink)
                {
                    P1iconPtr++;
                }
                else{
                    P1iconPtr = 0;
                    if(P1iconPtr == P2iconPtr)
                    {
                        P1iconPtr++;
                        ui->p1Icon->setIcon(QIcon(iconLink[P1iconPtr]));
                    }
                    else{
                        ui->p1Icon->setIcon(QIcon(iconLink[P1iconPtr]));
                    }
                }
            }
            QSound::play(":/Music/Music/restart.wav");
            ui->p1Icon->setIcon(QIcon(iconLink[P1iconPtr]));
        }
        else{
            P1iconPtr = 0;
            if(P1iconPtr == P2iconPtr)
            {
                P1iconPtr++;
                ui->p1Icon->setIcon(QIcon(iconLink[P1iconPtr]));
            }
            else{
                ui->p1Icon->setIcon(QIcon(iconLink[P1iconPtr]));
            }
            QSound::play(":/Music/Music/restart.wav");
        }
    }
}

// Logic to select player II icon, Player II will not be able to select the icon that Player I have selected.
void Pitch::on_p2Icon_clicked()
{
    if(_Flag_MatchOn == false)
    {
        if(P2iconPtr < sizeof_iconLink)
        {
            P2iconPtr++;
            if(P2iconPtr == P1iconPtr)
            {
                if(P2iconPtr < sizeof_iconLink)
                {
                    P2iconPtr++;
                }
                else{
                    P2iconPtr = 0;
                    if(P2iconPtr == P1iconPtr)
                    {
                        P2iconPtr++;
                        ui->p2Icon->setIcon(QIcon(iconLink[P2iconPtr]));
                    }
                    else{
                        ui->p2Icon->setIcon(QIcon(iconLink[P2iconPtr]));
                    }
                }
            }
            QSound::play(":/Music/Music/restart.wav");
            ui->p2Icon->setIcon(QIcon(iconLink[P2iconPtr]));
        }
        else{
            P2iconPtr = 0;
            if(P2iconPtr == P1iconPtr)
            {
                P2iconPtr++;
                ui->p2Icon->setIcon(QIcon(iconLink[P2iconPtr]));
            }
            else{
                ui->p2Icon->setIcon(QIcon(iconLink[P2iconPtr]));
            }
            QSound::play(":/Music/Music/restart.wav");
        }
    }
}


void Pitch::on_newgame_clicked()
{
    _Flag_MatchOn = false;
    _Flag_Dav = true;
    _Flag_Turn = true;
    for(int i=0; i<9;i++){
        arr__[i] = 0;
     }
    _Flag_P1Win = 0;
    _Flag_P2Win = 0;
    _Flag_WhoWin = 0;
    _Flag_HowWin = 0;
    ui->player1Win->setText("");
    ui->player2Win->setText("");
    QSound::play(":/Music/Music/restart.wav");
    P1iconPtr = 0;
    ui->p1Icon->setIcon(QIcon(iconLink[P1iconPtr]));
    P2iconPtr = 1;
    ui->p2Icon->setIcon(QIcon(iconLink[P2iconPtr]));

    ui->turn2Label->setVisible(false);
    ui->turn1Label->setVisible(true);

    QObject::connect(ui->but_1, SIGNAL(clicked(bool)), this, SLOT(on_but_1_clicked()));
    QObject::connect(ui->but_2, SIGNAL(clicked(bool)), this, SLOT(on_but_2_clicked()));
    QObject::connect(ui->but_3, SIGNAL(clicked(bool)), this, SLOT(on_but_3_clicked()));
    QObject::connect(ui->but_4, SIGNAL(clicked(bool)), this, SLOT(on_but_4_clicked()));
    QObject::connect(ui->but_5, SIGNAL(clicked(bool)), this, SLOT(on_but_5_clicked()));
    QObject::connect(ui->but_6, SIGNAL(clicked(bool)), this, SLOT(on_but_6_clicked()));
    QObject::connect(ui->but_7, SIGNAL(clicked(bool)), this, SLOT(on_but_7_clicked()));
    QObject::connect(ui->but_8, SIGNAL(clicked(bool)), this, SLOT(on_but_8_clicked()));
    QObject::connect(ui->but_9, SIGNAL(clicked(bool)), this, SLOT(on_but_9_clicked()));

    ui->but_1->setIcon(QIcon());
    ui->but_2->setIcon(QIcon());
    ui->but_3->setIcon(QIcon());
    ui->but_4->setIcon(QIcon());
    ui->but_5->setIcon(QIcon());
    ui->but_6->setIcon(QIcon());
    ui->but_7->setIcon(QIcon());
    ui->but_8->setIcon(QIcon());
    ui->but_9->setIcon(QIcon());

    img->setPixmap(QPixmap());
    img->setVisible(false);
    ui->newgame->setVisible(false);
    ui->countinue->setVisible(false);
}

void Pitch::on_countinue_clicked()
{
    _Flag_MatchOn = false;
    QSound::play(":/Music/Music/restart.wav");
    for(int i=0; i<9;i++){
        arr__[i] = 0;
     }
    if(_Flag_Turn == true){
        _Flag_Dav = false;
        _Flag_Turn = false;
        ui->turn1Label->setVisible(false);
        ui->turn2Label->setVisible(true);
    }
    else{
        _Flag_Dav = true;
        _Flag_Turn = true;
        ui->turn2Label->setVisible(false);
        ui->turn1Label->setVisible(true);
    }
    _Flag_WhoWin = 0;
    _Flag_HowWin = 0;

    QObject::connect(ui->but_1, SIGNAL(clicked(bool)), this, SLOT(on_but_1_clicked()));
    QObject::connect(ui->but_2, SIGNAL(clicked(bool)), this, SLOT(on_but_2_clicked()));
    QObject::connect(ui->but_3, SIGNAL(clicked(bool)), this, SLOT(on_but_3_clicked()));
    QObject::connect(ui->but_4, SIGNAL(clicked(bool)), this, SLOT(on_but_4_clicked()));
    QObject::connect(ui->but_5, SIGNAL(clicked(bool)), this, SLOT(on_but_5_clicked()));
    QObject::connect(ui->but_6, SIGNAL(clicked(bool)), this, SLOT(on_but_6_clicked()));
    QObject::connect(ui->but_7, SIGNAL(clicked(bool)), this, SLOT(on_but_7_clicked()));
    QObject::connect(ui->but_8, SIGNAL(clicked(bool)), this, SLOT(on_but_8_clicked()));
    QObject::connect(ui->but_9, SIGNAL(clicked(bool)), this, SLOT(on_but_9_clicked()));

    ui->but_1->setIcon(QIcon());
    ui->but_2->setIcon(QIcon());
    ui->but_3->setIcon(QIcon());
    ui->but_4->setIcon(QIcon());
    ui->but_5->setIcon(QIcon());
    ui->but_6->setIcon(QIcon());
    ui->but_7->setIcon(QIcon());
    ui->but_8->setIcon(QIcon());
    ui->but_9->setIcon(QIcon());

    img->setPixmap(QPixmap());
    img->setVisible(false);
    ui->newgame->setVisible(false);
    ui->countinue->setVisible(false);
}


void Pitch::on_but_1_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(0, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_1->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_1, SIGNAL(clicked(bool)), this, SLOT(on_but_1_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(0, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_1->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_1, SIGNAL(clicked(bool)), this, SLOT(on_but_1_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_2_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(1, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_2->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_2, SIGNAL(clicked(bool)), this, SLOT(on_but_2_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(1, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_2->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_2, SIGNAL(clicked(bool)), this, SLOT(on_but_2_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_3_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(2, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_3->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_3, SIGNAL(clicked(bool)), this, SLOT(on_but_3_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(2, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_3->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_3, SIGNAL(clicked(bool)), this, SLOT(on_but_3_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_4_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(3, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_4->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_4, SIGNAL(clicked(bool)), this, SLOT(on_but_4_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(3, 2);
        davDashbar();
        QSound::play("D:/Project's/Tic tac toe/Genny/New folder/Test_Prj_1/Music/player_2.wav");
        ui->but_4->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_4, SIGNAL(clicked(bool)), this, SLOT(on_but_4_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_5_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(4, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_5->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_5, SIGNAL(clicked(bool)), this, SLOT(on_but_5_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(4, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_5->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_5, SIGNAL(clicked(bool)), this, SLOT(on_but_5_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_6_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(5, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_6->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_6, SIGNAL(clicked(bool)), this, SLOT(on_but_6_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(5, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_6->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_6, SIGNAL(clicked(bool)), this, SLOT(on_but_6_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_7_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(6, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_7->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_7, SIGNAL(clicked(bool)), this, SLOT(on_but_7_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(6, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_7->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_7, SIGNAL(clicked(bool)), this, SLOT(on_but_7_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_8_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(7, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_8->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_8, SIGNAL(clicked(bool)), this, SLOT(on_but_8_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(7, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_8->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_8, SIGNAL(clicked(bool)), this, SLOT(on_but_8_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}


void Pitch::on_but_9_clicked()
{
    _Flag_MatchOn = true;
    if (_Flag_Dav == true){
        assignMoves(8, 1);
        davDashbar();
        QSound::play(":/Music/Music/player_1.wav");
        ui->but_9->setIcon(QIcon(iconLink[P1iconPtr]));
        QObject::disconnect(ui->but_9, SIGNAL(clicked(bool)), this, SLOT(on_but_9_clicked()));
        _Flag_Dav = false;
    }
    else{
        assignMoves(8, 2);
        davDashbar();
        QSound::play(":/Music/Music/player_2.wav");
        ui->but_9->setIcon(QIcon(iconLink[P2iconPtr]));
        QObject::disconnect(ui->but_9, SIGNAL(clicked(bool)), this, SLOT(on_but_9_clicked()));
        _Flag_Dav = true;
    }

    winCheck();
    celibrate();
}

void Pitch::on_actionExit_triggered()
{
    QApplication::quit();
}


void Pitch::on_actionThe_history_of_XO_triggered()
{
    HistoryOfQt show;
    show.setModal(true);
    show.exec();
}

void Pitch::on_actionHow_To_Play_triggered()
{
    HowToPlay show;
    show.setModal(true);
    show.exec();
}

void Pitch::on_actionAbout_QT_triggered()
{
    aboutQt show;
    show.setModal(true);
    show.exec();
}

