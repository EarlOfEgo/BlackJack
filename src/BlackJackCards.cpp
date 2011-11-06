#include "BlackJackCards.h"

//For random shuffling
#include <stdlib.h>
#include <time.h>

#include <stdio.h>

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


