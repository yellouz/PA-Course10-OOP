#pragma once

#include<iostream>
#include<ctime>
using namespace std;

enum enDayName { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

struct sDate
{
    short Day;
    short Month;
    short Year;
};

sDate ReadDate()
{
    sDate Date;

    cout << "Please Enter a Month Number : ";
    cin >> Date.Month;

    cout << "Please Enter a Year : ";
    cin >> Date.Year;

    cout << "Please Enter a Day : ";
    cin >> Date.Day;

    return Date;
}

bool isLeapYear(int Year)
{
    return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
}

bool isLeapYear(sDate Date)
{
    return isLeapYear(Date.Year);
}

int NumberOfDaysInMonth(int Month, int Year)
{
    switch (Month)
    {
    case 1:
        return 31;
        break;
    
    case 2:
        return (isLeapYear(Year) ? 29 : 28);
        break;

    case 3:
        return 31;
        break;

    case 4:
        return 30;
        break;

    case 5:
        return 31;
        break;

    case 6:
        return 30;
        break;

    case 7:
        return 31;
        break;
    
    case 8:
        return 31;
        break;

    case 9:
        return 30;
        break;

    case 10:
        return 31;
        break;

    case 11:
        return 30;
        break;

    case 12:
        return 31;
        break;

    default:
        break;
    } 
}

int NumberOfDaysInMonth(sDate Date)
{
    return NumberOfDaysInMonth(Date.Month, Date.Year);
}

short DayOrder(int Day, int Month, int Year)
{
    int a = (14 - Month) / 12;
    int y = Year - a;
    int m = Month + 12 * a - 2;
    //Gregorian Calendar:
    int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
    //Sun=0, Mon=1, Tue=2 ...
    return d;
}

short DayOrder(sDate Date)
{
    return DayOrder(Date.Day, Date.Month, Date.Year);
}

string MonthShortName(short MonthNumber)
{
    string Months[12] = { "Jan", "Feb", "Mar",
    "Apr", "May", "Jun",
    "Jul", "Aug", "Sep",
    "Oct", "Nov", "Dec"
    };

    return (Months[MonthNumber - 1]);
}

void PrintMonthCalendar(int Year, int Month)
{
    int FirstDayOfMonth = DayOrder(1,Month,Year);
    int NumberOfDays = NumberOfDaysInMonth(Month,Year);

    cout << "_________________________" << MonthShortName(Month) << "_____________________________" << endl;
    printf("Sun \t Mon \t Tue \t Wed \t Thu \t Fri \t Sat \n");

    int i;
    for ( i = 0; i < FirstDayOfMonth; i++)
    {
        cout << " \t ";
    }
    
    for (int j = 1; j <= NumberOfDays; j++)
    {
        cout << j << " \t ";
        if (++i % 7 == 0)
        {
            cout << endl;
        }
    }
}

void PrintMonthCalendar(sDate Date)
{
    PrintMonthCalendar(Date.Year, Date.Month);
}

void PrintYearCalendar(int Year)
{
    cout << "\n_________________________________________________________\n";
    cout << "                      Calendar - " << Year;
    cout << "\n_________________________________________________________\n";


    for (int Month = 1; Month < 12; Month++)
    {
        PrintMonthCalendar(Year,Month);
    }
    
}

void PrintYearCalendar(sDate Date)
{
    PrintYearCalendar(Date.Year);
}

int TotalDaysFromBeginnigOfTheYear(int Day, int Month, int Year)
{
    int NumberOfDays = 0;

    for (int i = 1; i < Month; i++)
    {
        NumberOfDays += NumberOfDaysInMonth(i, Year);
    }

    NumberOfDays += Day;

    return NumberOfDays;
}

int TotalDaysFromBeginnigOfTheYear(sDate Date)
{
    return TotalDaysFromBeginnigOfTheYear(Date.Day, Date.Month, Date.Year);
}

sDate NumberOfDaysToCalendarDay(int NumberOfDays, int Year)
{
    short Month = 1;
    short Day = 0;

    while (NumberOfDays != 0)
    {
        NumberOfDays--;
        Day++;

        if (Day == NumberOfDaysInMonth(Month, Year))
        {
            Month++;
            Day = 0;
        }
    }
    sDate Date;
    Date.Day = Day;
    Date.Month = Month;
    Date.Year = Year;

    return Date;
}

sDate NumberOfDaysToCalendarDay(int NumberOfDays, sDate Date)
{
    return NumberOfDaysToCalendarDay(NumberOfDays, Date.Year);
}

sDate AddDaysToDate(int NumberOfDaysToAdd, sDate Date)
{
    while (NumberOfDaysToAdd != 0)
    {
        NumberOfDaysToAdd--;
        Date.Day++;

        if (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year))
        {
            Date.Month++;
            Date.Day = 0;
        }

        if(Date.Month == 13)
        {
            Date.Year++;
            Date.Month = 1;
        }
        
    }
    
