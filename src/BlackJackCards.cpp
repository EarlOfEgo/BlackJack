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

#include "BlackJackCards.h"

//For random shuffling
#include <stdlib.h>
#include <time.h>

BlackJackCards::BlackJackCards()
{
    stackPossition = 0;
    initialiceDeck();
    fillDecksIntoCarStack();
}

BlackJackCards::~BlackJackCards()
{
    //dtor
}

void BlackJackCards::getNextCardInStack(int* value, int* type)
{
    *value = allCards[stackPossition][0];
    *type = allCards[stackPossition][1];
    allCards[stackPossition][0] = -1;
    allCards[stackPossition++][0] = -1;
}

void BlackJackCards::fillDecksIntoCarStack()
{
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 52; j++)
        {
            allCards[j+(i*52)][0] = deck[j][0];
            allCards[j+(i*52)][1] = deck[j][1];
        }
    }
}

void BlackJackCards::shuffleCardStack(int times)
{
    stackPossition = 0;
    srand ( time(NULL) );
    for(int i = 0; i < times; i++)
    {
        for(int j = 0; j < 312; j++)
        {
            int valTmp = allCards[j][0];
            int typTmp = allCards[j][1];
            int randomPossition = rand() % 312;
            allCards[j][0] = allCards[randomPossition][0];
            allCards[j][1] = allCards[randomPossition][1];
            allCards[randomPossition][0] = valTmp;
            allCards[randomPossition][1] = typTmp;
        }
    }
}

void BlackJackCards::initialiceDeck()
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            deck[j+(i*13)][0] = j+1 <= 10 ? j+1 : 10;
            deck[j+(i*13)][1] = i;
        }
    }
}

int BlackJackCards::getDeckValue(int possition)
{
    return deck[possition][0];
}

int BlackJackCards::getDeckType(int possition)
{
    return deck[possition][1];
}


