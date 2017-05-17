// Author: Roger Greer
// Purpose: This program is a game called battleship. The user enters the board name and 
// then enters coordinates to sink the enemy fleet.

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

//Prototype Functions
void Instruct(void);
void SelectBoard(ifstream& infile);
int Fire(int CoordOne, int cordTwo);
bool FleetSunk(bool& Exists);

//Constants
const int NUM_ROWS = 25;
const int NUM_COL = 25;
const int SENTINEL = -99;

//Define array
char Board[NUM_ROWS][NUM_COL];

int main()
{
	ifstream infile;
    string name, halt, boardName;
    int coordOne, coordTwo;
    bool gameOver = false;
    
    //Instructions
    Instruct();

    //Open game board file
     cout << "Enter the boardname.txt > "  ; 
     getline ( cin, boardName );  
     infile.open ( boardName.c_str() );
     while(!infile)
     {
    	cout << "File does not exist. Try again." << endl;
    	cout << "Enter the boardname.txt > "  ; 
    	getline ( cin, boardName );
        infile.open ( boardName.c_str() );
     }
   	//Load board from text file	
    SelectBoard(infile);
    
	    cout << "Enter a coordinate to fire on..." << endl;
	    cin >>  coordOne >> coordTwo;
	    while(coordOne != SENTINEL || coordTwo != SENTINEL) // Not catching SENTINEL
	    {	 
	    	while (!cin) //Ensure correct input type
	    	{
	    	   cout << "Please enter a numeric pair of coordinates..." << endl;
	    	   cin.clear();
	    	   cin.ignore(256,'\n');
	    	   cin >>  coordOne >> coordTwo;
	        }
		   //Pass coordinates to Fire()	
		   Fire(coordOne, coordTwo);
		   //Test game over condition
		   FleetSunk(gameOver);
		   if (gameOver == false)
		   {
		       cout << "Enter a coordinate to fire on..." << endl;
			   cin >>  coordOne >> coordTwo;
		   }
		   else if (gameOver == true)
		   {
		   	cout << endl;
		   	cout << "The Fleet is Destroyed!" << endl;
			cout << "      Game Over!" << endl;
			return 1;
		   }
	    }

    return 0; 
}

//User Instructions
void Instruct(void)
{
	cout << "*******************************************************" << endl;
	cout << "*                     BATTLE SHIP!!                   *" << endl;
	cout << "*  Welcome to Battle Ship. When prompted, load your   *" << endl;
	cout << "*  game board from file. Enter coordinates to fire as *" << endl;
	cout << "*   0-25 horizontal and 0-25 vertical. HIT! or MISS!  *" << endl;
	cout << "*    indicates your success. When all ships have been *" << endl;
	cout << "*               sunk the FLEET IS DESTROYED           *" << endl;
	cout << "*                 Enter -99 -99 to Quit               *" << endl;
	cout << "*******************************************************" << endl;
}

void SelectBoard(ifstream& infile)
//PRE:  A board text file is in the programs directory.
//POST: The board charachters are loaded into the array.
{
 		//Load 2D Array
		 for ( unsigned i = 0; i < 25; i++ ) 
   			  for ( unsigned j = 0; j < 25; j++ ) 
   			  infile >> Board[i][j]; 
       	cout << "       BEGIN GAME!     " << endl;  
       	cout << endl;
        infile.close();   
}

int Fire(int coordOne, int coordTwo)
//PRE:  Two input int coordinate values have been validated and passed from main().
//POST: The array index char value is compared and the appropriate response is issued and/or replaced. 
{
     if (Board[coordOne][coordTwo] == '~')
     	cout << "MISS!" << endl;
     else if (Board[coordOne][coordTwo] == 'X')
     	{
     	Board[coordOne][coordTwo] = 'H';
     	cout << "HIT!" << endl;
        }
     else if (Board[coordOne][coordTwo] == 'H')
     	cout << "HIT AGAIN!" << endl;   
}
     
bool FleetSunk(bool& Exists)
//PRE:  Changes to the array have been made if applicable.
//POST: The array is searched for additional X char values, if none are found true is returned to main()
//indicating game over.
{	
	int count;
	
	for (int i = 0; i < NUM_ROWS; ++i )
	{
  		for (int j = 0; j < NUM_COL; ++j)
  		if (Board[i][j] == 'X')
  		count++;		 
	}     
	if (count <= 0)
		return Exists = true;
	else if (cout > 0)
		return Exists = false;
}

/* Board Text File
~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~XXXX~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~X~~~~~~
~~~~~~~~~~~~~~~~~~X~~~~~~
~~~~~~~~~~~~~~~~~~X~~~~~~
~~~X~~~~~~~~~~~~~~X~~~~~~
~~~X~~~~~~~~~~~~~~X~~~~~~
~~~X~~~~~~~~~~~~~~X~~~~~~
~~~X~~~~~~~~~~~~~~~~~~~~~
~~~X~~~~~~~~~~~~~~~~~~~~~
~~~X~~~~~~~~~~~~~~~~~~~~~
~~~X~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~
~~~XXXXXXXXXX~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~X~~~
~~~~~~~~~~~~~~~~~~~~~X~~~
~~~~~~~~~~~~~~~~~~~~~X~~~
~~~~~~~~~~~~~~~~~~~~~X~~~
~~~~~~~~~~~~~~~~~~~~~X~~~
~~~~~~~~~~~~~~~~~~~~~X~~~
~~~~~~~~~~~~~~~~~~~~~~~~~
 */





