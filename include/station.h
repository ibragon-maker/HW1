#ifndef STATION_H
#define STATION_H

#include <string>

struct Station {
    std::string name;
    double elevation_m;
};

/**
 * @brief Finds index of a station by name (case-insensitive).
 * @param stations Array of Station structures.
 * @param count Number of stations.
 * @param name Target station name.
 * @return Index of matching station, or -1 if not found.
 */
int find_station(const Station* stations, int count, const std::string& name);

#endif 
