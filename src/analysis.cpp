#include "grid.h"
#include "analysis.h"

bool station_average(const double* temps, int rows, int cols, int station, double& average) {
    if (!in_bounds(station, 0, rows, cols) || cols <= 0) {
        return false;
    }
    double sum = 0.0;
    for (int col = 0; col < cols; ++col) {
        int idx = grid_index(station, col, cols);
        sum += temps[idx];
    }
    average = sum / cols;
    return true;
}

bool day_average(const double* temps, int rows, int cols, int day, double& average) {
    if (!in_bounds(0, day, rows, cols) || rows <= 0) {
        return false;
    }
    double sum = 0.0;
    for (int row = 0; row < rows; ++row) {
        int idx = grid_index(row, day, cols);
        sum += temps[idx];
    }
    average = sum / rows;
    return true;
}

bool find_hottest(const double* temps, int rows, int cols, int& hot_row, int& hot_col) {
    if (rows <= 0 || cols <= 0) {
        return false;
    }
    double max_temp = temps[0];
    hot_row = 0;
    hot_col = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int idx = grid_index(r, c, cols);
            if (temps[idx] > max_temp) {
                max_temp = temps[idx];
                hot_row = r;
                hot_col = c;
            }
        }
    }
    return true;
}

int count_above(const double* temps, int rows, int cols, double threshold) {
    int count = 0;
    int total = rows * cols;
    for (int i = 0; i < total; ++i) {
        if (temps[i] > threshold) {
            count++;
        }
    }
    return count;
}
