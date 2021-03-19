#ifndef BACKUPSYSTEM_POINTMANAGER_H
#define BACKUPSYSTEM_POINTMANAGER_H

#include "RestorePointSelector.h"

class PointManager
{
public:
  RestorePoint* CreatePoint(bool type, Backup backup);

};

#endif //BACKUPSYSTEM_POINTMANAGER_H
