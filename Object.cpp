/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the object class that has the 3 deathly hallows, friends and foes.   
 * */

#include "Object.hpp"
#include <iostream>
#include <string>

using namespace std;

//Object ***************************************8
Object::Object()
{
	name = "no name";
	description = "no description";
}

Object::~Object()
{}

string Object::getName()
{
	return name;
}


string Object::getDescription()
{
	return description;
}


void Object::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl; 
}


//Cloak of Invis***********************************************

CloakOfInvis::CloakOfInvis()
{
	name = "Cloak of Invisability";
	description = "This allows you to turn invisible if you put it on. It is very handy!";

}


CloakOfInvis::~CloakOfInvis()
{}


string CloakOfInvis::getName()
{
	return name;
}

string CloakOfInvis::getDescription()
{
	return description;
}


void CloakOfInvis::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl; 

} 


//Elder Wand*****************************************************

ElderWand::ElderWand()
{
	name = "Elder Wand";
	description = "This is the most powerful wand in the world. Use it wisely.";   

}

ElderWand::~ElderWand()
{}

string ElderWand::getName()
{
	return name;
}


string ElderWand::getDescription()
{
	return description;

}

void ElderWand::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl; 

}



//Resurrection Stone*********************************************

ResurrectionStone::ResurrectionStone()
{
	name = "Resurrection Stone";
	description = "This stone can bring back an echo from the dead."; 

}

ResurrectionStone::~ResurrectionStone()
{}


string ResurrectionStone::getName()
{
	return name;
}


string ResurrectionStone::getDescription()
{
	return description;
}

void ResurrectionStone::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl; 

}



//Ron**********************************************************

Ron::Ron()
{
	name = "Ron Weasley";
	description = "Harry's best friend!";
}

Ron::~Ron()
{}

string Ron::getName()
{
	return name;
}

string Ron::getDescription()
{
	return description;
}

void Ron::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;	
}


//Hermione*****************************************************

Hermione::Hermione()
{
	name = "Hermione Granger";
	description = "Absolutely Brilliant";
}

Hermione::~Hermione()
{}

string Hermione::getName()
{
	return name;
}

string Hermione::getDescription()
{
	return description;
}

void Hermione::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;	
}


//Malfoy***************************************************

Malfoy::Malfoy()
{
	name = "Draco Malfoy";
	description = "Made Harry's life miserable";

}

Malfoy::~Malfoy()
{}

string Malfoy::getName()
{
	return name;
}

string Malfoy::getDescription()
{
	return description;
}

void Malfoy::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;	
}



//Bellatrix************************************************

Bellatrix::Bellatrix()
{
	name = "Bellatrix LeStrange";
	description = "Powerful Death Eater";
}


Bellatrix::~Bellatrix()
{}

string Bellatrix::getName()
{
	return name;
}

string Bellatrix::getDescription()
{
	return description;
}

void Bellatrix::printObject()
{
	cout << "Name: " << name << endl;
	cout << "Description: " << description << endl;	
} 


