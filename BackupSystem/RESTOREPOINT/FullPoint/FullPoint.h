#ifndef BACKUPSYSTEM_FULLPOINT_H
#define BACKUPSYSTEM_FULLPOINT_H

#include "../../BACKUP/Backup.h"

class FullPoint : public RestorePoint
{
public:
  FullPoint(Backup backup);
};

#endif
