#ifndef VICTORY_H
#define VICTORY_H

class Victory
{
    public:
        bool _Flag_MatchOn = false;
        bool _Flag_Turn = true;
        bool _Flag_Dav = true;
        int _Flag_WhoWin = 0;
        int _Flag_HowWin = 0;
        int _Flag_P1Win = 0;
        int _Flag_P2Win = 0;
        int arr__[9] = {0};

        void assignMoves(int,int);
        void winCheck();
};

#endif // VICTORY_H
