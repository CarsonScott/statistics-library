#ifndef STATS_HPP_INCLUDED
#define STATS_HPP_INCLUDED

#include <vector>
#include <cmath>

#define DataSet std::vector<float>

float mean(DataSet);
float variance(DataSet, bool);
float std_dev(DataSet, bool);
float mse(DataSet, DataSet);
float weighted_mse(DataSet, DataSet, DataSet);
#endif // STATS_HPP_INCLUDED
