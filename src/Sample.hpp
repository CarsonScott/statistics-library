#ifndef SAMPLE_HPP_INCLUDED
#define SAMPLE_HPP_INCLUDED

#include "Stats.hpp"

class Sample
{
    Data data;
    int max_size;
    long double mean;
    long double variance;
    long double computeMean(long double);
    long double computeVariance(long double, long double);
    long double computeStandardDeviation();

public:
    Sample(int);
    void append(long double);
    long double getMean();
    long double getVariance();
    long double getStandardDeviation();
    Data getData();
};

#endif // SAMPLE_HPP_INCLUDED
