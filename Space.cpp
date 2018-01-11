/*Program Name: Final Project 
 * Author: Josh Ceciliani
 * Date: November 30, 2017 
 * Description: This is the space class that holds the space and derived spaces for the Harry Potter text-based game.    
 * */

#include "Space.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

//Inventory object
Inventory inv;

//Space*****************************************
Space::Space()
{
	name = "No Name";
	description = "No Description";	 
	id = 'Z';
	obj = NULL;
	winner = 0;		
}

Space::~Space()
{}	

string Space::getName()
{
	return name;
}


string Space::getDescription()
{
	return description;
}

int Space::getWinner()
{
	return winner;
}	

void Space::setWinner(int w)
{
	winner = w;
}
char Space::getId()
{
	return id;
}

Space* Space::getNorth()
{
	return north;
}

Space* Space::getEast()
{
	return east;
} 

Space* Space::getSouth()
{
	return south;
}

Space* Space::getWest()
{
	return west;
}

void Space::setDirections(Space* N, Space* E, Space* S, Space* W)
{
	north = N;
	east = E;
	south = S;
	west = W;

}


//Diagon Alley************************************

DiagonAlley::DiagonAlley()
{
	name = "Diagon Alley";
	description = "A cobblestoned wizarding alley and shopping area. You can find anything a young witch or wizard would need here!"; 
	id = 'D';
	obj = NULL;
}

DiagonAlley::~DiagonAlley()
{}

string DiagonAlley::getName()
{
	return name;
}

string DiagonAlley::getDescription()
{
	return description;
}


void DiagonAlley::printSpace()
{
	cout << "CURRENT LOCATION: " << getName() << endl;
	cout <<	"DESCRIPTION: " << getDescription() << endl;

}

char DiagonAlley::getId()
{
	return id;
}


//Knockturn Alley*****************************************

KnockturnAlley::KnockturnAlley()
{
	name = "Knockturn Alley";
	description = "This alley is full of shops dedicated to the dark arts. There are some dangerous and scary people around, be careful!";
	id = 'K';
	obj = new Bellatrix();	
}

KnockturnAlley::~KnockturnAlley()
{
	if(obj != NULL)
	{
		delete obj;
	}
} 

string KnockturnAlley::getName()
{
	return name;
}


string KnockturnAlley::getDescription()
{
	return description;
}


void KnockturnAlley::printSpace()
{
	
	cout << "CURRENT LOCATION: " << getName() << endl;
	cout <<	"DESCRIPTION: " << getDescription() << endl;
	if(obj == NULL)
	{
		cout << "'I would hurry along now.. He's coming...'" << endl;
	}
	else
	{
		cout << "Of course.. It's Bellatrix.." << endl;
		cout << "'Looks like you're wandering around the wrong parts here, Potter..'" << endl;
		cout << "'I would start running now before the dark lord finds you..'" << endl;
		cout << "DEDUCTED: -1 turn" << endl; 		
		obj = NULL;
	}
}


char KnockturnAlley::getId()
{
	return id;
} 


//The Leaky Cauldron************************************


LeakyCauldron::LeakyCauldron()
{
	name = "Leaky Cauldron";
	description = "This is a popular wizarding pub and inn! Please come in and enjoy yourself!";
	id = 'L';
	obj = new ResurrectionStone();	
		
}

LeakyCauldron::~LeakyCauldron()
{
	if(obj != NULL)
	{
		delete obj;
	}
}

string LeakyCauldron::getName()
{
	return name;
}

string LeakyCauldron::getDescription()
{
	return description;
} 

void LeakyCauldron::printSpace()
{	
	char choice;
	
		cout << "CURRENT LOCATION: " << getName() << endl;
		cout <<	"DESCRIPTION: " << getDescription() << endl;
		if(obj == NULL)
		{
			cout << "You have already acquired the Resurrection Stone!" << endl; 
		}
		else
		{
			cout << "You see something shiny in the corner, do you want do pick it up? Y - Yes | N - No" << endl;
			choice = getchar();
			cin.clear();
			cin.ignore(255, '\n');
			if(choice == 'Y')
			{
				cout << "You found the Resurrection Stone!" << endl;
				inv.addToInventory(*obj);
				cout << "You have these items in your inventory: " << endl;
				inv.printInventory();
				obj = NULL;
				if(getWinner() == 0)
				{
					setWinner(1);
				}
				else if(getWinner() == 1)
				{
					setWinner(2);
				}	
				else if(getWinner() == 2)
				{
					setWinner(3);
				}
			}	
			else if(choice == 'N')
			{
				cout << "You decide to leave it be." << endl; 
			}
			else
			{
				cout << "Invalid Input - Please Enter Y or N" << endl;	
			}
		}


}


