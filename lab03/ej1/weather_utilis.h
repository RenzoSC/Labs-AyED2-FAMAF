#ifndef _WEATHER_UTILIS_H
#define _WEATHER_UTILIS_H
#include "weather.h"
#include "array_helpers.h"

int minor_temp_min(WeatherTable a);

void max_temp_perYear(WeatherTable a, int outputArray[]);

void monthMaxPrecip_per_year(WeatherTable a, int outputArray[]);

#endif