// 	Julia Navarro
//	CECS 282 section 01
//	Solitaire Prime - Program 1
// 	09/13/2021
// 
//  I certify that this program is my own original work. I did not copy any part of this program from 
//  any other source. I further certify that I typed each and every line of code in this program.


#include <iostream>
#include "Deck.h"
#include "Card.h"
using namespace std;
#include <string>


int main() {
  //create general deck
  Deck d1;
  //Welcome the user
  cout << "Welcome to Solitaire Prime!\n";
  //declaire variable to keep track of the user's menu input
  int choice;
  //while the user does not decide to quit the game....
  while(choice != 5){
    //display the menu and prompt an entry from the user
    choice = d1.menu();
    if(choice == 1){
      //create a new deck if the user chooses 1 from the menu
      d1.refreshDeck();
    }
    else if(choice == 2){
      //display the ceck if the user chooses 2 from the menu
      d1.showDeck();
    }
    //shuffle the deck if the user chooses 3 from the menu
    else if(choice == 3){
      d1.shuffle();
    }
    //play the game if the user chooses 4 from the menu
    else if(choice == 4){
      cout << "\nPlaying Solitaire Prime!!!\n" << endl;
      //generate variable to keep track of prime piles
      int piles = 0;
      //while there are still cards left inside the deck....
      while(d1.cardsLeft() > 0){
        //the card at the top of the deck is drawn and displayed
        d1.deal().showCard();
        //if the pile is prime then the pile is counted to the total of piles, the user is notified
        //of the prime pile, and the total value of the cards drawn is reset to 0.
        if(d1.checkPrime(d1.getTotalValue()) == true){
          piles += 1; //count piles
          cout << " Prime: " << d1.getTotalValue() << endl; //notify user of prime pile
          d1.resetTotalValue(); //reset total value of cards drawn back to 0
        }
      }
      //once all cards are drawn, if the last pile is prime, the user wins and is notified
      if(d1.checkPrime(d1.getTotalValue()) == true){
        cout << "\nWinner in " << piles << " piles!" << endl;
      }
      //if the last pile is not prime, the user loses and is notifed
      else if(d1.checkPrime(d1.getTotalValue()) == false){
        cout << "\nLoser!!\n";
      }
    }
  }
  return 0;
}


