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


#include "gtest/gtest.h"
#include "BlackJackCards.h"

BlackJackCards bjc;
int *value = new int;
int *type = new int;

TEST(CheckDeck, equal)
{
    for(int j = 0; j<4; j++)
    {
        for(int i = 0; i<13; i++)
        {
            int resultValue = bjc.getDeckValue(i+(j*13));
            EXPECT_EQ(i+1 <= 10 ? i+1 : 10, resultValue);
            int resultType = bjc.getDeckType(i+(j*13));
            EXPECT_EQ(j, resultType);
        }
    }
}

/*
 Takes one card from the stack and compares it with the deck, does it 6 times
*/
TEST(FillCardsIntoStack, equal)
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
                EXPECT_EQ(resultValue, *value);
                EXPECT_EQ(resultType, *type);
            }
        }

    }
}

/*
    CHECK if all cards are there and if the amount of the cards is still 312
*/
TEST(ShuffleCards, equal)
{
    int allCards[10][4];
    int cardAmount = 0;
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
            EXPECT_EQ(i+1 < 10 ? 6 : 24, allCards[i][j]);
        }
    }
    ASSERT_EQ(312, cardAmount);
}
