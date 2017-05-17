/******************************************************************************
* Roger Greer
* Chapter 10
* PURPOSE: This program displays vehicle informaion from an in-put file using
* structures.
******************************************************************************/

#include <stdio.h>
#define strSize 20

/* Structure defines the date */
typedef struct
{
	int month, day, year;
} date_t;

/* Structure defines the capacity and current fuel level of the fuel tank */
typedef struct
{
	double capacity, current;
} tank_t;

/* Structure defines the automobile */
typedef struct
{
	char make[strSize], model[strSize]; 
	int odometer;
	date_t man, purch;
	tank_t tank;
} auto_t;

/* Provides user instructions */
void instruct(void)
{
	printf("\nThis program displays vehicle informaion from an in-put file\n");
	printf("located in the programs directory\n\n");
}

/* Scan data into auto struct */
int scan_auto(auto_t *vehicle, FILE *fp) 
{
	return fscanf(fp, "%s %s %d", vehicle->make, vehicle->model, &vehicle->odometer);
}

/* Scan data into date struct */
int scan_date(auto_t *vehicle, FILE *fp) 
{
		return fscanf(fp, "%d %d %d %d %d %d"
        , &vehicle->man.month
        , &vehicle->man.day
        , &vehicle->man.year
        , &vehicle->purch.month
        , &vehicle->purch.day
        , &vehicle->purch.year);
}

/* Scan data into tank struct */
int scan_tank(auto_t *vehicle, FILE *fp) 
{
		return fscanf(fp, "%lf %lf"
        , &vehicle->tank.capacity
        , &vehicle->tank.current);
}

/* Print data from auto struct */
void print_auto(auto_t vehicle) 
{
	printf("%s\t%2s\t%d\t"
    , vehicle.make
    , vehicle.model
    , vehicle.odometer);
}

/* Print data from date struct */
void print_date(auto_t vehicle) 
{
	printf("%8d-%d-%d\t %d-%d-%d\t"
    , vehicle.man.month
    , vehicle.man.day
    , vehicle.man.year
    , vehicle.purch.month
    , vehicle.purch.day
    , vehicle.purch.year);
}

/* Print data from tank struct */
void print_tank(auto_t vehicle) 
{
	printf("%7.1lfgal%12.1lfgal\n"
    , vehicle.tank.capacity
    , vehicle.tank.current);
}

int main()
{
auto_t vehicle;
FILE *fp;
char fileName[20];

instruct();

printf("Enter the name of the data file => ");
    scanf("%s", fileName);
    fp = fopen(fileName,"r");
     
    if (fp == NULL)
    {
    	printf("File not found!");
    }
    else
    {
    printf("\n  MAKE  MODEL   ODOMETER    MANUFACTURE DATE   PURCHASE DATE    TANK CAPACITY    FUEL LEVEL\n");
    printf("\n-------------------------------------------------------------------------------------------\n");
		while(1) 
			{
		    /* Validate scan_auto(&vehicle) */
		    if(scan_auto(&vehicle, fp) == EOF)
			{
		        break;
		    }
		    /* Validate scan_date(&date) */
		    if(scan_date(&vehicle, fp) == EOF)
			{
		        break;
		    }
		    /* Validate scan_tank(&tank) */
		    if(scan_tank(&vehicle, fp) == EOF)
			{
		    	break;
		    }
		    /* Print data */
		    print_auto(vehicle);
		    print_date(vehicle);
		    print_tank(vehicle);
	    	}
    }
getch();
return (0);
}

/* Project Data
Mercury Sable 99842 1 18 2001 5 30 1991 16  12.5
Mazda Navajo 123961 2 20 1993 6 15 1993 19.3 16.7
*/