char LeakyCauldron::getId()
{
	return id;
}


//Diagon Alley East********************************

DiagonAlleyEast::DiagonAlleyEast()
{
	name = "Diagon Alley East";
	description = "This is the East end of the cobblestoned wizarding alley and shopping area. You can find anything a young witch or wizard would need here!"; 
	id = 'E';
	obj = new Malfoy();
}

DiagonAlleyEast::~DiagonAlleyEast()
{
	if(obj != NULL)
	{
		delete obj;
	}
}


string DiagonAlleyEast::getName()
{
	return name;
}

string DiagonAlleyEast::getDescription()
{
	return description;
}

void DiagonAlleyEast::printSpace()
{
	
	cout << "CURRENT LOCATION: " << getName() << endl;
	cout <<	"DESCRIPTION: " << getDescription() << endl;
	if(obj == NULL)
	{
		cout << "'I would hurry up, Potter. The dark lord is coming...'" << endl;
	}	
	else
	{
		cout << "Oh no, it's Malfoy." << endl; 
		cout << "'Look who it is.. Harry Potter. Don't mind me alerting the dark lord of your movements..'" << endl;
		cout << "DEDUCTED: -2 turns" << endl; 	
		obj = NULL;
	}		
}

char DiagonAlleyEast::getId()
{
	return id;
}



//Diagon Alley West**************************************

DiagonAlleyWest::DiagonAlleyWest()
{
	name = "Diagon Alley West";
	description = "This is the West end of the cobblestoned wizarding alley and shopping area. You can find anything a young witch or wizard would need here!"; 
	id = 'S';
	obj = NULL;
}

DiagonAlleyWest::~DiagonAlleyWest()
{}


string DiagonAlleyWest::getName()
{
	return name;
}

string DiagonAlleyWest::getDescription()
{
	return description;
}

void DiagonAlleyWest::printSpace()
{
	cout << "CURRENT LOCATION: " << getName() << endl;
	cout <<	"DESCRIPTION: " << getDescription() << endl;
	
}

char DiagonAlleyWest::getId()
{
	return id;
}


//Ollivanders***************************************

Ollivanders::Ollivanders()
{
	name = "Ollivanders Wand Shop";
	description = "This is the famous Ollivanders Wand Shop, founded in 382 B.C.. Look around for an amazing wand!";
	id = 'O';
	obj = new ElderWand();   


}

Ollivanders::~Ollivanders()
{
	if(obj != NULL)
	{
		delete obj;
	}	

}

string Ollivanders::getName()
{
	return name;
} 

string Ollivanders::getDescription()
{
	return description;
}

void Ollivanders::printSpace()
{
	char choice;	
	
		cout << "CURRENT LOCATION: " << getName() << endl;
		cout <<	"DESCRIPTION: " << getDescription() << endl;
		if(obj == NULL)
		{
			cout << "You have already aquired the Elder Wand!" << endl;
		}
		else 
		{
			cout << "Ollivander asks if you want to see a special item. Do you want to see it? Y - Yes | N - No" << endl;
			choice = getchar();
			cin.clear();
			cin.ignore(255, '\n');
			if(choice == 'Y')
			{
				cout << "He gave you the Elder Wand!" << endl;
				inv.addToInventory(*obj);
				cout << "You have these items in your inventory: " << endl;
				inv.printInventory();
				obj = NULL;
				if(getWinner() == 0)
				{
					setWinner(1);
				}
				else if(getWinner() == 1)
				{
					setWinner(2);
				}	
				else if(getWinner() == 2)
				{
					setWinner(3);
				}
			}	
			else if(choice == 'N')
			{
				cout << "You decide to leave it be." << endl; 
			}
			else
			{
				cout << "Invalid Input - Please Enter Y or N" << endl;	
			}
		}

}

