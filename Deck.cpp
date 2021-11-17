#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>

using namespace std;


Deck::Deck(){
  //the deck will have 4 rows, begining with the spades in the first row, hearts in the second row, diamonds in the third row, and the clubs in the fourth row
  for(int i = 0; i < 4; i++){
    char s = ' ';
    if(i == 0){
      s = 'S';
    }
    else if(i == 1){
      s = 'H';
    }
    else if(i == 2){
      s = 'D';
    }
    else if(i == 3){
      s = 'C';
    }
    //each row will have 13 cards beginning with the Ace, 2 - 10, Jack, Queen, and King.
    for(int j = 0; j < 13; j++){
      char r = ' ';
      if(j == 0){
        r = 'A';
      }
      else if(j >= 1 && j <= 8){
        r = '0' + (j + 1);
      }
      else if(j == 9){
        r = 'T';
      }
      else if(j == 10){
        r = 'J';
      }
      else if(j == 11){
        r = 'Q';
      }
      else if(j == 12){
        r = 'K';
      }
      //each card in the deck will have a rank and suit set.
      deck[i][j].setCard(r,s);
    }
  }
}

void Deck::refreshDeck(){
   //the deck will have 4 rows, begining with the spades in the first row, hearts in the second row, diamonds in the third row, and the clubs in the fourth row
  for(int i = 0; i < 4; i++){
    char s = ' ';
    if(i == 0){
      s = 'S';
    }
    else if(i == 1){
      s = 'H';
    }
    else if(i == 2){
      s = 'D';
    }
    else if(i == 3){
      s = 'C';
    }
    //each row will have 13 cards beginning with the Ace, 2 - 10, Jack, Queen, and King.
    for(int j = 0; j < 13; j++){
      char r = ' ';
      if(j == 0){
        r = 'A';
      }
      else if(j >= 1 && j <= 8){
        r = '0' + (j + 1);
      }
      else if(j == 9){
        r = 'T';
      }
      else if(j == 10){
        r = 'J';
      }
      else if(j == 11){
        r = 'Q';
      }
      else if(j == 12){
        r = 'K';
      }
      //each card in the deck will have a rank and suit set.
      deck[i][j].setCard(r,s);
    }
  }
}

Card Deck::deal(){
  Card tempCard;
  //start from the beginning just in case
  topDeck_row = 0;
  topDeck_col = 0;
  //search for the next card in the deck
  while(deck[topDeck_row][topDeck_col].getValue() == 0){
    deck[topDeck_row][topDeck_col].getValue();
    //stop searching once the next card in the deck is found
    if(deck[topDeck_row][topDeck_col].getValue() != 0){
      break;
    }
    //check to see if you have reached the end of the row
    else if(topDeck_col == 12){
      //check to see if you have reached the end of the entire deck
      if(topDeck_row == 3){
        //go back to the beginning just in case
        topDeck_row = 0;
        topDeck_col = 0;
        //end the loop
        break;
      }
      //if you reached the end of the row but not the end of the deck, move onto the next row
      else if(topDeck_row < 3){
        topDeck_row += 1;
        topDeck_col = 0;
      } 
    }
    //if you have not reached the end of the row, move onto the next column
    else if(topDeck_col < 12){
      topDeck_col += 1;
    }
  }
  //assign the temp card to the card at the top of the deck
  tempCard = deck[topDeck_row][topDeck_col];
  //get the new total value of the cards drawn
  totalValue(deck[topDeck_row][topDeck_col]);
  //remove the top card from the deck
  deck[topDeck_row][topDeck_col].setCard(' ', ' ');
  //return the top card from the deck to be displayed
  return tempCard;
}

void Deck::shuffle(){
  //generate ints for two random rows and columns
  int rand_row1 = 0;
  int rand_col1 = 0;
  int rand_row2 = 0;
  int rand_col2 = 0;
  //generate a temp Card 
  Card temp[1];

  srand(time(0));
  for(int i = 1; i <= 52; i ++){
    //randomly generate first row & column
    rand_row1 = rand() % 4;
    rand_col1 = rand() % 13;
    //randomly generate second row & column
    rand_row2 = rand() % 4;
    rand_col2 = rand() % 13;
    //copy the card in the first row & column into the temp card
    temp[0] = deck[rand_row1][rand_col1];
    //change the card in the first row & column to equal the card in the second row & column
    deck[rand_row1][rand_col1] = deck[rand_row2][rand_col2];
    //change the card in the second row & column to equal the temp card (AKA the original card in the first row & column)
    deck[rand_row2][rand_col2] = temp[0];

  }
}

int Deck::cardsLeft(){
  //generate variable to keep track of cards left in the deck
  int totalCards = 0; 
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 13; j++){
      if(deck[i][j].getValue() > 0){
        totalCards += 1;
      }
    }
  }
  return totalCards;
}

int Deck::totalValue(Card c){
  //add the drawn card's value to the total value
  return totalVal += c.getValue();
}

int Deck::getTotalValue(){
  //return the total value of drawn cards
  return totalVal;
}

int Deck::resetTotalValue(){
  return totalVal = 0;
}

bool Deck::checkPrime(int num){
  int n = num - 1;
  if(num == 1){
      prime = false;
  }
  else if(num > 1){
    for(int i = n; n > 1; n--){
      if(num%n == 0){
        prime = false;
        break;
      }
      else if(num%n > 0){
        if(n == 2){
          prime = true;
        }
      }
    }
  }
  return prime;
}

int Deck::menu(){
  
  cout << "\n1) New Deck\n2) Display Deck\n3) Shuffle Deck\n4) Play Solitair Prime\n5) Exit\n";
  int choice;
  cin >> choice;
  
  return choice;
}

void Deck::showDeck(){

  //display the deck
  for(int i = 0; i < 4; i++){
    //new line for each row
    cout << "\n";
    for(int j = 0; j < 13; j++){
      //display the card in each row
      deck[i][j].showCard();
    }
  }
  cout << "\n";
  
}