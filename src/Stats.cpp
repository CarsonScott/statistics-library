#include "Stats.hpp"

float mean(DataSet x)
{
    float m = 0;
    for(int i = 0; i < x.size(); i++)
    {
        m += x[i];
    }
    return m/x.size();
}

float variance(DataSet x, bool sample=false)
{
    float v = 0;
    float m = mean(x);
    for(int i = 0; i < x.size(); i++)
    {
        v += pow(x[i] - m, 2);
    }
    float n = x.size();
    if(sample) n -= 1;
    return v/n;
}

float std_dev(DataSet x, bool sample=false)
{
    /* Standard Deviation */
    return sqrt(variance(x, sample));
}

float mse(DataSet p, DataSet m)
{
    /* Mean-Squared Error */
    float e = 0;
    for(int i = 0; i < p.size(); i++)
    {
        e += pow(p[i] - m[i], 2);
    }
    return e/p.size();
}

float wmse(DataSet p, DataSet m, DataSet w)
{
    /* Weighted Mean-Squared Error */
    float e = 0;
    for(int i = 0; i < p.size(); i++)
    {
        e += w[i]*pow(p[i] - m[i], 2);
    }
    return e/p.size();
}
