#ifndef ANALYSIS_H
#define ANALYSIS_H

#include "grid.h"

/**
 * @brief Calculates average temperature for a specific station.
 * @param temps Pointer to temperature array.
 * @param rows Total rows (stations).
 * @param cols Total columns (days).
 * @param station Index of target station.
 * @param average Reference to store computed average.
 * @return True on success, false if out of bounds.
 */
bool station_average(const double* temps, int rows, int cols, int station, double& average);

/**
 * @brief Calculates average temperature for a specific day.
 * @param temps Pointer to temperature array.
 * @param rows Total rows (stations).
 * @param cols Total columns (days).
 * @param day Index of target day.
 * @param average Reference to store computed average.
 * @return True on success, false if out of bounds.
 */
bool day_average(const double* temps, int rows, int cols, int day, double& average);

/**
 * @brief Finds the highest temperature in the grid.
 * @param temps Pointer to temperature array.
 * @param rows Total rows (stations).
 * @param cols Total columns (days).
 * @param hot_row Reference to store row of hottest temp.
 * @param hot_col Reference to store column of hottest temp.
 * @return True on success, false if dimensions invalid.
 */
bool find_hottest(const double* temps, int rows, int cols, int& hot_row, int& hot_col);

/**
 * @brief Counts readings strictly greater than a threshold.
 * @param temps Pointer to temperature array.
 * @param rows Total rows.
 * @param cols Total columns.
 * @param threshold Temperature cutoff.
 * @return Count of readings above threshold.
 */
int count_above(const double* temps, int rows, int cols, double threshold);

#endif 
