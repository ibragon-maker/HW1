#include "station.h"
#include <algorithm>
#include <cctype>

static std::string to_lower(std::string s) {
    for (char &c : s) {
        c = std::tolower(static_cast<unsigned char>(c));
    }
    return s;
}

int find_station(const Station* stations, int count, const std::string& name) {
    if (!stations || count <= 0) {
        return -1;
    }
    std::string target = to_lower(name);
    for (int i = 0; i < count; ++i) {
        if (to_lower(stations[i].name) == target) {
            return i;
        }
    }
    return -1;
}
