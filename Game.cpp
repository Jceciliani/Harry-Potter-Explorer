/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the game class that holds the board, turns and play functions.    
 * */

#include "Game.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

//Allocate game board
Game::Game()
{
	turns = 10;
	spaceArr = new Space*[9]; 
	spaceArr[0] = new KnockturnAlley();
	spaceArr[1] = new LeakyCauldron();
	spaceArr[2] = new Ollivanders();
	spaceArr[3] = new DiagonAlleyWest();
	spaceArr[4] = new DiagonAlley();
	spaceArr[5] = new DiagonAlleyEast();
	spaceArr[6] = new QuidditchSupply();
	spaceArr[7] = new WeasleyWizardWheezes();
	spaceArr[8] = new MagicalMenagerie(); 	 

	
		
	//Knockturn Alley
	spaceArr[0]->setDirections(NULL, spaceArr[1], spaceArr[3], NULL);
	//Leaky Cauldron
	spaceArr[1]->setDirections(NULL, spaceArr[2], spaceArr[4], spaceArr[0]);  

	//Ollivanders
	spaceArr[2]->setDirections(NULL, NULL, spaceArr[5], spaceArr[1]);	

	//Diagon Alley West
	spaceArr[3]->setDirections(spaceArr[0], spaceArr[4], spaceArr[6], NULL);

	//Diagon Alley
	spaceArr[4]->setDirections(spaceArr[1], spaceArr[5], spaceArr[7], spaceArr[3]);	

	//Diagon Alley East	
	spaceArr[5]->setDirections(spaceArr[2], NULL, spaceArr[8], spaceArr[4]);

	//Quidditch Supply	
	spaceArr[6]->setDirections(spaceArr[3], spaceArr[7], NULL, NULL);

	//Weasley's Wizard Wheezes 
 	spaceArr[7]->setDirections(spaceArr[4], spaceArr[8], NULL, spaceArr[6]);
	
	//Magical Menagerie
	spaceArr[8]->setDirections(spaceArr[5], NULL, NULL, spaceArr[7]); 
	//Location for player is Diagon Alley
	playerLoc = spaceArr[4];	
}

Game::~Game()
{
//Delete  array
//	delete [] spaceArr;		
	delete spaceArr[0];
	delete spaceArr[1];
	delete spaceArr[2];
	delete spaceArr[3];
	delete spaceArr[4];
	delete spaceArr[5];
	delete spaceArr[6];
	delete spaceArr[7];
	delete spaceArr[8];
	delete [] spaceArr;
//Delete player pointer



}

int Game::getTurns()
{
	return turns;
}

void Game::addTurns(int t)
{
	turns += t;	
}
//Character move
int Game::move(char loc)
{
	switch(loc)
	{
		case 'N': 
			if(playerLoc->getNorth() == NULL)
			{
				return -1;
			}	 
			else
			{
				playerLoc = playerLoc->getNorth(); 	
				return 0;
			}
		case 'E':
			if(playerLoc->getEast() == NULL)
			{
				return -1;

			}
			else
			{
				playerLoc = playerLoc->getEast();
				return 0;
			}
		case 'S':
			if(playerLoc->getSouth() == NULL)
			{
				return -1;

			}
			else
			{
				playerLoc = playerLoc->getSouth();
				return 0;
			}
		case 'W':
			if(playerLoc->getWest() == NULL)
			{
				return -1;

			}	
			else
			{
				playerLoc = playerLoc->getWest();
				return 0;	
			}	

		default:
			cout << "You broke it" << endl;
			return -1;  
	}


}


