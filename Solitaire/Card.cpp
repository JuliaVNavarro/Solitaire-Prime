#include "Card.h"
#include <iostream>
#include <string>
using namespace std;

Card::Card(){
  //set the rank and suit to be blank
  rank = ' ';
  suit = ' ';
}

Card::Card(char r, char s){
  //create card with the provided rank and suit characters
  rank = r;
  suit = s;
}

void Card::setCard(char r, char s){
  //change an existing card's rank and suit to the provided rank and suit characters
  rank = r;
  suit = s; 
}

int Card::getValue(){
  //generate variable for value of the card
  int val = 0;
  //if the card is empty the value is 0
  if(rank == ' '){
    val = 0;
  }
  //if the rank is Ace, the value is 1
  else if(rank == 'A'){
    val = 1;
  }
  //if the rank is 10, then the value is 10
  else if(rank == 'T'){
    val = 10;
  }
  //if the rank is Jack, the value is 10
  else if(rank == 'J'){
    val = 10;
  }
  //if the rank is Queen, the value is 10
  else if(rank == 'Q'){
    val = 10;
  }
  //if the rank is K, the value is 10
  else if(rank == 'K'){
    val = 10;
  }
  //otherwise, the value is the rank
  else {
    val = (int)rank - 48;
  }
  //return the card's value
  return val;
}

void Card::showCard(){
  //check to see if the card's rank is 10, then convert 'T' to display 10
  if(rank == 'T'){
    cout << 10 << suit << ", ";
  } 
  //otherwise, display card with the correct rank and suit.
  else {
    cout << rank << suit << ", ";
  }
  
}