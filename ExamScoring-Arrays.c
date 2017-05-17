/******************************************************************************
*  Roger Greer
*  Chapter07
*  This program recieves student number, exam score, and exam key input from 
*  the user. Based on the exam key it calculates the students score and
*  the number of times the exam question was missed. The program provides 
*  an output file in the programs directory. 
******************************************************************************/

#include <stdio.h>
#define SENTINEL -99

/* Declare prototype functions */
void instruct(void);
void getAnswers(int numQues);

int main(void)
{
	int num;
	Filef
	/* Call to instruct */
	instruct();
	
	/* Define size of array */
	printf("Enter the number of test questions => ");
	scanf("%d", &num);
	num = num + 1; /* Add one to compensate for char array */
	
	/* Call to getAnswers */
	getAnswers(num);
	
	getch();
	return(0);
}

/* This function provides user instructions */
void instruct(void)
{
	printf("\nThis program recieves student numbers, exam scores, and exam\n");  
	printf("key input from the user. Based on the exam key it calculates\n"); 
	printf("thes students score and the number of times the exam question\n");  
	printf("was missed. The program provides an output file in the programs\n");
	printf("directory.\n\n");
}

/* This function calculates exam scores and number of times exam question was
*  missed */
void getAnswers(int numQues)
{
	/* Declare function variables */
	FILE *scoresOut;
	int i, stdID, numElements = numQues, stdScore, count;
	char examKey[numElements];
	char studAns[numElements];
	int scoreTally[numElements];
		
	/* Calculate test score for students */
		/* Get key values */
		printf("Enter the exam answers => ");
		for (i = 0; i < numElements; ++i)
			scanf("%c", &examKey[i]);
					
		/* Loop to initialize scoreTally[] to zero */
		for (i = 0; i < numElements; ++i)
			scoreTally[i] = 0;
		
		/* Format initial output */
		scoresOut = fopen("examreport.txt", "w");
		fprintf(scoresOut,"                  Exam Report\n");
		fprintf(scoresOut, "\nQuestion:  ");
		for (i = 1; i < numElements; ++i) 
			fprintf(scoresOut, "%2d", i);
		fprintf(scoresOut, "\nAnswers:   ");
		for (i = 1; i < numElements; ++i) 
			fprintf(scoresOut, "%2c", examKey[i]);
		fprintf(scoresOut, " \n\nID     Score (%%)\n");
					
		/* Compare array elements to exam key */
		printf("\nEnter the student ID (press -99 to quit) => ");
		scanf("%d", &stdID);
		while (stdID != SENTINEL)
			{
			/* Initialize student score to 100 */
			stdScore = 100; 
			/* Scan and enter scores into array */
			printf("Enter the students exam scores => ");
			for (i = 0; i < numElements; ++i)
				{
				scanf("%c", &studAns[i]);
				}
			for (i = 0; i < numElements; ++i)
				{
					if (studAns[i] != examKey[i])
					{
					scoreTally[i] = scoreTally[i]+1;
					stdScore = stdScore - 20;
					}
				}
			fprintf(scoresOut, "%d %9d\n", stdID, stdScore);       
			
			/* Reset stdAns[] to null */		
			for (i = 0; i < numElements; ++i)
				studAns[i] = ' ';    
				
			/* SENTINEL value not entered */
			printf("\nEnter the student ID => ");
		    scanf("%d", &stdID);
			}
	     		     
	/* Write final output file*/
	fprintf(scoresOut, "\nQuestion: ");
	for (i = 1; i < numElements; ++i) 
			fprintf(scoresOut,"%2d", i);
	fprintf(scoresOut, "\nMissed:   ");
	for (i = 1; i < numElements; ++i) 
			fprintf(scoresOut, "%2d", scoreTally[i]);
	
	/* Housekeeping */
	fclose(scoresOut);
}


/* Exam Key
5 dbbac
111 dabac
102 dcbdc
251 dbbac
*/