char Ollivanders::getId()
{
	return id;
}


//Weasley Wizard Wheezes****************************

WeasleyWizardWheezes::WeasleyWizardWheezes()
{
	name = "Weasley's Wizard Wheezes";
	description = "This is the Weasley's joke shop. This is a great place to find some tricks to annoy your teachers!";
	id = 'W';
	obj = new Ron();     

}

WeasleyWizardWheezes::~WeasleyWizardWheezes()
{
	if(obj != NULL)
	{
		delete obj;
	}	
}

string WeasleyWizardWheezes::getName()
{
	return name;
}

string WeasleyWizardWheezes::getDescription()
{
	return description;
}


void WeasleyWizardWheezes::printSpace()
{
	cout << "CURRENT LOCATION: " << getName() << endl;
	cout <<	"DESCRIPTION: " << getDescription() << endl;
	if(obj == NULL)
	{
		cout << "Ron is already doing his best!" << endl;	
	}	
	else
	{	
		cout << "You run into Ron. Bloody Hell! Even with his broken wand, he plans to protect you from Voldemort as long as possible!" << endl;
		cout << "ACQUIRED: +1 turn" << endl;
		obj = NULL;			
	}

}

char WeasleyWizardWheezes::getId()
{
	return id;

}



//Quidditch Supply***********************************

QuidditchSupply::QuidditchSupply()
{
	name = "Quality Quiddich Supply";
	description = "This store has the Quidditch starter kit, including Quaffles, Bludgers and broomsticks. Look around for any special items!";
	id = 'Q';
	obj = new CloakOfInvis();	 

}


QuidditchSupply::~QuidditchSupply()
{
	if(obj != NULL)
	{
		delete obj;
	}


}


string QuidditchSupply::getName()
{
	return name;
} 

string QuidditchSupply::getDescription()
{
	return description;
} 

void QuidditchSupply::printSpace()
{
	char choice;
	
		cout << "CURRENT LOCATION: " << getName() << endl;
		cout <<	"DESCRIPTION: " << getDescription() << endl;
		if(obj == NULL)
		{
			cout << "You have already collected the Cloak of Invisibility!" << endl;
		}
		else
		{
			cout << "You bump into a mysterious item that seems, invisible. Do you want to investigate? Y - Yes | N - No" << endl;
			choice = getchar();
			cin.clear();
			cin.ignore(255, '\n');
			if(choice == 'Y')
			{
				cout << "You found the Cloak of Invisibility!" << endl;
				inv.addToInventory(*obj);
				cout << "You have these items in your inventory: " << endl;
				inv.printInventory();
				obj = NULL;
				if(getWinner() == 0)
				{
					setWinner(1);
				}
				else if(getWinner() == 1)
				{
					setWinner(2);
				}	
				else if(getWinner() == 2)
				{
					setWinner(3);
				}
			}	
			else if(choice == 'N')
			{
				cout << "You decide to leave it be." << endl; 
			}
			else
			{
				cout << "Invalid Input - Please Enter Y or N" << endl;	
			}
		}


}



char QuidditchSupply::getId()
{
	return id;
}


//Magical Menagerie***********************************

MagicalMenagerie::MagicalMenagerie()
{
	name = "Magical Menagerie";
	description = "This store is full of magical creatures. It is quite smelly, but I would stay and take a look around!";
	id = 'M';
	obj = new Hermione();    


}

MagicalMenagerie::~MagicalMenagerie()
{
	if(obj != NULL)
	{
		delete obj;
	}

}

string MagicalMenagerie::getName()
{
	return name;
}

string MagicalMenagerie::getDescription()
{
	return description;
}

void MagicalMenagerie::printSpace()
{ 
	cout << "CURRENT LOCATION: " << getName() << endl;
	cout <<	"DESCRIPTION: " << getDescription() << endl;
	if(obj == NULL)
	{	
		cout << "What are you doing here Harry?! Go find the Deathly Hallows!" << endl;
	}
	else
	{
		cout << "You run into Hermione! She's in here looking for treats for her cat, Crookshanks. She knows Voldemort is after you and will protect you as long as she can!" << endl;
		cout << "ACQUIRED: +2 turns" << endl;		
		obj = NULL;		
	}		

}

char MagicalMenagerie::getId()
{
	return id;
} 



