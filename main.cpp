/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the main class that runs the menu for the Harry Potter text based game.     
 * */

#include "Game.hpp"
#include <iostream>
#include <string>

int main()
{
		
	string choice;
	bool ifError = false;	
	while(1)
	{	
		cout << "1. Play the text-based Harry Potter game" << endl;
		cout << "2. Exit" << endl;
		getline(cin, choice);
	
		//Start the game  
		if(choice == "1")
		{
 			Game *game = new Game();
			game->play();
			delete game;
					 
		}
		//Exits program
		else if(choice == "2")
		{
			return 0;
		} 
		//Input validation
		else 
		{
			cout << "Invalid - Please enter 1 - 2" << endl;
			ifError = true;
		}
		if(ifError)
		{
			ifError = false;
		} 
		
	}
	return 0;	
}	
