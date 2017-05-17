// Author: Roger Greer
// Purpose: The purpose of this application is to compute a students grade for
// an assignment as a percentage given the students score and the total points 
// available. An assessment is provided for the grade result. 
// The score and points come from a file in the applications directory.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

// Prototype functions
void Instruct(void);
void studGrade(int score, int points);
void studName(string strName);

int main()
{
	string stdFile, stdName;
	int stdScore, totPoints, halt;
	ifstream inData;
	
	// Call to instructions
	Instruct();
	
	// Get the student file name
	cout << "Enter the student file name..." << endl;
	cin >> stdFile;
	inData.open(stdFile.c_str());
	if (!inData)
		{
		cout << "Cannot open the input file!" << endl;
		return (1);
        }
    else
	// Read student scores
	cout << endl;
	cout << "Scores" << endl;
	while (inData >> stdName >> stdScore >> totPoints)
	{
        // Pass name and scores to respective function
		studName(stdName);	
        studGrade(stdScore, totPoints);
    }
    inData.close(); 
    cin >> halt;
    return(0);
}

void Instruct(void)
{
	cout << "*******************************************************" << endl;
	cout << "* This program calculates a students assignment grade *" << endl;
	cout << "* from a file found in the programs directory.        *" << endl;
	cout << "*******************************************************" << endl;
}

void studName(string strName)
//Pre:  The students name has been entered from the input file
//Post: The students name is printed to the console
{
     cout << strName;
}

void studGrade(int score, int points)
//Pre:  The students exam score and total number of points has been entered from the input file
//Post: The final score is calculated and based on the score, appropriate result statement is assigned
//      Scores and results are printed to the console
{
	float perScore, finScore;
	string Result;
	
	perScore = (float(score) / float(points)) * 100.0;
	finScore = ceil(perScore);
	
	if (finScore >= 90)
		Result = "Excellent!";
	else if (finScore < 90 && finScore >= 80)
		Result = "Well Done.";
	else if (finScore < 80 && finScore >= 70)
		Result = "Good.";
	else if (finScore < 70 && finScore >= 60)
		Result = "You need Improvement.";
	else 
		Result = "You have failed!";

	cout << " " << fixed << int(finScore) << "% " << setw(6) << setprecision(5) << perScore  << " " << Result << endl;	
}