    return Date;
}

bool isDate1BeforeDate2(sDate Date1, sDate Date2)
{
    if (Date1.Year < Date2.Year)
        return true;
    else
    {
        if (Date1.Year == Date2.Year)
        {
            if (Date1.Month < Date2.Month)
                return true;
            else
            {
                if (Date1.Month == Date2.Month)
                {
                    if (Date1.Day < Date2.Day)
                        return true;
                }
            }
        }
    }

    return false;
}

bool isDate1EqualDate2(sDate Date1, sDate Date2)
{
    return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

bool isLastDayInMonth(int Day, int Month, int Year)
{
    return (Day == NumberOfDaysInMonth(Month,Year));
}

bool isLastDayInMonth(sDate Date)
{
    return isLastDayInMonth(Date.Day, Date.Month, Date.Year);
}

bool isLastMonthInYear(int Month)
{
    return (Month == 12);
}

bool isLastMonthInYear(sDate Date)
{
    return isLastMonthInYear(Date.Month);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (isLastDayInMonth(Date.Day, Date.Month, Date.Year))
    {
        if (isLastMonthInYear(Date.Month))
        {
            Date.Day = 1;
            Date.Month = 1;
            Date.Year++;
        }
        else
        {
            Date.Day = 1;
            Date.Month++;
        }
    }
    else
    {
        Date.Day++;
    }
    return Date;
}

int DifferenceBetweenTwoDatesInDays(sDate Date1, sDate Date2, bool IncludeEndDay = false)
{
    int NumberOfDays = 0;

    while (isDate1BeforeDate2(Date1, Date2))
    {
        NumberOfDays++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return (IncludeEndDay ? ++NumberOfDays : NumberOfDays);
}

sDate GetSystemDate()
{
    sDate Date;
    time_t t = time(0);
    tm* now = localtime(&t);
    Date.Year = now->tm_year + 1900;
    Date.Month = now->tm_mon + 1;
    Date.Day = now->tm_mday;
    return Date;
}

int AgeInNumberOfDays(sDate Birthday)
{
    sDate CurrentDay = GetSystemDate();
    return DifferenceBetweenTwoDatesInDays(Birthday, CurrentDay, true);
}

sDate IncreaseDateByXDays(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    
    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
    return IncreaseDateByXDays(Date, 7);
}

sDate IncreaseDateByXWeeks(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }
    
    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 12)
    {
        Date.Year++;
        Date.Month = 1;
    }
    else
        Date.Month++;

    //last check day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate IncreaseDateByXMonths(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
    Date.Year++;
    return Date;
}

sDate IncreaseDateByXYears(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    return Date;
}

sDate IncreaseDateByXYearsFaster(sDate Date, int X)
{
    Date.Year += X;
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
    Date.Year += 10;
    return Date;
}

sDate IncreaseDateByXDecades(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = IncreaseDateByOneDecade(Date);
    }
    return Date;
}

sDate IncreaseDateByXDecadesFaster(sDate Date, int X)
{
    Date.Year += (X * 10);
    return Date;
}

sDate IncreaseDateByOneCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}

sDate IncreaseDateByOneMillennium(sDate Date)
{
    Date.Year += 1000;
    return Date;
}

sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Day = 31;
            Date.Month = 12;
            Date.Year--;
        }
        else
        {
            Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
            Date.Month--;
        }
    }
    else
    {
        Date.Day--;
    }
    return Date;
}

sDate DecreaseDateByXDays(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    return DecreaseDateByXDays(Date, 7);
}

sDate DecreaseDateByXWeeks(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    
    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 1)
    {
        Date.Year--;
        Date.Month = 12;
    }
    else
        Date.Month--;

    //last check day in date should not exceed max days in the current month
    // example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should be 28/2/2022
    short NumberOfDaysInCurrentMonth = NumberOfDaysInMonth(Date.Month, Date.Year);

    if (Date.Day > NumberOfDaysInCurrentMonth)
    {
        Date.Day = NumberOfDaysInCurrentMonth;
    }

    return Date;
}

sDate DecreaseDateByXMonths(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    return Date;
}

