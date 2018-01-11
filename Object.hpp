/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the object class that has the 3 deathly hallows, friends and foes.   
 * */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <string>

using namespace std;

class Object
{
	protected:
		string name;
		string description;
	public:
		Object();
		~Object();
		string getName();
		string getDescription();
		virtual void printObject();	

};
#endif

//Cloak of Invisability******************
class CloakOfInvis : public Object
{
	public:
		CloakOfInvis();
		~CloakOfInvis();
		string getName();
		string getDescription();
		void printObject();	

};


//Elder Wand***************************
class ElderWand : public Object
{
	public:
		ElderWand();
		~ElderWand();
		string getName();
		string getDescription();
		void printObject();	

};


//Resurrection Stone******************
class ResurrectionStone : public Object
{
	public:
		ResurrectionStone();
		~ResurrectionStone();
		string getName();
		string getDescription();
		void printObject();	
};

//Ron***********************************
class Ron : public Object
{
	public:
		Ron();
		~Ron();
		string getName();
		string getDescription();
		void printObject(); 
	
};

//Hermione*************************************
class Hermione : public Object
{
	public:
		Hermione();
		~Hermione();
		string getName();
		string getDescription();
		void printObject();

};


//Malfoy****************************************
class Malfoy : public Object
{
	public:
		Malfoy();
		~Malfoy();
		string getName();
		string getDescription();
		void printObject(); 

};


//Bellatrix*************************************** 
class Bellatrix : public Object
{
	public:
		Bellatrix();
		~Bellatrix();
		string getName();
		string getDescription();
		void printObject();
		
};
