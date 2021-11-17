#ifndef Card_h
#define Card_h
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

//header class
class Card{

  private:
    char rank;
    char suit;
  
  public:
    //create a blank card
    Card();
    //constructor to create a card, setting the rank and suit
    Card(char r, char s);
    //set an existing blank card to a particular value
    void setCard(char r, char s);
    //return the point value of the card. Ace = 1, 2 - 10, Jack = 10, Queen = 10, King = 10
    int getValue();
    //display the card using 2 fields. EX: Ace of Space would be AS, 10 of Diamond would be 10D
    void showCard();
};

#endif