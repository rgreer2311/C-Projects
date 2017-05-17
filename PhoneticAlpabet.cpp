// Author: Roger Greer
// Assignment: Chapter 7, Problem 1
// Purpose: This application receives input string from the user and outputs the
// ICAO phonetic spelling of the word. The application terminates on receiving a
// Sentinel value.

#include <iostream>
#include <string>

using namespace std;

// Prototype functions
void Instruct(void);
void CAIO(char);

int main()
{
	// Variables
	string InWord, SubString;
	char InLetter;
	int StrLength, i;

	// Call to User Instructions
	Instruct();
	
	// Get the input word
	getline(cin, InWord);
	while (InWord != "-99") 
	{
		cout << "The phonetic spelling is: ";
		StrLength = InWord.length();
		i = 0;
		while (i <= StrLength - 1)
		{
			SubString = InWord.substr(i, 1);
			InLetter = SubString[0];
		    if (isalpha(InLetter)==0)
		    	cout << " ";
		    else
			CAIO(InLetter);
			i++;		
	    }
	    cout << endl;
	    getline(cin, InWord);
	   
    }
	return 0;
}

// User Instructions
void Instruct(void)
{
	cout << "*******************************************************" << endl;
	cout << "* Enter a word or phrase to get the International     *" << endl;
	cout << "* Civil Aviation Organization Alphabet phonetic       *" << endl;
	cout << "* spelling. Enter one word at a time.                 *" << endl;
	cout << "* Enter -99 to quit.                                  *" << endl;       
	cout << "*******************************************************" << endl;
	cout << endl;
}

// This function determines the phonetic string based on character input.
void CAIO(char Input)
{
 switch (Input)	
{
 case 'A': case 'a': cout << "Alpha "; 
 break;
 case 'B': case 'b': cout << "Bravo ";
 break;
 case 'C': case 'c': cout << "Charlie ";
 break;
 case 'D': case 'd': cout << "Delta ";
 break;
 case 'E': case 'e': cout << "Echo ";
 break;
 case 'F': case 'f': cout << "Foxtrot ";
 break;
 case 'G': case 'g': cout << "Golf ";
 break;
 case 'H': case 'h': cout << "Hotel ";
 break;
 case 'I': case 'i': cout << "India "; 
 break;
 case 'J': case 'j': cout << "Juliet ";
 break;
 case 'K': case 'k': cout << "Kilo ";
 break;
 case 'L': case 'l': cout << "Lima ";
 break;
 case 'M': case 'm': cout << "Mike ";
 break;
 case 'N': case 'n': cout << "November ";
 break;
 case 'O': case 'o': cout << "Oscar ";
 break;
 case 'P': case 'p': cout << "Papa ";
 break;
 case 'Q': case 'q': cout << "Quebec ";
 break;
 case 'R': case 'r': cout << "Romeo ";
 break;
 case 'S': case 's': cout << "Sierra ";
 break;
 case 'T': case 't': cout << "Tango ";
 break;
 case 'U': case 'u': cout << "Uniform ";
 break;
 case 'V': case 'v': cout << "Victor ";
 break;
 case 'W': case 'w': cout << "Whiskey ";
 break;
 case 'X': case 'x': cout << "X-Ray ";
 break;
 case 'Y': case 'y': cout << "Yankee ";
 break;
 case 'Z': case 'z': cout << "Zulu ";
 break;
 default : cout << "Invalid Input";
  } 	
}
