// Author: Roger Greer
// Purpose: This program calculates the expression -(((5-4)*(8/2))+7) using
// value returning functions.

#include <iostream>
#include <cmath>

using namespace std;

// Prototype functions
void Instruct(void);
int Add(int A,int B);
int Subtract(int C,int D);
int Multiply(int E,int F);
int Divide(int G,int H);
int Negate(int I);

int main()
{
	int halt; //Halt on completion

	// Call to functions
	Instruct();
	 cout << Negate(Add(Multiply(Subtract(5,4),Divide(8,2)),7))<<endl;
 
    cin >> halt;
    return(0);
}

void Instruct(void)
{
	cout << "*************************************************************" << endl;
	cout << "* This program calculates the expression -(((5-4)*(8/2))+7) *" << endl;
	cout << "*************************************************************" << endl;
}
//Functions
 int Add(int A,int B)
 {
 return A+B;
 }
 
 int Subtract(int C,int D)
 {
 return C-D;
 }
 
 int Multiply(int E,int F)
 {
 return E*F;
 }
 
 int Divide(int G,int H)
 {
 return G/H;
 }
 
 int Negate(int I)
 {
 return -I;
 }
