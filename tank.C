#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "UniteTest.h"
#include "Solve_Square.h"

enum Options
{
    ERROR = 1,
    NO_ROOT,
    ONE_ROOT,
    TWO_ROOT,
    INFINITY_ROOT
};
int RunUniteTest();
void Input_coeff (double *,double *, double *);
int Solve_Square (double a, double b, double c, double *x1, double *x2);
int main ()
{ 
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    Input_coeff (&a,&b,&c);

    int answer = Solve_Square(a, b, c, &x1, &x2);
    switch (answer)
    {
    case ERROR: printf ("Error");
                break;
    case NO_ROOT: printf ("No roots");
                break;
    case ONE_ROOT: printf ("x = %.2f", x1);
                break;
    case TWO_ROOT: printf ("x1 = %.2f, x2 = %.2f", x1,x2);
                break;
    case INFINITY_ROOT: printf ("x is an any number");
                break;
    }
    int countfaild = RunUniteTest();
    printf ("Count failed: %d", countfaild);
    return 0;
}    
void Input_coeff(double *ptr1, double *ptr2, double *ptr3)
{
    printf ("# Square equation solver\n");
    printf ("Enter a, b, c: ");
    scanf ("%f %f %f", ptr1,ptr2,ptr3); 
}
int RunUniteTest() 
{
    int failed = 0;
    if ( UniteTest (1, 5, -6, 2, 1, -6) == 0 ) failed ++;
    return failed;
}