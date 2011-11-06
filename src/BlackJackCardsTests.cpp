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


#include "UnitTest++.h"
#include "BlackJackCards.h"

SUITE(TestBlackJackCards)
{

    BlackJackCards bjc;
    int *value = new int;
    int *type = new int;

    TEST(CheckDeck)
    {
        for(int j = 0; j<4; j++)
        {
            for(int i = 0; i<13; i++)
            {
                int resultValue = bjc.getDeckValue(i+(j*13));
                CHECK_EQUAL(i+1 <= 10 ? i+1 : 10, resultValue);
                int resultType = bjc.getDeckType(i+(j*13));
                CHECK_EQUAL(j, resultType);
            }
        }
    }

    /*
     Takes one card from the stack and compares it with the deck, does it 6 times
    */
    TEST(FillCardsIntoStack)
    {

        for(int k = 0; k < 6; k++)
        {
            for(int j = 0; j<4; j++)
            {
                for(int i = 0; i<13; i++)
                {
                    int resultValue = bjc.getDeckValue(i+(j*13));
                    int resultType = bjc.getDeckType(i+(j*13));
                    bjc.getNextCardInStack(value, type);
                    CHECK_EQUAL(resultValue, *value);
                    CHECK_EQUAL(resultType, *type);
                }
            }

        }
    }

    /*
        CHECK if all cards are there and if the amount of the cards is still 312
    */
    TEST(ShuffleCards)
    {
        int allCards[10][4];
        int cardAmount;
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 4; j++)
                allCards[i][j] = 0;
        }

        BlackJackCards bjc2;
        bjc2.shuffleCardStack(5);
        for(int i = 0; i < 312; i++)
        {
            bjc2.getNextCardInStack(value, type);
            allCards[*value-1][*type]++;
        }


        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                cardAmount += allCards[i][j];
                CHECK_EQUAL(i+1 < 10 ? 6 : 24, allCards[i][j]);
            }
        }
        CHECK_EQUAL(312, cardAmount);
    }

//    delete value;
//    delete type;
}
