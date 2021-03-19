#include "Time.h"

Time::Time()
{
  time_t t = time(nullptr);

  tm* now = localtime(&t);

  this->Year = now->tm_year + 1900;
  this->Month = now->tm_mon + 1;
  this->Day = now->tm_mday;

  this->Hour = now->tm_hour;
  this->Min = now->tm_min;
  this->Sec = now->tm_sec;
}

int Time::getDay()
{
  return this->Day;
}
int Time::getMonth()
{
  return this->Month;
}
int Time::getYear()
{
  return this->Year;
}
int Time::getHour()
{
  return this->Hour;
}
int Time::getMin()
{
  return this->Min;
}
int Time::getSec()
{
  return this->Sec;
}

bool Time::operator==(const Time &f)
{
  if (f.Year == this->Year && f.Month == this->Month && f.Day == this->Day &&
      f.Hour == this->Hour && f.Min== this->Min && f.Sec == this->Sec)
    return true;
  return false;
}

bool Time::operator!=(const Time &f)
{
  if (f.Year != this->Year || f.Month != this->Month || f.Day != this->Day ||
      f.Hour != this->Hour || f.Min != this->Min || f.Sec != this->Sec)
    return true;
  return false;
}




Time &Time::operator=(const Time &f)
{
  this->Year = f.Year;
  this->Month = f.Month;
  this->Day = f.Day;

  this->Hour = f.Hour;
  this->Min = f.Min;
  this->Sec = f.Sec;

  return *this;
}



bool Time::operator<(const Time &f)
{
  if (this->Year < f.Year)
    return true;
  else if (this->Year > f.Year)
    return false;
  else
  {
    if (this->Month < f.Month)
      return true;
    else if (this->Month > f.Month)
      return false;
    else
    {
      if (this->Day < f.Day)
        return true;
      else if (this->Day > f.Day)
        return false;
      else
      {
        if (this->Hour < f.Hour)
          return true;
        else if(this->Hour > f.Hour)
          return false;
        else
        {
          if (this->Min < f.Min)
            return true;
          else if (this->Min > f.Min)
            return false;
          else
          {
            if (this->Sec < f.Sec)
              return true;
            else if (this->Sec > f.Sec)
              return false;
          }
        }
      }
    }
  }
  return true;
}

bool Time::operator>(const Time &f)
{
  if (*this < f)
    return false;
  return true;
}

bool Time::operator<=(const Time &f)
{
  if (*this < f || *this == f)
    return true;
  else
    return false;
}

bool Time::operator>=(const Time &f)
{
  if (*this > f || *this == f)
    return true;
  return false;
}

void Time::setDay(int day)
{
  this->Day = day;
}

void Time::setMonth(int month)
{
  this->Month = month;
}

void Time::setYear(int year)
{
  this->Year = year;
}

void Time::setHour(int hour)
{
  this->Hour = hour;
}

void Time::setMin(int min)
{
  this->Min = min;
}

void Time::setSec(int sec)
{
  this->Sec = sec;
}




