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
