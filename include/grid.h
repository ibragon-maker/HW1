#ifndef GRID_H
#define GRID_H

/**
 * @brief Converts 2D grid coordinates to a 1D array index.
 * @param row Row index.
 * @param col Column index.
 * @param cols Total number of columns.
 * @return Computed 1D index.
 */
int grid_index(int row, int col, int cols);

/**
 * @brief Checks if a row and column pair is within grid bounds.
 * @param row Row index.
 * @param col Column index.
 * @param rows Total rows.
 * @param cols Total columns.
 * @return True if within bounds, false otherwise.
 */
bool in_bounds(int row, int col, int rows, int cols);

#endif 
