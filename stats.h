
#include <stdio.h>
// define the Stats structure here. See the tests to infer its properties
typedef struct
{
        float average;
        float max;
        float min;
}Stats;

Stats compute_statistics(const float* numberset, int setlength);

// If the email Alert has been sent
typedef struct
{
        bool emailAlertSent;
}EmailAlertSent;
extern EmailAlertSent Emailsent;

// If the led has turned on
typedef struct
{
        bool ledAlertOn;
}LedAlertSent;
extern LedAlertSent LedOn;

typedef void (*alerter_funcptr)();
void check_and_alert(float maxThreshold, void (*alerter_funcptr[])(), Stats computedStats);
//Function for LedAlerter
void emailAlerter(void);
//Function for Email Alert sent
void ledAlerter(void);
