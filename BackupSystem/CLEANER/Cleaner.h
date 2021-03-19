#ifndef BACKUPSYSTEM_CLEANER_H
#define BACKUPSYSTEM_CLEANER_H

#include "../BACKUP/BackupManager.h"

class Cleaner
{
public:
  virtual void Clean(Backup &backup) = 0;
};


class CountClean : public Cleaner
{
private:
  int limit;
public:
  CountClean(int limit);
  void Clean(Backup &backup) override;
};

// Clean by date
class  DateClean : public Cleaner
{
private:
  Time time;
public:
  DateClean(Time time);
  void Clean(Backup &backup) override;
};


// Clean by storage size
class SizeClean : public Cleaner
{
private:
  long size;
public:
  SizeClean(long size);
  void Clean(Backup &backup) override;
};



#endif //BACKUPSYSTEM_CLEANER_H
