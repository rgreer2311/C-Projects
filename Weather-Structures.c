/******************************************************************************
* Roger Greer
* Chapter 11
* This program reads a text file of weather data and determines the site with
* the greatest variation in temperature and the site with the highest average
* windspeed.
*******************************************************************************/
#include <stdio.h>

#define STRSIZE 80
#define SITE 3
#define DAYS 7

void instruct(void);

typedef struct
{
	int site_id_num;
	int wind_speed;
	int day_of_month;
	int temperature;
} measured_data_t;

typedef struct
{
	int site_id_num;
	int low_temp, high_temp;
	int avg_speed;
} calculated_data_t;

int main(void)
{
	char filename[STRSIZE];
	measured_data_t data[SITE*DAYS];
	calculated_data_t calculate[SITE];
	int variation[SITE], i, j, highAvg = 0, highVar = 0, siteHighAvg = 0, 
	siteHighVar = 0, status;
	FILE *fp;
	
	instruct();
	
	printf("Enter the meteorological data file => ");
	scanf("%s", filename);
    fp = fopen(filename,"r");
     
    if (fp == NULL)
    
    	printf("File not found!");
    
    else
    {
    	/* Get data from file*/
		for (i = 0; i < (SITE*DAYS); ++i)
			{			
			status = fscanf(fp, "%d%d%d%d", &data[i].site_id_num, 
											&data[i].day_of_month, 
											&data[i].wind_speed,
											&data[i].temperature);
			}
			
		/* Populate calculate structure with default values */
		for (j = 0; j < SITE; ++j)
		{
			calculate[j].site_id_num = data[j*DAYS].site_id_num;
			calculate[j].low_temp = 0;
			calculate[j].high_temp = 0;
			calculate[j].avg_speed = 0;
		}
		
		/* Calculate low and high temp, average speed */		
		for (i = 0; i < (SITE*DAYS); ++i)
		{
			for (j = 0; j < SITE; ++j)
			{
				if (calculate[j].site_id_num == data[i].site_id_num)
				{								
					if (calculate[i].low_temp <= data[i].temperature)
											
						calculate[j].low_temp = data[i].temperature;
							
					if (calculate[j].high_temp <= data[i].temperature)
					{
						calculate[j].high_temp = data[i].temperature;
					}
					
					if (calculate[j].avg_speed <= data[i].wind_speed)
					{
						calculate[j].avg_speed = calculate[j].avg_speed + data[i].wind_speed;
						calculate[j].avg_speed = calculate[j].avg_speed / DAYS;
					}
			    }
			}
		}
		
		
		
		/* Calculate variation */		
		for (j = 0; j < SITE; ++j)
			{
				if (calculate[j].avg_speed >= highAvg)
				{
					highAvg = calculate[j].avg_speed;
					siteHighAvg = calculate[j].site_id_num;
				}
				variation[j] = calculate[j].high_temp - calculate[j].low_temp;
		 		if (variation[j] >= highVar)
				{
					 highVar = variation[j];
					 siteHighVar = calculate[j].site_id_num;
				}
			}
			
		/* Display Result */
		printf("\nThe site with the highest average windspeed is: %d\n\n", siteHighAvg);
		printf("The site with the greatest variation in temperature is %d\n", siteHighVar);		
	}
	/* House keeping */
	fclose(fp);
	getch();
	return(0);
}

/* Provides user instructions */
void instruct(void)
{
	printf("\nThis program reads a text file in the programs directory of weather\n"); 
    printf("data and determines the site with the greatest variation in temperature\n"); 
    printf("and the site with the highest variation in windspeed respectivly.\n\n");
}


/* Project Data
2001 10 11 30
2001 11 5 22
2001 12 18 25
2001 13 16 26
2001 14 14 26
2001 15 2 25
2001 16 14 22
3345 10 8 29
3345 11 5 23
3345 12 12 23
3345 13 14 24
3345 14 10 24
3345 15 9 22
3345 16 9 20
3819 10 17 27
3819 11 22 21
3819 12 22 21
3819 13 18 22
3819 14 15 22
3819 15 9 19
3819 16 12 18
*/



















