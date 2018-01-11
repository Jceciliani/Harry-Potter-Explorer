/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the game class.    
 * */

#ifndef GAME_HPP
#define GAME_HPP

#include "Space.hpp"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Game
{
	private:
		int turns;
		Space **spaceArr;
		Space *playerLoc;
		Inventory *playerInv;
	public:
		Game();
		~Game();
		void play();
		int getTurns();
		void addTurns(int t);  	
		int move(char loc);
};
#endif
 


