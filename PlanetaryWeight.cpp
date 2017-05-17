// Author: Roger Greer
// Purpose: This program calculates a users weight on a selected planet.

#include <iostream>
#include <string>

using namespace std;

enum Planets{MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN, URANUS, NEPTUNE, PLUTO};

const int Exit = -99; // Sentinel value

//Prototype Functions
void Instruct(); 
Planets planetSearch(string pSearch);
double calcWeight(Planets Name, double userWeight);

int main()
{
// Variables
double weight, pWeight;
string pName;

// User instructions
Instruct();

cout << "Enter your weight..." << endl;
cin >> weight;

while(weight != Exit)
{
	cout << "Enter a planet..." << endl;
	cin >> pName;
	
	// Calculate user weight on planet
	pWeight = calcWeight(planetSearch(pName), weight);
	
	cout << "Your weight on " << pName << " is " << pWeight << " lbs." << endl;
	cout << "Enter your weight..." << endl;
	cin >> weight;
}
return 0;
}

// User instructions
void Instruct()
{
cout << "******************************************************************************" << endl;
cout << "*This program calculates a users weight on the selected planet. Please select*" << endl; 
cout << "*from the following: MERCURY, VENUS, EARTH, MOON, MARS, JUPITER, SATURN,     *" << endl;
cout << "*URANUS, NEPTUNE, PLUTO.           Enter -99 for weight to Quit              *" << endl;
cout << "******************************************************************************" << endl;
}

Planets planetSearch(string pSearch)
//PRE:  The user has entered a planet name.
//POST: The user supplied planet name is validated, found in the enum, and returned to main function.
{
enum Planets name = MERCURY;
if(pSearch.length() < 4) // Shortest planet is MARS

	cout << "Your selection is invalid. Please check your spelling." << endl;
	
switch(toupper(pSearch.at(0)))	
{
case 'M':
switch(toupper(pSearch.at(1))) //Search at position one for M's
{
case 'E':
name = MERCURY;
break;
case 'A':
name = MARS;
break;
case 'O':
name = MOON;
break;
default:
	cout << "Your selection is invalid. Please check your spelling." << endl;
	break;
}
break;
case 'V':
name = VENUS;
break;
case 'E':
name = EARTH;
break;
case 'J':
name = JUPITER;
break;
case 'S':
name = SATURN;
case 'U':
name = URANUS;
break;
case 'N':
name = NEPTUNE;
break;
case 'P':
name = PLUTO;
default:
		cout << "Your selection is invalid. Please check your spelling." << endl;
		break;
}
return name;
}

// Calculates the users weight on the selected planet.
double calcWeight(Planets Name, double userWeight)
//PRE: The user has supplied a double value for weight and the planet name has  
//     been validated by the planetSearch function.
//POST: The users weight is calculated based on the planet selected and returned 
//      to the main function.
{
double planetWeight = 0;

switch(Name)
{
case MERCURY:
planetWeight = userWeight * 0.4155;
break;
case MARS:
planetWeight = userWeight * 0.3507;
break;
case MOON:
planetWeight = userWeight * 0.166;
break;
case VENUS:
planetWeight = userWeight * 0.8975;
break;
case EARTH:
planetWeight = userWeight * 1.0;
break;
case JUPITER:
planetWeight = userWeight * 2.5374;
break;
case SATURN:
planetWeight = userWeight * 1.0677;
break;
case URANUS:
planetWeight = userWeight * 0.8947;
break;
case NEPTUNE:
planetWeight = userWeight * 1.1794;
break;
case PLUTO:
planetWeight = userWeight * 0.0899;
break;
}
return planetWeight;
}





