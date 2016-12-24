#include "Sample.hpp"

long double Sample::computeMean(long double x)
    {
        long double m;
        if(data.size() < 2)
        {
            m = x;
        }
        else if(data.size() == max_size + 1)
        {
            m = (x + mean*max_size - data[0])/max_size;
        }
        else
        {
            m = (x + mean*(data.size() - 1))/data.size();
        }
        return m;
    }

    long double Sample::computeVariance(long double x, long double m)
    {
        long double v;
        if(data.size() < max_size)
        {
            v = 0;
        }
        else if(data.size() == max_size + 1)
        {
            v = (variance*(max_size - 1) - pow(data[0] - m, 2) + pow(x - mean, 2))/(max_size - 1);
        }
        else
        {
            v = var(data, true);
        }
        return v;
    }

    long double Sample::computeStandardDeviation()
    {
        return sqrt(variance);
    }

    Sample::Sample(int sample_size)
    {
        max_size = sample_size;
        mean = 0;
        variance = 0;
    }

    void Sample::append(long double x)
    {
        data.push_back(x);
        long double m = mean;

        mean = computeMean(x);
        variance = computeVariance(x, m);

        if(data.size() == max_size + 1)
        {
            data.erase(data.begin());
        }
    }

    long double Sample::getMean()
    {
        return mean;
    }

    long double Sample::getVariance()
    {
        return variance;
    }

    long double Sample::getStandardDeviation()
    {
        return sqrt(variance);
    }

    Data Sample::getData()
    {
        return data;
    }
