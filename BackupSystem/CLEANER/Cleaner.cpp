#include "Cleaner.h"

// Count Cleaner
CountClean::CountClean(int limit)
{
  this->limit = limit;
}


template<typename T>
void pop_front(std::vector<T>& vec)
{
  assert(!vec.empty());
  vec.erase(vec.begin());
}

void CountClean::Clean(Backup &backup)
{
  while (backup.get_pointList().size() > this->limit)
  {
    pop_front(backup.get_pointList());
    backup.BackupResize();
  }
}


//Date Cleaner

DateClean::DateClean(Time time)
{
  this->time = time;
}


void DateClean::Clean(Backup &backup)
{
  int i = 0;
  while (i < backup.get_pointListSize())
  {
    if (backup.get_pointList()[i].get_creationTime() > this->time)
      backup.RemovePoint(backup.get_pointList()[i]);
    else
      i++;
  }
}


SizeClean::SizeClean(long size)
{
  this->size = size;
}

void SizeClean::Clean(Backup &backup)
{
  while (backup.get_backupSize() > this->size)
  {
    backup.get_pointList().pop_back();
    backup.BackupResize();
  }
}
