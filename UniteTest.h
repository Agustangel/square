int UniteTes (int TestNum, double a, double b,
            double c, int nRoots, double x1ref, double x2ref);
int isEqual(double x1, double x1ref);
int Solve_Square (double a, double b, double c, double *x1, double *x2);
    double x1 = 0, x2 = 0;
    enum Different 
    {
        EQUALS=5,
        NOT_EQUALS
    };
    int nRoots = Solve_Square(a,b,c, &x1, &x2);
    int n = isEqual(x1, x1ref);
    int m = isEqual(x2, x2ref);
    if ((n == NOT_EQUALS) || (m == NOT_EQUALS))
        {
        printf ("Test %d FAILED: \n"
        "x1 = %f, x2 = %f, should be x1 = %f, x2 = %f", TestNum, x1, x2, x1ref, x2ref);
        return 0;
        }
    else 
        {
        printf ("OK");
        return 1;
        }

int isEqual(double xn, double xnref)
{   
    double eps=1e-10;
    if (fabs(xn-xnref) < eps)
        return EQUALS;
    else 
        return NOT_EQUALS;
}