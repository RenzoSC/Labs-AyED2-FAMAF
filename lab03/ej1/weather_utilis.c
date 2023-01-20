#include <stdio.h>
#include "weather_utilis.h"

int minor_temp_min(WeatherTable a){
    int minor_temp = a[0][0][0]._min_temp;
    for(int year=0; year < YEARS; year++){
        for(int month=0; month < MONTHS; month++){
            for (int day = 0; day < DAYS; day++){
                if(minor_temp >= a[year][month][day]._min_temp){
                    minor_temp = a[year][month][day]._min_temp;
                }
            }
        }
    }
    return minor_temp;
}

void max_temp_perYear(WeatherTable a, int outputArray[]){
    int max_temp;
    for(int year=0; year < YEARS; year++){
        max_temp = a[year][0][0]._max_temp;
        for(int month=0; month < MONTHS; month++){
            for (int day = 0; day < DAYS; day++){
                if(max_temp <= a[year][month][day]._max_temp){
                    max_temp = a[year][month][day]._max_temp;
                }
            }
        }
        outputArray[year] = max_temp;
    }
}

void monthMaxPrecip_per_year(WeatherTable a, int outputArray[]){
    for(int year=0; year < YEARS; year++){
        int topMonthOfYear=0;
        int topTotalPrepMonth=0;
        for(int month=0; month < MONTHS; month++){
            
            int totalPrepMonth= 0;
            
            for (int day = 0; day < DAYS; day++){
                totalPrepMonth += a[year][month][day]._rainfall;
            }

            if (topTotalPrepMonth<= totalPrepMonth)
            {
                topTotalPrepMonth = totalPrepMonth;
                topMonthOfYear = month;
            }
            
        }
        outputArray[year] = topMonthOfYear;
    }
}