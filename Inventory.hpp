/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the Inventory class to hold the deathly hallows.   
 * */

#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Object.hpp"

using namespace std;

class Inventory
{
	private:
		vector<Object> hallows;
	public:
		Inventory();
		~Inventory();
		void addToInventory(Object& obj);
		int printInventory(); 


};
#endif




