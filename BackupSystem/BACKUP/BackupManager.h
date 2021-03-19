#ifndef BACKUPSYSTEM_BACKUPMANAGER_H
#define BACKUPSYSTEM_BACKUPMANAGER_H


#include <utility>

#include "../RESTOREPOINT/PointManager.h"
#include "../CLEANER/Cleaner.h"

class BackupManager
{
public:

  Backup BackupCreate(Backup backup);
  void PointCreate(Backup *backup, bool pointType, bool storageType);  //true - full, false - separate
  void PointCleaner(Backup *backup, vector<int> cleanType);

};

#endif //BACKUPSYSTEM_BACKUPMANAGER_H
