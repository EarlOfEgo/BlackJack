/*
* Copyright (c) 2011 Stephan Hagios <stephan.hagios@gmail.com>
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Library General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

#include "CheckGame.h"

CheckGame::CheckGame()
{
    //ctor
}

CheckGame::~CheckGame()
{
    //dtor
}

int CheckGame::checkActualScore(int cards[5])
{
    int finalScore = 0;
    int countOfAces = 0;
    for(int i = 0; i < 5; i++)
    {
        if(cards[i] == 1)
            countOfAces++;
        else
            finalScore += cards[i];
    }
    for(int i = 0; i < countOfAces; i++)
    {
        if((finalScore + 11) <= 21)
            finalScore += 11;
        else
            finalScore += 1;
    }
    return finalScore;
}



