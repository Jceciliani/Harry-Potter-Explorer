/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the space class that holds the space and derived spaces for the Harry Potter text-based game.    
 * */

#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include <vector>

#include "Inventory.hpp"

using namespace std;

class Space
{
	protected:
		Space *north;
		Space *east;
		Space *south;
		Space *west;
		string name;
		string description;
		char id;
		int winner;
		Object *obj;
	public:
		Space();
		~Space();
		virtual string getName();
		virtual string getDescription();
		//Print the information about each location	
		virtual void printSpace() = 0;
		virtual char getId();
		//See if user wins
		int getWinner();
		void setWinner(int w);
		//Board Directions	
		Space* getNorth();
		Space* getEast();
		Space* getSouth();
		Space* getWest();
		void setDirections(Space* N, Space* E, Space* S, Space* W);	 

};
#endif

//DiagonAlley*********************************************
class DiagonAlley : public Space
{
	public:
		DiagonAlley();
		~DiagonAlley();	
		string getName();
		string getDescription();
		void printSpace();
		char getId();
			
};


//KnoockturnAlley******************************************
class KnockturnAlley : public Space
{
	public:
		KnockturnAlley();
		~KnockturnAlley(); 
		string getName();
		string getDescription();
		void printSpace();
		char getId();

}; 


//Diagon Alley East************************************************
class DiagonAlleyEast : public Space
{
	public:
		DiagonAlleyEast();
		~DiagonAlleyEast(); 
		string getName();
		string getDescription();
		void printSpace();
		char getId();
			
};


//Diagon Alley West************************************************
class DiagonAlleyWest : public Space
{
	public:
		DiagonAlleyWest();
		~DiagonAlleyWest(); 
		string getName();
		string getDescription();
		void printSpace();
		char getId();

};

//LeakyCauldron******************************************
class LeakyCauldron : public Space
{
	public:
		LeakyCauldron();
		~LeakyCauldron();
		string getName();
		string getDescription();
		void printSpace();
		char getId();
			
};

//Ollivanders******************************************
class Ollivanders : public Space
{
	public:
		Ollivanders();
		~Ollivanders();	
		string getName();
		string getDescription();
		void printSpace();
		char getId();
			
};


//Weasley's Wizard Wheezes***************************
class WeasleyWizardWheezes : public Space
{
	public:
		WeasleyWizardWheezes();
		~WeasleyWizardWheezes();
		string getName();
		string getDescription();
		void printSpace();
		char getId();

};


//Quality Quidditch Supply**************************
class QuidditchSupply : public Space
{
	public:
		QuidditchSupply();
		~QuidditchSupply();
		string getName();
		string getDescription();
		void printSpace();
		char getId();
			
};


//Magical Menagerie*********************************
class MagicalMenagerie : public Space
{
	public:
		MagicalMenagerie();
		~MagicalMenagerie();
		string getName();
		string getDescription();
		void printSpace();
		char getId();
			
};





