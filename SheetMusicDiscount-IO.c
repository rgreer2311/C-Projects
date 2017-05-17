/* Roger Greer
*  Chapter04
*  PURPOSE: This program calculates various discounts on sheet music based on 
*  the condition of whether a customer is a music teacher or not and the  
*  purchase total. The program applies the discount before 5% sales tax is  
*  applied and provides a reciept as an output text file that can be found
*  in the programs directory*/

#include <stdio.h>
#define salesTax 5
#define disOne 10
#define disTwo 12 

/* Provides user instructions  */
void dis_instruct(void); 
/* Calculates discount */
double discount(double CalcSubTotal, char calcCustype); 
/* Prints echo statement and appropriate receipt */
double print_receipt(int printReceipt, double printSubTotal, double printTeachdis, double printDistotal, double printTaxtotal, double printFintotal);

int main(void)
{
	/* Declare variavles */
	double salesTotal;
	char cusType;
	
	/* Calls user instructions function */
	dis_instruct();
	
	/* Get the sales total */
	printf("Enter the sales total => ");
	scanf("%lf", &salesTotal);
	
	/* Determine if customer is a teacher, conditional statement */
	printf("Is the customer an educator? (Y/N) => ");
	scanf(" %c", &cusType);
	
	/* Call the discount function  */
	discount(salesTotal, cusType);	
		
	getch();
	return(0);
}

void dis_instruct(void)
{      
	printf(" \n*** Keith's Sheet Music Educator's Discount Program ***\n\n");
	printf("This program applies a %d%% educators discount to the\n", disOne);
	printf("total purchase. Orders over $100.00 receive a %d%% discount.\n", disTwo);
	printf("%d%% sales tax is then applied to the total. Enter the orders \n", salesTax);
	printf("sub total and whether the customer is an educator as (Y/N).\n\n");
}

/* Discount function calculates conditional discount, totals, & receipt */
double discount(double calcSubTotal, char calcCustype)
{
double calcTeachdis, calcDistotal, calcTaxtotal, calcPretax, calcFintotal;
int calcReceipt;

				
	/* Apply appropriate discount based on educator status & purchase amount */
	if ((calcCustype == 'Y' || calcCustype == 'y') && calcSubTotal < 100)
		{/* Educator, subtotal is < than $100, applies 10% discount */
		calcReceipt = 1;
        calcTeachdis = calcSubTotal * disOne / 100; 
		calcDistotal = calcSubTotal - calcTeachdis; 
		}
	else if ((calcCustype == 'Y' || calcCustype == 'y') && calcSubTotal >= 100)
		{/* Educator, subtotal is >= to $100, applies 12% discount */
		calcReceipt = 1;
		calcTeachdis = calcSubTotal * disTwo / 100; 
		calcDistotal = calcSubTotal - calcTeachdis; 
		}
	else if (calcCustype == 'N' || calcCustype =='n')	
		/* Not an educator, no discount applied */
		calcReceipt = 2;
		calcDistotal = calcSubTotal;
					
	/* Apply 5% sales tax */
	calcTaxtotal = calcDistotal * salesTax / 100;
	calcFintotal = calcDistotal + calcTaxtotal;
	
	/* Calculations complete, print receipt*/
	print_receipt(calcReceipt, calcSubTotal, calcTeachdis, calcDistotal, calcTaxtotal, calcFintotal);
}

double print_receipt(int printReceipt, double printSubTotal, double printTeachdis, double printDistotal, double printTaxtotal, double printFintotal)
{	
	/* Prints echo statements & receipt based on customer type */
    FILE * openFile;
	if (printReceipt == 1 )
	{   /* Echo statements for receipt output */
	    printf("\nTotal purchase    $%.2f\n",printSubTotal);
		printf("Teachers discount $%.2f\n",printTeachdis);
		printf("Discount total    $%.2f\n",printDistotal);
		printf("Sales tax         $%.2f\n",printTaxtotal);
		printf("Total             $%.2f\n",printFintotal);
		
		/* Print Receipt */
		openFile = fopen("salesreceipt.txt", "w");
		fprintf(openFile, "   Keith's Sheet Music\n");
		fprintf(openFile,"\nTotal purchase    $%.2f\n",printSubTotal);
		fprintf(openFile,"Teachers discount $%.2f\n",printTeachdis);
		fprintf(openFile,"Discount total    $%.2f\n",printDistotal);
		fprintf(openFile,"Sales tax         $%.2f\n",printTaxtotal);
		fprintf(openFile,"Total             $%.2f\n\n",printFintotal);
		fprintf(openFile,"   Thanks for shopping!");
		fclose(openFile);
	}
	else if (printReceipt == 2)
	{	/* Echo statements for receipt output */
		printf("\nTotal purchase    $%.2f\n",printSubTotal);
		printf("Sales tax         $%.2f\n",printTaxtotal);
		printf("Total             $%.2f\n\n", printFintotal);
		
		/* Print Receipt */		
		openFile = fopen("salesreceipt.txt", "w");
		fprintf(openFile,"  Keith's Sheet Music\n");
		fprintf(openFile,"\nTotal purchase    $%.2f\n",printSubTotal);
		fprintf(openFile,"Sales tax         $%.2f\n",printTaxtotal);
		fprintf(openFile,"Total             $%.2f\n\n",printFintotal);
		fprintf(openFile," Thanks for shopping!");
		fclose(openFile);
	}
}


