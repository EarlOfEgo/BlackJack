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
#include "CheckGame.h"

SUITE(TestCheckGame)
{
    CheckGame cg;

    TEST(CheckActualScoreWithBJ)
    {
        int cards[5] = {1, 10, 0 ,0 ,0};
        int result = cg.checkActualScore(cards);
        CHECK_EQUAL(21,result);
    }

    TEST(CheckActualScoreWithAce)
    {
        int cards[5] = {1, 10, 10 ,0 ,0};
        int result = cg.checkActualScore(cards);
        CHECK_EQUAL(21,result);
    }

    TEST(CheckActualScoreWithAce2)
    {
        int cards[5] = {1, 10,0 ,0 ,0};
        int result = cg.checkActualScore(cards);
        CHECK_EQUAL(21,result);
    }
}

