#include "Stats.hpp"

long double mean(Data x)
{
    long double m = 0;
    for(int i = 0; i < x.size(); i++)
    {
        m += x[i];
    }

    return m/x.size();
}

long double var(Data x, bool sample=false)
{
    long double v = 0;
    long double m = mean(x);
    for(int i = 0; i < x.size(); i++)
    {
        v += pow(x[i]-m, 2);
    }
    long double n = x.size();
    if(sample) n -= 1;

    return v/n;
}

long double std_dev(Data x, bool sample=false)
{
    /* Standard Deviation */
    return sqrt(var(x, sample));
}

long double mse(Data p, Data m)
{
    /* Mean-Squared Error */
    long double e = 0;
    for(int i = 0; i < p.size(); i++)
    {
        e += pow(p[i]-m[i], 2);
    }

    return e/p.size();
}

long double wmse(Data p, Data m, Data w)
{
    /* Weighted Mean-Squared Error */
    long double e = 0;
    for(int i = 0; i < p.size(); i++)
    {
        e += pow(p[i]-m[i], 2)*w[i];
    }

    return e/p.size();
}
