#include "grid.h"
#include "station.h"
#include "analysis.h"
#include "report.h"
#include <iostream>
#include <string>

int main() {
    constexpr int station_count = 4;
    constexpr int day_count = 7;

    const Station stations[station_count] = {
        {"Normal", 161.5},
        {"Fairway", 152.0},
        {"North", 170.0},
        {"Downtown", 145.0}
    };

    const double temps[station_count * day_count] = {
        50.0, 52.5, 51.0, 53.0, 55.0, 54.0, 52.0, // Normal
        58.0, 60.0, 62.0, 61.0, 63.0, 65.0, 64.0, // Fairway
        45.0, 47.0, 46.0, 48.0, 50.0, 49.0, 47.5, // North
        60.0, 62.0, 65.0, 67.0, 66.0, 68.0, 69.0  // Downtown
    };

    double threshold = 55.0;

    print_report(stations, temps, station_count, day_count, threshold);

    std::cout << "\nStation to look up: ";
    std::string query;
    if (std::getline(std::cin, query) && !query.empty()) {
        int idx = find_station(stations, station_count, query);
        if (idx != -1) {
            double avg = 0.0;
            if (station_average(temps, station_count, day_count, idx, avg)) {
                std::cout << "Station " << stations[idx].name << " avg " << avg << " F.\n";
            }
        } else {
            std::cout << "No station named \"" << query << "\".\n";
        }
    }

    return 0;
}
