#ifndef STATION_H
#define STATION_H

#include <string>

struct Station {
    std::string name;
    double elevation_m;
};

int find_station(const Station* stations, int count, const std::string& name);

#endif 
