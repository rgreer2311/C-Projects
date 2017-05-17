/* Monthly Loan Amoritization Calculator
*  Author: Roger Greer
*  Chapter Five
*  This program calculates a customized loan amoritization schedule given the 
*  loan amount, annual interest rate, and term of the loan. Payments are rounded
*  to the nearest cent. The program writes the schedule to an output file in 
*  the programsdirectory. */

#include <stdio.h>
#include <math.h>

/* Instructions function declaration */
void instruct(void);

/* Monthly payment function declaration*/
double loan_calc(double LA, double ANIR, int LT);

/* Main var declaration*/
double loanAmount, annualRate; 
int loanTerm;

int main(void)
{
	/* Call to instruction function */
	instruct();
	
	/* Capture the purchase price, annual intrest rate, and loan term. */
	printf("Enter loan amount => ");
	scanf("%lf", &loanAmount);

	printf("Enter the annual intrest rate => ");
	scanf("%lf", &annualRate);
	
	printf("Enter the number of payments => ");
	scanf("%d", &loanTerm);
	
	/* Call loan calculation function */
	loan_calc(loanAmount, annualRate, loanTerm); 
  
    getch();
    return(0);
}

/* This function provides user instructions for the program */
void instruct(void)
{
	printf("\nThis program calculates a loan amoritization schedule\n");
	printf("and provides an output file in the programs directory.\n");
	printf("Required input includes the loan amount, annual interest,\n");
	printf("rate and period of the loan.\n\n");
}

/* This function calculates the monthly loan payment 
*  based on the loan amount (LA), annual intrest rate(ANIR),
*  and loan term (LT) values passed from main().*/
double loan_calc(double LA, double ANIR, int LT)
{
	FILE * openFile;
	/* Function specific var declaration */
	double interest, intAccrued, balance, principal, loanPayment, finalPayment; 
	int count, payment=0;
	
    /* Calculate the monthly payment. */
    interest = (ANIR/100)/12;    /* Interest rate ans decimal */
    balance = LA;                /* Initially sets principal to loan amount */
    loanPayment = (interest * balance) / (1 -(pow((1 + interest),-LT))); /* Calculate the payment */
    
	/* Echo statement for output */
    openFile = fopen("AmoritizationSchedule.txt", "w");
    printf("\nPrincipal:       $%.2f    Payment: $%.2f\n", loanAmount, loanPayment); 
	printf("Annual Interest: %.1f%%        Term:    %d\n\n", annualRate, LT);
   	printf("Payment:   Interest:    Principal:   Balance:\n");
   	printf("------------------------------------------------\n");
   	
	   /* Output table header */
   	fprintf(openFile,"\nPrincipal:       $%.2f    Payment: $%.2f\n", loanAmount, loanPayment); 
	fprintf(openFile,"Annual Interest: %.1f%%        Term:    %d\n\n", annualRate, LT);
   	fprintf(openFile,"Payment:   Interest:    Principal:   Balance: \n");
   	fprintf(openFile,"------------------------------------------------\n");
	
	for(count=0; count < LT; count = count +1)
	{
	    intAccrued = balance * interest;
		principal = loanPayment - intAccrued;
		balance = balance - (intAccrued + principal);
		if (balance <= 0)
		{
			balance = 0;
		}
	 	payment = payment +1;
	 	
		/* Echo statement for output */	 	
	    printf("%4d %13.2f %13.2f %11.2f\n", payment, intAccrued, principal, balance);
	    
	    /* Output table */
	    fprintf(openFile,"%4d %13.2f %13.2f %11.2f\n", payment, intAccrued, principal, balance);
		if (payment ==6)	
	    {
	    	/* Output table EOF */
	    	finalPayment = principal + intAccrued;
	     	fprintf(openFile,"\nFinal Payment:    $%.2f\n", finalPayment);
	    	fprintf(openFile,"------------------------------------------------\n");
	    	
	    	/* Echo statement for output */
			printf("\nFinal Payment:    $%.2f\n", finalPayment);
	    	printf("------------------------------------------------\n");
	    	fclose(openFile);
	    }
    }   
}













