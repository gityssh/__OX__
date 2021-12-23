#include "victory.h"

void Victory::assignMoves(int __index, int __value)
{
    arr__[__index] = __value;
}

void Victory::winCheck()
{
    // ----- Player 1 wining permutations -----
    // horizontal
    if(arr__[0] == 1 && arr__[1] == 1 && arr__[2] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 1;
    }
    if(arr__[3] == 1 && arr__[4] == 1 && arr__[5] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 2;
    }
    if(arr__[6] == 1 && arr__[7] == 1 && arr__[8] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 3;
    }

    // virticle
    if(arr__[0] == 1 && arr__[3] == 1 && arr__[6] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 4;
    }
    if(arr__[1] == 1 && arr__[4] == 1 && arr__[7] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 5;
    }
    if(arr__[2] == 1 && arr__[5] == 1 && arr__[8] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 6;
    }

    // cross-sectional
    if(arr__[0] == 1 && arr__[4] == 1 && arr__[8] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 7;
    }
    if(arr__[2] == 1 && arr__[4] == 1 && arr__[6] == 1)
    {
        _Flag_WhoWin = 1;
        _Flag_HowWin = 8;
    }

    // ----- Player 2 wining permutations -----
    // horizontal
    if(arr__[0] == 2 && arr__[1] == 2 && arr__[2] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 1;
    }
    if(arr__[3] == 2 && arr__[4] == 2 && arr__[5] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 2;
    }
    if(arr__[6] == 2 && arr__[7] == 2 && arr__[8] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 3;
    }

    // virticle
    if(arr__[0] == 2 && arr__[3] == 2 && arr__[6] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 4;
    }
    if(arr__[1] == 2 && arr__[4] == 2 && arr__[7] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 5;
    }
    if(arr__[2] == 2 && arr__[5] == 2 && arr__[8] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 6;
    }

    // cross-sectional
    if(arr__[0] == 2 && arr__[4] == 2 && arr__[8] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 7;
    }
    if(arr__[2] == 2 && arr__[4] == 2 && arr__[6] == 2)
    {
        _Flag_WhoWin = 2;
        _Flag_HowWin = 8;
    }

    //Draw
    if((arr__[0] == 2 || arr__[0] == 1) && (arr__[1] == 2 || arr__[1] == 1) && (arr__[2] == 2 || arr__[2] == 1) && (arr__[3] == 2 || arr__[3] == 1) && (arr__[4] == 2 || arr__[4] == 1) && (arr__[5] == 2 || arr__[5] == 1) && (arr__[6] == 2 || arr__[6] == 1) && (arr__[7] == 2 || arr__[7] == 1) && (arr__[8] == 2 || arr__[8] == 1))
    {
        if(_Flag_WhoWin == 0){
            _Flag_WhoWin = 3;
        }
    }
}
