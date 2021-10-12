#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// make sure to delcare score, itemsgrabbed, itemspulled, itemsinbag, playersname, computernum, playerstotal(items they pulled out)
	int itemBag = 23;
	int playerTotal = 0; //score for both player and computer v
	int computerTotal = 0;
	srand(time(NULL));  //for computer random picks to actually be random

	int computerNum;
	int playerNum;  //num is the number that they selected as the input
	string playerName;
	string computer;
	cout << "Welcome to the game of NIM, this is a game between the computer and the player where the players take turns removing objects from a heap." << endl;
	cout << "There are 23 objects in the heap and on each turn, a player removes either 1, 2, or 3 objects and whoever removes the last object loses." << endl;
	cout << "To start, may I please have your name ? " << endl;
	cin >> playerName;			//getting player name 
	// going to put everything in a while which only breaks if there are no more iteams in the bag

	do {
		srand(time(NULL)); //putting this in here so it is in the loop
		cout << playerName << ", please input 1, 2, or 3 for how many objects you want to remove" << endl;
		cin >> playerNum;
		while ((playerNum != 1) && (playerNum != 2) && (playerNum != 3)) //making the player input one of the 3 numbers, otherwise they are stuck in a loop
		{
			cout << "ERROR: That is not one of the numbers you can input, please choose either 1, 2, or 3." << endl;
			cin >> playerNum;
		} 
		
		itemBag = itemBag - playerNum; // subtracting the player number inputed from the bag
		playerTotal = playerNum + playerTotal;
		if (itemBag <= 0) {
			
			cout << "Computer has won!" << endl;
			break; 
		}
		// now its computers turn to random select numbers from 1-3
		computerNum = rand() % 3 + 1; // this is the input from the computer 
		cout << "Computer's input: " << computerNum << endl; //to see what they were putitng in for test
		itemBag = itemBag - computerNum;
		computerTotal = computerNum + computerTotal; // below im checking to see if the computer took out the last object
		if (itemBag <= 0) {
			
			cout << "Player has won!" << endl;
			break;
		}

	} while ( itemBag >= 0);
	 
	
	
	cout << "Computer's Total: " << computerTotal << endl;
	cout << "Player's Total:  " << playerTotal << endl;
	// this was to make sure logic was correct

	return 0;
}