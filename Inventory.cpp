/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the Inventory class to hold the deathly hallows.   
 * */

#include "Inventory.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
//Delete Memory in vector	
	//for(int i = 0; i < hallows.size(); i++)
	//{
	//	delete hallows[i];
	//}		
	hallows.clear();

}
//Add Objects to Vector
void Inventory::addToInventory(Object &obj)
{
	hallows.push_back(obj);	
} 

//Print inventory to screen
int Inventory::printInventory()
{
		for(int i = 0; i < hallows.size(); i++)
		{
			cout << hallows[i].getName() << endl;
		}

} 

