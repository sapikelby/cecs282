/*
** Programmer: Kelby Sapien
** Course: CECS 282, CSULB
** Assignment: Lab 1
*/

#include <iostream>
#include <cstdlib> // for RAND_MAX	
#include <time.h> 
#include <string>;
using namespace std; 

// randomly selects winning door and returns door number
int SetSecretDoor()
{
	srand(time(0)); 
	int chosen = rand() % 3 + 1; 
	//int chosen = rand() % 10 + 5; 
	cout << chosen;

	return chosen; 
}

// randomly selects 1 of 5 prizes and returns prize as a string
string SetPrize()
{
	string prize[] = {"Iphone 5s", "Xbox One", "PS4", 
	 "Nexus 5", "Macbook Pro"}; 
	srand(time(0)); 
	int prizeNum = rand() % 5; 

	return prize[prizeNum]; 
}

int main(int argc, char* argv[]) {

	int winningDoor = SetSecretDoor(); 
	int doorChoice; 

	cout << "Welcome to Let's Make a Deal!\n\n";
	cout << "Please choose a door: " << endl; 
	
	cin >> doorChoice; 

	cout << "You chose door: " << doorChoice << endl; 
	
	int doorShown; 
	bool shown = false;
	// show door with goat to user 
	for (int i = 1; i<4; i++) {
		while (i != doorChoice && i != winningDoor && !shown) {
			// display door if user choice is different && != winningDoor
			cout << "Here is what we have in door: " << i << endl; 
			cout << "A goat is here as a prize!" << endl << endl;
			shown = true; 
			doorShown = i; 
		}
	}
	
	
	cout << "Would you like to switch doors?" << endl;
	char answer;
	cin >> answer; 

	// upadate userChoice with remaining door if answer is yes
	if (answer == 'y' || answer == 'Y') {
		for (int i = 1; i < 4; i++) {
			// assign new door to user
			if(doorShown != i && doorChoice != i) {
				doorChoice = i;
				break; 
			}
		}
		cout << "You now have door: " << doorChoice << endl;
	}

	// else confirm no change in choice
	else {
		cout << "Okay. You're sticking with door: " << doorChoice << endl;
	}
	
	cout << endl; 
	cout << "Final choice: " << doorChoice << endl << endl; 

	string grandPrize;
	// check if user won and display message accordingly
	if (doorChoice == winningDoor) {
		grandPrize = SetPrize(); 
		cout << "You win! You're prize is: " << grandPrize << endl; 
	}
	else {
		cout << "Sorry, Pal! Better luck next time." << endl; 
	}

	system("pause");
	return 0; 
}

