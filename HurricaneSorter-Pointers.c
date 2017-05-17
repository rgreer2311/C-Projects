/******************************************************************************
* Roger Greer
* Chapter 08
* PURPOSE: This program loads data from an inputfile and sorts it by name or  
* year based on user selection. The program produces a sorted output file in  
* the programs directory.
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30
int numOfData = 0;

/* Declare prototype functions */
void instruct(void);
void dataIn(int year[], char *name[], char *state[]);
void sortYear(int year[], char *name[], char *state[]);
void sortName(int year[], char *name[], char *state[]);
	
int main(void)
{
	int year[MAX], i;
    char *name[MAX];
    char *state[MAX];
   	char selection;
	FILE *op;
	
	/* Call to instruct */		
	instruct(); 
	
	dataIn(year, name, state);
	
	op = fopen("hurricanesort.txt","w");
	
	/* User sort selection */	
	fflush(stdin);
	printf("Please enter the sort method: N(Name), Y(Year), or Q(Quit) => ");
	selection = getchar();
	
	
	if (selection == 'Q' || selection == 'q')
		exit(0);
	else if (selection == 'N' || selection =='n')
	{
		printf("\nStarting Sort\n");
		sortName(year, name, state);
 		fprintf(op, "\nU.S. Hurricane by Name\n\n");
   		fprintf(op, "\nYEAR          NAME          STATES\n");
   		fprintf(op, "\n----          ----          ------\n\n");
		for(i=0;i<numOfData;i++)
       		fprintf(op, "%-10d%-10s%-10s\n",year[i],name[i],state[i]);
       	printf("\nSort Complete!\n");
	}
	else if (selection == 'Y' || selection =='y')
	{
		printf("\nStarting Sort\n");
		sortYear(year, name, state);
   		fprintf(op, "\nU.S. Hurricane by Year of Occurrence\n\n");
   		fprintf(op, "\nYEAR          NAME          STATES\n");
   		fprintf(op, "\n----          ----          ------\n\n");
		for(i=0;i<numOfData;i++)
       		fprintf(op, "%-10d%-10s%-10s\n",year[i],name[i],state[i]);
       	printf("\nSort Complete!\n");
	}
	
	fclose(op);
	getch();
	return(0);
	
}

/* This function provides user instructions */
void instruct(void)
{
	printf("\nThis program loads hurricane data from a text file and sorts\n");  
	printf("it by the hurricane name or hurricane year based on the users\n"); 
	printf("sort selection. The program provides the sorted output file in\n");  
	printf("the programs directory\n\n");
}

 /* This function reads the input file into parallel arrays */
void dataIn(int year[], char *name[], char *state[])
{
	char fileName[20];
	char hurricaneName[50];
    char stateEffected[50];
    char line[100];
    int i, index=0;
    FILE *ip;

    /* Open file */
    printf("Enter the name of the data file => ");
    scanf("%s", fileName);
    ip = fopen(fileName,"r");
   
    /* Check that file is valid */
    if(!ip)
    {
       printf("File not found");
       getch();
       exit(0);
    }
    
    while(fgets(line, 200, ip))
   	{  			
        sscanf(line,"%d %s %[^\n]",&year[index], &hurricaneName, &stateEffected);
        name[index] = (char*) malloc(sizeof(char) * (1 + strlen(hurricaneName)));
       
        strcpy(name[index],hurricaneName);
       
        state[index] = (char*) malloc(sizeof(char) * (1 + strlen(stateEffected)));
        strcpy(state[index],stateEffected);
       
        ++index;
  	}
	
	numOfData = index;
  		
   fclose(ip);
}

/* This function sorts the array by name */
void sortName(int year[], char *name[], char *state[])
{
   int i, j, temp;
   char *tempName, *tempState;

   for(i = 0; i < numOfData - 1; i++)
   {
       for(j = i + 1;j < numOfData;j++)
       {

           if(strcmp(name[i], name[j]) > 0)
           {
               int temp = year[i];
               year[i] = year[j];
               year[j] = temp;

               char tempName[100];
               strcpy(tempName, name[i]);
               strcpy(name[i], name[j]);
               strcpy(name[j],tempName);

 			   strcpy(tempName, state[i]);
               strcpy(state[i], state[j]);
               strcpy(state[j], tempName);
           }
	   }
   }
}

/* This function sorts the array by year */
void sortYear(int year[], char *name[], char *state[])
{
   int i, j, temp;
   char *tempName, *tempState;

   for(i = 0; i < numOfData - 1;i++)
   {
       for(j = i + 1; j < numOfData;j++)
       {

           if(year[i] > year[j])
           {
			   int temp = year[i];
               year[i] = year[j];
               year[j] = temp;

               char tempName[100];
               strcpy(tempName, name[i]);
               strcpy(name[i], name[j]);
               strcpy(name[j],tempName);

 			   strcpy(tempName, state[i]);
               strcpy(state[i], state[j]);
               strcpy(state[j], tempName);
           }

       }
   }

}

/* Project Data
1960 Donna FL, NC
1969 Camille MS
1972 Agnes FL
1983 Alicia TX
1989 Hugo SC, NC
1992 Andrew FL, LA
1995 Opal FL, LA
1999 Floyd NC
2003 Isabel NC, VA
2004 Frances FL
2004 Ivan AL
2004 Jeanne FL
2005 Dennis FL, AL
2005 Katrina FL, LA, MS
2005 Rita TX, LA
2005 Wilma FL
2008 Ike TX
2009 Ida MS
2011 Irene NC, NJ MA, VT
2012 Isaac LA
2004 Charley FL, SC, NC
*/


