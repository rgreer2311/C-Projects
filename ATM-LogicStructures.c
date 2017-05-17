/* Roger Greer
*  Chapter06
*  PURPOSE: This program performs an ATM function of dispensing a desired dollar
*  amount in multiples of $10 in $10, $20, and $50 denominations.*/

#include <stdio.h>

#define MAX 500 /* The maximum withdrawl amount allowed daily */

/* Declare prototype functions */
void instruct(void);
int ATM(int cash);
void dispence(int *fifty, int *twenty, int *ten);

int main(void)
{
	/* Var decleration */
	int amount;
	
	/* Calls user instruction function */
	instruct();
	
	/* Get dollar denomenation ensure divisible by 10 and !> MAX */
	do 
	{
		printf("The maximum daily withdrawl amount is $%d\n", MAX);
		printf("Please enter the dollar amount in multiples of $10 => ");
		scanf("%d",&amount);
	}
    while (amount>MAX || amount%10>0);
	
	/* Pass amount to ATM function */
	ATM(amount);
	
	getch();
	return(0);
}

/* This function provides user instructions for the ATM program */
void instruct(void)
{
	printf("\nThis program returns the number of bills for a given withdrawl amount\n");
	printf("in demoninations of $50, $20, and $10. The user enters a desired amount\n"); 
	printf("not to exceed the $%d daily limit in multiples of $10.\n\n", MAX);
}

/* This function displays the dollar demonination for the specified withdrawl amount
*  PRE: Input should be >0, divisible by 10, and <= MAX */
int ATM(int cash)
{
	/* Local var decleration */
	int grant = 50, jack = 20, ham = 10, denom50, denom20, denom10;
	int *total; /* Define pointer*/
	total = &cash; /* Assign pointer to memory location */

	/* Determine correct demonination in 50, 20, & 10 */
	denom50 = *total/grant;
	*total = *total-(denom50*grant);
	denom20 = *total/jack;
	*total = *total-(denom20*jack);
	denom10 = *total/ham;
	*total = *total-(denom10*ham);
	
	/* Pass values by reference to dispence */
	dispence(&denom50, &denom20, &denom10);
}

/* This function takes values by reference from ATM and formats output */
void dispence(int *fifty, int *twenty, int *ten)
{
	/* Return correct denomenation of bills */
	printf("\n****PLEASE TAKE YOUR CASH****\n");
	if (*fifty > 0)
		printf("%13d x $50\n", *fifty);
	if (*twenty > 0)
		printf("%13d x $20\n", *twenty);
	if (*ten > 0)
		printf("%13d x $10\n", *ten);
	printf("*****************************");
}