sDate DecreaseDateByXYears(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearsFaster(sDate Date, int X)
{
    Date.Year -= X;
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, int X)
{
    for (int i = 0; i < X; i++)
    {
        Date = DecreaseDateByOneDecade(Date);
    }
    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, int X)
{
    Date.Year -= (X * 10);
    return Date;
}

sDate DecreaseDateByOneCentury(sDate Date)
{
    Date.Year -= 100;
    return Date;
}

sDate DecreaseDateByOneMillennium(sDate Date)
{
    Date.Year -= 1000;
    return Date;
}

string DayShortName(short d)
{
    string DayName;
    switch (d)
    {
    case enDayName::Sunday:
        DayName = "Sun";
        break;
    
    case enDayName::Friday:
        DayName = "Fri";
        break;

    case enDayName::Monday:
        DayName = "Mon";
        break;

    case enDayName::Tuesday:
        DayName = "Tue";
        break;

    case enDayName::Wednesday:
        DayName = "Wed";
        break;

    case enDayName::Thursday:
        DayName = "Thu";
        break;

    case enDayName::Saturday:
        DayName = "Sat";
        break;

    default:
        break;
    }
    return DayName;
}

bool isEndOfWeek(sDate Date)
{
    int DayOrd = DayOrder(Date);
    return (DayOrd == 6);
    
}

bool isWeekEnd(sDate Date)
{
    int DayOrd = DayOrder(Date);
    return (DayOrd == 5) || (DayOrd == 6);   
}

bool isBusinessDay(sDate Date)
{
    return !isWeekEnd(Date);
}

int DaysUntilEndOfWeek(sDate Date)
{
    return (6 - DayOrder(Date));
}

int DaysUntilEndOfMonth(sDate Date)
{
    return (NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day);
}

int DaysUntilEndOfYear(sDate Date)
{
    int NumOfDays = DaysUntilEndOfMonth(Date);

    for (int i = Date.Month + 1; i <= 12; i++)
    {
        NumOfDays += NumberOfDaysInMonth(Date.Month, Date.Year);
    }
    return NumOfDays; 
}

int CalculateVacationDays(sDate VacationStart, sDate VacationEnd)
{
    int NumberOfDays = 0;

    while (isDate1BeforeDate2(VacationStart, VacationEnd))
    {
        if (!isWeekEnd(VacationStart))
        {
            NumberOfDays++;
        }
        VacationStart = IncreaseDateByOneDay(VacationStart); 
    }

    return NumberOfDays;
}

sDate CalculateVacationReturnDate(sDate VacationStart, int VacationDays)
{
    while (VacationDays != 0)
    {
        if (isBusinessDay(VacationStart))
        {
            VacationDays--;
        }
        VacationStart = IncreaseDateByOneDay(VacationStart);
    }
    return VacationStart;
}

bool isDate1AfterDate2(sDate Date1, sDate Date2)
{  
   return (!isDate1BeforeDate2(Date1,Date2) && !isDate1EqualDate2(Date1, Date2));
}

short CompareDates(sDate Date1, sDate Date2)
{
    if (isDate1AfterDate2(Date1,Date2))
    {
        return 1;
    }

    if (isDate1BeforeDate2(Date1,Date2))
    {
        return -1;
    }

    if (isDate1EqualDate2(Date1,Date2))
    {
        return 0;
    }
}

struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
};

sPeriod ReadPeriod()
{
    sPeriod Period;

    Period.StartDate = ReadDate();
    Period.EndDate = ReadDate();

    return Period;
}

bool isPeriodsOverlap(sPeriod Period1, sPeriod Period2)
{
    if (CompareDates(Period2.EndDate, Period1.StartDate) == -1 || CompareDates(Period2.StartDate, Period1.EndDate) == 1)
    {
        return false;
    }

    else 
        return true;
   
}

int PeriodLengthInDays(sPeriod Period, bool IncludeEndDay = false)
{
    return DifferenceBetweenTwoDatesInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
}

bool isDateWithinPeriod(sPeriod Period, sDate Date)
{
    return !(CompareDates(Date, Period.StartDate) == -1 || CompareDates(Date, Period.EndDate) == 1);
}

int CountOverlapDaysBetweenTwoPeriods(sPeriod Period1, sPeriod Period2)
{
    if (!isPeriodsOverlap(Period1,Period2))
    {
        return 0;
    }
    
    int NumberOfDays = 0;

    while (isDate1BeforeDate2(Period1.StartDate, Period1.EndDate))
    {
        if (isDateWithinPeriod(Period2, Period1.StartDate))
        {
            NumberOfDays++;
        }

        Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);
        
    }
    
    return NumberOfDays;
}

bool isValidDate(sDate Date)
{
    if (Date.Day < 1 || Date.Day > NumberOfDaysInMonth(Date.Month, Date.Year))
    {
        return false;
    }
    
    if (Date.Month < 1 || Date.Month > 12)
    {
        return false;
    }

    return true;
}

sDate StringToDate(string StringDate)
{
    string tmp[3] = {"","",""};
    int j = 0;

    for (int i = 0; i < StringDate.length(); i++)
    {
        if (StringDate[i] == '/')
        {
            j++;
            continue;
        }

        tmp[j] += StringDate[i];
    }

    sDate Date;
    Date.Day = stoi(tmp[0]);
    Date.Month = stoi(tmp[1]);
    Date.Year = stoi(tmp[2]);

    return Date;
}

string DateToString(sDate Date)
{
    string StringDate = "";
    StringDate += to_string(Date.Day);
    StringDate += '/';
    StringDate += to_string(Date.Month);
    StringDate += '/';
    StringDate += to_string(Date.Year);

    return StringDate;
}
