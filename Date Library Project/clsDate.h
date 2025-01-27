#pragma warning(disable : 4996)
#pragma once

#include<iostream>
#include<ctime>
using namespace std;

class clsDate
{
    private:
        short _Day = 1;
        short _Month = 1;
        short _Year = 1900;
        
    public:
        clsDate()
        {
            time_t t = time(0);
            tm* now = localtime(&t);

            _Year = now->tm_year + 1900;
            _Month = now->tm_mon + 1;
            _Day = now->tm_mday;
        }

        clsDate(short Day, short Month, short Year)
        {
            _Day = Day;
            _Month = Month;
            _Year = Year;
        }

        clsDate(string StringDate)
        {
            clsDate Date = StringToDate(StringDate);
    
            _Day = Date.Day;
            _Month = Date.Month;
            _Year = Date.Year;
        }

        clsDate(short NumberOfDays, short Year)
        {
            clsDate Date = NumberOfDaysToCalendarDay(NumberOfDays, Year);

            _Day = Date.Day;
            _Month = Date.Month;
            _Year = Date.Year;
        }

        void SetDay(short Day)
        {
            _Day = Day;
        }
        short GetDay()
        {
            return _Day;
        }
        __declspec(property(get = GetDay, set = SetDay)) short Day;

        void SetMonth(short Month)
        {
            _Month = Month;
        }
        short GetMonth()
        {
            return _Month;
        }
        __declspec(property(get = GetMonth, set = SetMonth)) short Month;

        void SetYear(short Year)
        {
            _Year = Year;
        }
        short GetYear()
        {
            return _Year;
        }
        __declspec(property(get = GetYear, set = SetYear)) short Year;

        void Print()
        {
            clsDate Date;
            Date.Day = _Day;
            Date.Month = _Month;
            Date.Year = _Year;

            cout << DateToString(Date) << endl;
        }

        static clsDate GetSystemDate()
        {
            time_t t = time(0);
            tm* now = localtime(&t);

            short Year, Month, Day;

            Year = now->tm_year + 1900;
            Month = now->tm_mon + 1;
            Day = now->tm_mday;

            return clsDate(Day, Month, Year);
        }

        static bool isValidDate(clsDate Date)
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

        bool isValid()
        {
            return isValidDate(*this);
        }

        static clsDate StringToDate(string StringDate)
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

            clsDate Date;
            Date.Day = stoi(tmp[0]);
            Date.Month = stoi(tmp[1]);
            Date.Year = stoi(tmp[2]);

