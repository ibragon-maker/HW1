#ifndef REPORT_H
#define REPORT_H

#include "station.h"

/**
 * @brief Prints weather station analysis report.
 * @param stations Array of Station structures.
 * @param temps Pointer to temperature array.
 * @param rows Total rows (stations).
 * @param cols Total columns (days).
 * @param threshold Temperature threshold for count_above.
 */
void print_report(const Station* stations, const double* temps, int rows, int cols, double threshold);

#endif 
