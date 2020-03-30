#include <iostream>
#include <string>
using namespace std;

// Just for aesthetics
string stars(){
  return "\n*******************************\n";
}
// Used to check if the user input is Yes/No
bool checkRes(string res){
  if(res.find("Y") != string::npos || res.find("y") != string::npos){
    return true;
  } else {
    return false;
  }
}
int main(){
  string cards[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
  string response, suit;
  // Check the color of the card. Total cards is cut down from 52 to 26
  cout << "Is your card black? (Yes/No)" << endl;
  cin >> response;
  if(checkRes(response)){
    // Check the suit of the card. Total cards is cut down from 26 to 13
    cout << "Is your card a clubs? (Yes/No)" << endl;
    cin >> response;
    if(checkRes(response)){
      suit = "Clubs";
      cout << response << endl;
    } else {
      suit = "Spades";
    }
  } else {
    cout << "Is your card hearts? (Yes/No)" << endl;
    cin >> response;
    if(checkRes(response)){
      suit = "Hearts";
    } else {
      suit = "Diamonds";
    }
  }
  // Initiate variables for binary search
  int high = 12, low = 0, guess;
  bool finished = false;
  cout << stars() << endl;
  cout << "Type Yes if your card is found!" << endl;   // Fail-safe incase the guess is the users card
  cout << stars() << endl;
  while(finished == false){
    guess = (low + high) / 2; // Cut the cards in half each loop. Making the search O(log n)
    if(guess - low == 0){ // If there is only one possible card left, break the loop. (Worst-case)
      finished = true;
      break;
    }
    cout << "Is your card higher or lower than " << cards[guess] << "? (H/L)" << endl;
    cin >> response;
    if(checkRes(response)){
      finished = true;
    } else if(response == "H" || response == "h"){
      low = guess + 1;
    } else if(response == "L" || response == "l"){
      high = guess;
    } else {
      cout << "\nNot a valid input!" << endl;
    }
  }
  cout << stars() << endl;
  cout << "Your card is the " << cards[guess] << " of " << suit << endl;
  cout << stars() << endl;
}