//Play the game
void Game::play()
{
	//Introduce game
	cout << "Welcome to the Harry Potter Text-Based Game!\n" << endl;
	//Objective of game
	cout << "You are Harry Potter, the boy who lived. You are a famous wizard with powerful potential" << endl;  		
	cout << "You start in Diagon Alley, and you can move around to go to the other stores!" << endl;
	cout << "Some stores may have a friend, while others could potentially have a foe... So be careful!" << endl;
	cout << "The three deathly hallows are hidden in the stores. Your goal is to find all three before Voldemort finds you." << endl;
	cout << "He will find you if you do not acquire all three Deathly Hallows before your turns run out." << endl;
	cout << "Best of luck finding the most powerful objects in the land, and remember, keep your friends close!\n" << endl;        	

	//Create Objects
	DiagonAlley d;
	DiagonAlleyEast e;	
	DiagonAlleyWest s;
	KnockturnAlley k;
	LeakyCauldron l;
	Ollivanders o;
	QuidditchSupply q;
	WeasleyWizardWheezes w;
	MagicalMenagerie m;
		

	//Bool statements outside of game
	//East Diagon Alley
	bool ifELand = false;
	//Knockturn Alley	
	bool ifKLand = false;
	//Magical Menagerie	
	bool ifMLand = false;
	//Weasley's Wizard Wheezes	
	bool ifWLand = false;
	 	
	char choice;	
	while(getTurns() > 0)
	{
		cout << endl;
		//Shows locations around you
		if(playerLoc->getNorth() == NULL)
		{
			cout << "There is nothing North" << endl; 	
		}	
		else
		{
			cout << "To the north is: " << playerLoc->getNorth()->getName() << endl;
		}
		if(playerLoc->getEast() == NULL)
		{
			cout << "There is nothing East" << endl;
		}
		else
		{
			cout << "To the east is: " << playerLoc->getEast()->getName() << endl;
		}
		if(playerLoc->getSouth() == NULL)
		{
			cout << "There is nothing South" << endl; 
		}
		else	
		{
			cout << "To the south is: " << playerLoc->getSouth()->getName() << endl;
		}
		if(playerLoc->getWest() == NULL)
		{
			cout << "There is nothing West" << endl;
		}	
		else
		{
			cout << "To the west is: " << playerLoc->getWest()->getName() << endl; 
		} 
		cout << endl;
		//move
		while(1)
		{
			cout << " To go North, press N |";
			cout << " To go East, press E |";
			cout << " To go South, press S |";
			cout << " To go West, press W" << endl;
			choice = getchar();	
			cin.clear();
			cin.ignore(255, '\n');
			if(choice == 'N' || choice == 'E' || choice == 'S' || choice == 'W')
			{
				int res = move(choice);
				if(res == -1)
				{
					cout << "It is forbidden to go there" << endl;
					
				}
				else
				{		
					break;
				}
			}	

			else
			{
				cout << "Invalid input - Please enter N, E, S or W." << endl;

			}		
		}
		//Display location and descripton
		if(playerLoc == spaceArr[0])
		{
			k.printSpace();
			//Bellatrix finds you
			if(ifKLand)
			{
			}
			else 
			{
				addTurns(-1);
				ifKLand = true;	
			}		
	
		}
		else if(playerLoc == spaceArr[1])
		{
			l.printSpace();
		}	
		else if(playerLoc == spaceArr[2])
		{
			o.printSpace();
		}
		else if(playerLoc == spaceArr[3])
		{
			s.printSpace();	
		}
		else if(playerLoc == spaceArr[4])
		{
			d.printSpace();
		}
		else if(playerLoc == spaceArr[5])
		{
			e.printSpace();
			//Malfoy finds you
			if(ifELand)
			{
			}
			else
			{
				addTurns(-2);
				ifELand = true;
			}
		}
		else if(playerLoc == spaceArr[6])
		{
			q.printSpace();
		}
		else if(playerLoc == spaceArr[7])
		{
			w.printSpace();
			//Ron finds you
			if(ifWLand)
			{
			}
			else
			{
				addTurns(1);
				ifWLand = true;
			}
		}
		else if(playerLoc == spaceArr[8])
		{
			m.printSpace();
			//Hermione Finds you
			if(ifMLand)
			{
			}	
			else 
			{
				addTurns(2);
				ifMLand = true;
			}
		}
		//check if win
		int win = o.getWinner() + q.getWinner() + l.getWinner();		
		if(win == 3)
		{
			cout << "You have collected all of the Deathly Hallows before Voldemort found you. It is up to you to keep these out of the wrong hands!" << endl;
			cout << " You win the game!" << endl;
			return;		
	

		}
		else
		{
			//descrease turns 
			addTurns(-1);	
			//check turns
			cout << "You have " << getTurns() << " turns left." << endl;	
			if(getTurns() <= 0)
			{
				cout << "Voldemort found you. Better luck next time." << endl;
			}	
		}
	}
}

