#include <gtest/gtest.h>
#include "grid.h"
#include "station.h"
#include "analysis.h"

TEST(GridTest, IndexCalculation) {
    EXPECT_EQ(grid_index(0, 0, 4), 0);
    EXPECT_EQ(grid_index(1, 2, 4), 6);
    EXPECT_EQ(grid_index(2, 3, 4), 11);
}

TEST(GridTest, InBoundsCheck) {
    EXPECT_TRUE(in_bounds(0, 0, 3, 4));
    EXPECT_TRUE(in_bounds(2, 3, 3, 4));
    EXPECT_FALSE(in_bounds(-1, 0, 3, 4));
    EXPECT_FALSE(in_bounds(3, 0, 3, 4));
    EXPECT_FALSE(in_bounds(0, 4, 3, 4));
}

TEST(AnalysisTest, StationAverage) {
    double temps[6] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0};
    double avg = 0.0;
    EXPECT_TRUE(station_average(temps, 2, 3, 0, avg));
    EXPECT_DOUBLE_EQ(avg, 20.0);

    double unmod_avg = -1.0;
    EXPECT_FALSE(station_average(temps, 2, 3, 5, unmod_avg));
    EXPECT_DOUBLE_EQ(unmod_avg, -1.0);
}

TEST(AnalysisTest, DayAverage) {
    double temps[6] = {10.0, 20.0, 30.0, 40.0, 50.0, 60.0};
    double avg = 0.0;
    EXPECT_TRUE(day_average(temps, 2, 3, 1, avg));
    EXPECT_DOUBLE_EQ(avg, 35.0);
}

TEST(AnalysisTest, FindHottest) {
    double temps[6] = {10.0, 20.0, 30.0, 40.0, 60.0, 50.0};
    int r = -1, c = -1;
    EXPECT_TRUE(find_hottest(temps, 2, 3, r, c));
    EXPECT_EQ(r, 1);
    EXPECT_EQ(c, 1);
}

TEST(AnalysisTest, CountAbove) {
    double temps[6] = {10.0, 25.0, 30.0, 40.0, 15.0, 50.0};
    EXPECT_EQ(count_above(temps, 2, 3, 25.0), 3);
}

TEST(StationTest, FindStationName) {
    Station stations[3] = {{"Normal", 100.0}, {"Fairway", 200.0}, {"North", 150.0}};
    EXPECT_EQ(find_station(stations, 3, "Fairway"), 1);
    EXPECT_EQ(find_station(stations, 3, "fairway"), 1);
    EXPECT_EQ(find_station(stations, 3, "Unknown"), -1);
}
