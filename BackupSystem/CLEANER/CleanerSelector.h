#ifndef BACKUPSYSTEM_CLEANERSELECTOR_H
#define BACKUPSYSTEM_CLEANERSELECTOR_H

#include "Cleaner.h"

enum cleanType
{
  COUNT = 1,
  DATE = 2,
  SIZE = 3
};

class CleanerSelector
{
public:
  static Cleaner* cleanPoint(Backup &backup, vector<int> cleanType);
};

#endif //BACKUPSYSTEM_CLEANERSELECTOR_H
