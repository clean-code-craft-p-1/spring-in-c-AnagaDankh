#include "stats.h"

#include "gtest/gtest.h"
#include <stdlib.h>
#include <math.h>

TEST(Statistics, ReportsAverageMinMax) {
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats computedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;
    EXPECT_LT(abs(computedStats.average - 4.525), epsilon);
    EXPECT_LT(abs(computedStats.max - 8.9), epsilon);
    EXPECT_LT(abs(computedStats.min - 1.5), epsilon);
}


TEST(Statistics, AverageNaNForEmpty) {
    Stats computedStats = compute_statistics(0, 0);

    // Checking if sent as not a number
    EXPECT_TRUE(std::isnan(computedStats.average));
    EXPECT_TRUE(std::isnan(computedStats.min));
    EXPECT_TRUE(std::isnan(computedStats.max));
}

TEST(Alert, AlertsWhenMaxExceeds) {
     void (*alerter_funcptr[2])() = {ledAlerter, emailAlerter};
    
    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    Stats computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerter_funcptr, computedStats);
    
    EXPECT_EQ(true, Emailsent.emailAlertSent);
    EXPECT_EQ(true, LedOn.ledAlertOn);
}
