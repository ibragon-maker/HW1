#include "report.h"
#include "analysis.h"
#include "grid.h"
#include <iostream>
#include <iomanip>

void print_report(const Station* stations, const double* temps, int rows, int cols, double threshold) {
    if (!stations || !temps || rows <= 0 || cols <= 0) {
        std::cout << "Invalid grid dimensions or null pointer provided.\n";
        return;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "=== Weather Station Report ===\n";

    // Station Averages
    for (int r = 0; r < rows; ++r) {
        double avg = 0.0;
        if (station_average(temps, rows, cols, r, avg)) {
            std::cout << stations[r].name << " avg " << avg << " F\n";
        }
    }

    // Day Averages
    for (int c = 0; c < cols; ++c) {
        double avg = 0.0;
        if (day_average(temps, rows, cols, c, avg)) {
            std::cout << "Day " << (c + 1) << " avg " << avg << " F\n";
        }
    }

    // Hottest Location
    int hot_r = 0, hot_c = 0;
    if (find_hottest(temps, rows, cols, hot_r, hot_c)) {
        int idx = grid_index(hot_r, hot_c, cols);
        std::cout << "Hottest reading: " << temps[idx] << " F at " 
                  << stations[hot_r].name << " (day " << (hot_c + 1) << ")\n";
    }

    // Readings above threshold
    int above_count = count_above(temps, rows, cols, threshold);
    std::cout << "Readings above " << threshold << " F: " << above_count << "\n";
}
