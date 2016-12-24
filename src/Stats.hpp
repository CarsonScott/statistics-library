#ifndef STATS_HPP_INCLUDED
#define STATS_HPP_INCLUDED

#include <vector>
#include <cmath>

#define Data std::vector<long double>

long double mean(Data);
long double var(Data, bool);
long double std_dev(Data, bool);
long double mse(Data, Data);
long double weighted_mse(Data, Data, Data);

#endif // STATS_HPP_INCLUDED
