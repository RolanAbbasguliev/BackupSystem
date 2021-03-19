#ifndef BACKUPSYSTEM_DELTAPOINT_H
#define BACKUPSYSTEM_DELTAPOINT_H


#include "../../BACKUP/Backup.h"
class DeltaPoint : public RestorePoint
{
public:
  DeltaPoint(Backup *backup);
};

#endif //BACKUPSYSTEM_DELTAPOINT_H
