
#ifndef Deck_h
#define Deck_h
#include "Card.h"
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
//header class
class Deck{
  private:
    //array of 52 cards to make a whole deck - 4 rows (spades, hearts, diamonds, and clubs ) and 13 columns (Ace, 2-10, J, K, and Q)
    Card deck[4][13];
    int topDeck_row;
    int topDeck_col;
    int totalVal = 0;
    bool prime = false;
    
  public:
    //contructor which creaetes a deck of 52 cards. Ace of Spaces on top followed by the rest of the spades in order, followed by Hearts, Diamonds, and Clubs
    Deck();
    //rest the deck so it looks like a new deck
    void refreshDeck();
    //deal a card from the top of the deck
    Card deal();
    //shuffle the cards in the deck
    void shuffle();
    //return the number of cards left in the deck
    int cardsLeft();
    //calculate the total value of the cards that have been dealt
    int totalValue(Card C);
    //return the total value of the cards that have been dealt
    int getTotalValue();
    //resets the total value of the cards that have been dealt
    int resetTotalValue();
    //checks if value entered is prime by returning true or false
    bool checkPrime(int num);
    //menu
    int menu();
    //show all the cards in the deck: 13 columns and 4 rows
    void showDeck();
};

#endif