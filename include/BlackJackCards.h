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


#ifndef BLACKJACKCARDS_H
#define BLACKJACKCARDS_H


class BlackJackCards
{
    public:
        BlackJackCards();
        virtual ~BlackJackCards();
        int getDeckValue(int possition);
        int getDeckType(int possition);
        void getNextCardInStack(int* value, int* type);
        void shuffleCardStack(int times);
    protected:
    private:
        void initialiceDeck();
        void fillDecksIntoCarStack();
        int deck[52][2];
        int allCards[312][2];
        int stackPossition;
};

#endif // BLACKJACKCARDS_H
