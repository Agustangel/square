int Solve_Square(double a, double b, double c, double *x1, double *x2)
{
    double eps=1e-10;
    assert (std::isfinite (a));
    assert (std::isfinite (b));
    assert (std::isfinite (c));
    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);
    {
    if (fabs(a) < eps)
        { 
        if (fabs(b) < eps)
            {
            if (fabs(c) < eps)
                {
                 return INFINITY_ROOT;
                }
            else return ERROR;
            }
        else 
            {
            *x1 = *x2 = -c / b;
            return ONE_ROOT;
            }
        }
    else 
        {
        double d = pow (b, 2) - 4*a*c;

        if (d < 0)
            {
            return NO_ROOT;
            }
        if (fabs(d) < eps)
            {
            *x1 = *x2 = -b / (2*a);
            return ONE_ROOT;
            }
        if (d > 0)
            {
            *x1 = (-b + sqrt(d))/(2*a);
            *x2 = (-b - sqrt(d))/(2*a);
            return TWO_ROOT;
            }
        }
    }
}  