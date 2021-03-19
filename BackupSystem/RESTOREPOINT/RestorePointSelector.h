#ifndef BACKUPSYSTEM_RESTOREPOINTSELECTOR_H
#define BACKUPSYSTEM_RESTOREPOINTSELECTOR_H

#include "DeltaPoint/DeltaPoint.h"
#include "FullPoint/FullPoint.h"


class RestorePointSelector
{
public:
  static RestorePoint* createPoint(bool type, Backup backup);
};

#endif //BACKUPSYSTEM_RESTOREPOINTSELECTOR_H