            return Date;
        }

        static string DateToString(clsDate Date)
        {
            string StringDate = "";
            StringDate += to_string(Date.Day);
            StringDate += '/';
            StringDate += to_string(Date.Month);
            StringDate += '/';
            StringDate += to_string(Date.Year);

            return StringDate;
        }

        string DateToString()
        {
            return DateToString(*this);
        }

        static bool isLeapYear(int Year)
        {
            return ((Year % 4 == 0) && (Year % 100 != 0)) || (Year % 400 == 0);
        }

        bool isLeapYear()
        {
            return isLeapYear(_Year);
        }

        static int NumberOfDaysInMonth(int Month, int Year)
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

        int NumberOfDaysInMonth()
        {
            return NumberOfDaysInMonth(_Month, _Year);
        }

        static short DayOrder(int Day, int Month, int Year)
        {
            int a = (14 - Month) / 12;
            int y = Year - a;
            int m = Month + 12 * a - 2;
            //Gregorian Calendar:
            int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m) / 12) % 7;
            //Sun=0, Mon=1, Tue=2 ...
            return d;
        }

        static short DayOrder(clsDate Date)
        {
            return DayOrder(Date.Day, Date.Month, Date.Year);
        }

        short DayOrder()
        {
            return(DayOrder(*this));
        }

        enum enDayName { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

        static string DayShortName(clsDate Date)
        {
            short d = DayOrder(Date.Day, Date.Month, Date.Year);
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

        string DayShortName()
        {
            return DayShortName(*this);
        }

        static string MonthShortName(short MonthNumber)
        {
            string Months[12] = { "Jan", "Feb", "Mar",
            "Apr", "May", "Jun",
            "Jul", "Aug", "Sep",
            "Oct", "Nov", "Dec"
            };

            return (Months[MonthNumber - 1]);
        }

        string MonthShortName()
        {
            return MonthShortName(_Month);
        }

        static void PrintMonthCalendar(int Year, int Month)
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

        void PrintMonthCalendar()
        {
            PrintMonthCalendar(_Year, _Month);
        }

        static void PrintYearCalendar(int Year)
        {
            cout << "\n_________________________________________________________\n";
            cout << "                      Calendar - " << Year;
            cout << "\n_________________________________________________________\n";

            for (int Month = 1; Month < 12; Month++)
            {
                PrintMonthCalendar(Year, Month);
            }
            
        }

        void PrintYearCalendar()
        {
            PrintYearCalendar(_Year);
        }

        static int TotalDaysFromBeginnigOfTheYear(int Day, int Month, int Year)
        {
            int NumberOfDays = 0;

            for (int i = 1; i < Month; i++)
            {
                NumberOfDays += NumberOfDaysInMonth(i, Year);
            }

            NumberOfDays += Day;

            return NumberOfDays;
        }

        int TotalDaysFromBeginnigOfTheYear()
        {
            return TotalDaysFromBeginnigOfTheYear(_Day, _Month, _Year);
        }

        static clsDate NumberOfDaysToCalendarDay(int NumberOfDays, int Year)
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
            clsDate Date;
            Date.Day = Day;
            Date.Month = Month;
            Date.Year = Year;

            return Date;
        }

        static void AddDaysToDate(int NumberOfDaysToAdd, clsDate &Date)
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
            
            //return Date;
        }

        void AddDaysToDate(int NumberOfDaysToAdd)
        {
            AddDaysToDate(NumberOfDaysToAdd, *this);
        }

        static bool isDate1BeforeDate2(clsDate Date1, clsDate Date2)
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

        bool isBeforeDate2(clsDate Date2)
        {
            return isDate1BeforeDate2(*this, Date2);
        }

        static bool isDate1EqualDate2(clsDate Date1, clsDate Date2)
        {
            return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
        }

        bool isEqualDate2(clsDate Date2)
        {
            return isDate1EqualDate2(*this, Date2);
        }

        static bool isDate1AfterDate2(clsDate Date1, clsDate Date2)
        {  
            return (!isDate1BeforeDate2(Date1,Date2) && !isDate1EqualDate2(Date1, Date2));
        }

        bool isAfterDate2(clsDate Date2)
        {
            return isDate1AfterDate2(*this, Date2);
        }

        static short CompareDates(clsDate Date1, clsDate Date2)
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

        static bool isLastDayInMonth(clsDate Date)
        {
            return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
        }

        bool isLastDayInMonth()
        {
            return isLastDayInMonth(*this);
        }

        static void IncreaseDateByOneDay(clsDate &Date)
        {
            if (isLastDayInMonth(Date))
            {
                if (Date.Month == 12)
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
            //return Date;
        }

        void IncreaseDateByOneDay()
        {
            IncreaseDateByOneDay(*this);
        }

        static void DecreaseDateByOneDay(clsDate &Date)
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
            //return Date;
        }

        void DecreaseDateByOneDay()
        {
            DecreaseDateByOneDay(*this);
        }

        static int DifferenceBetweenTwoDatesInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay = false)
        {
            int NumberOfDays = 0;

            while (isDate1BeforeDate2(Date1, Date2))
            {
                NumberOfDays++;
                IncreaseDateByOneDay(Date1);
            }

            return (IncludeEndDay ? ++NumberOfDays : NumberOfDays);
        }

        static int CalculateAgeInNumberOfDays(clsDate Birthday)
        {
            clsDate CurrentDay = GetSystemDate();
            return DifferenceBetweenTwoDatesInDays(Birthday, CurrentDay, true);
        }

        static bool isEndOfWeek(clsDate Date)
        {
            int DayOrd = DayOrder(Date);
            return (DayOrd == 6);
        }

        bool isEndOfWeek()
        {
            return isEndOfWeek(*this);
        }

        static bool isWeekEnd(clsDate Date)
        {
            int DayOrd = DayOrder(Date);
            return (DayOrd == 5) || (DayOrd == 6);   
        }

        bool isWeekEnd()
        {
            return isWeekEnd(*this);
        }

        static bool isBusinessDay(clsDate Date)
        {
            return !isWeekEnd(Date);
        }

        bool isBusinessDay()
        {
            return isBusinessDay(*this);
        }

        static int DaysUntilEndOfWeek(clsDate Date)
        {
            return (6 - DayOrder(Date));
        }

        int DaysUntilEndOfWeek()
        {
            return DaysUntilEndOfWeek(*this);
        }

        static int DaysUntilEndOfMonth(clsDate Date)
        {
            return (NumberOfDaysInMonth(Date.Month, Date.Year) - Date.Day);
        }

        int DaysUntilEndOfMonth()
        {
            return DaysUntilEndOfMonth(*this);
        }

        static int DaysUntilEndOfYear(clsDate Date)
        {
            int NumOfDays = DaysUntilEndOfMonth(Date);

            for (int i = Date.Month + 1; i <= 12; i++)
            {
                NumOfDays += NumberOfDaysInMonth(Date.Month, Date.Year);
            }
            return NumOfDays; 
        }

        int DaysUntilEndOfYear()
        {
            return DaysUntilEndOfYear(*this);
        }
 
        static int CalculateVacationDays(clsDate VacationStart, clsDate VacationEnd)
        {
            int NumberOfDays = 0;

            while (isDate1BeforeDate2(VacationStart, VacationEnd))
            {
                if (!isWeekEnd(VacationStart))
                {
                    NumberOfDays++;
                }
                IncreaseDateByOneDay(VacationStart); 
            }

            return NumberOfDays;
        }

        static clsDate CalculateVacationReturnDate(clsDate VacationStart, int VacationDays)
        {
            while (VacationDays != 0)
            {
                if (isBusinessDay(VacationStart))
                {
                    VacationDays--;
                }
                IncreaseDateByOneDay(VacationStart);
            }
            return VacationStart;
        }

};