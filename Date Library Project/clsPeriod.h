#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include"clsDate.h"
using namespace std;

class clsPeriod
{
    public:
        clsDate StartDate;
        clsDate EndDate;

        clsPeriod(clsDate StartDate, clsDate EndDate)
        {
            this->StartDate = StartDate;
            this->EndDate = EndDate;
        }

        static bool isPeriodsOverlap(clsPeriod Period1, clsPeriod Period2)
        {
            if (clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == -1 || clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == 1)
            {
                return false;
            }

            else 
                return true;
        
        }

        bool isPeriodsOverlap(clsPeriod Period2)
        {
            return isPeriodsOverlap(*this, Period2);
        }

        static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
        {
            return clsDate::DifferenceBetweenTwoDatesInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
        }

        int PeriodLengthInDays(bool IncludeEndDay = false)
        {
            return PeriodLengthInDays(*this, IncludeEndDay);
        }

        static bool isDateWithinPeriod(clsPeriod Period, clsDate Date)
        {
            return !(clsDate::CompareDates(Date, Period.StartDate) == -1 || clsDate::CompareDates(Date, Period.EndDate) == 1);
        }

        bool isDateWithinPeriod(clsDate Date)
        {
            return isDateWithinPeriod(*this, Date);
        }

        static int CountOverlapDaysBetweenTwoPeriods(clsPeriod Period1, clsPeriod Period2)
        {
            if (!isPeriodsOverlap(Period1,Period2))
            {
                return 0;
            }
            
            int NumberOfDays = 0;

            while (clsDate::isDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
            {
                if (isDateWithinPeriod(Period2, Period1.StartDate))
                {
                    NumberOfDays++;
                }

                clsDate::IncreaseDateByOneDay(Period1.StartDate);
            }
            
            return NumberOfDays;
        }

        int CountOverlapDays(clsPeriod Period2)
        {
            return CountOverlapDaysBetweenTwoPeriods(*this, Period2);
        }
        
};