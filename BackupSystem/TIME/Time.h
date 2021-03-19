#ifndef BACKUPSYSTEM_TIME_H
#define BACKUPSYSTEM_TIME_H



#include <ctime>
#include <iostream>
using namespace std;

class Time
{
private:
  int Day = 0, Month = 0, Year = 0;
  int Hour = 0, Min = 0, Sec = 0;
public:
  Time();



  void FileNull();


  int getDay();
  void setDay(int day);

  int getMonth();
  void setMonth(int month);

  int getYear();
  void setYear(int year);

  int getHour();
  void setHour(int hour);

  int getMin();
  void setMin(int min);

  int getSec();
  void setSec(int sec);



  bool operator==(const Time &f);
  bool operator!=(const Time &f);
  Time& operator=(const Time &f);
  bool operator<(const Time &f);
  bool operator<=(const Time &f);
  bool operator>(const Time &f);
  bool operator>=(const Time &f);
};

#endif //BACKUPSYSTEM_TIME_H
