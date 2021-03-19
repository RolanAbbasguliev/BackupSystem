#include "BackupManager.h"

#include <utility>
#include "../CLEANER/CleanerSelector.h"

Backup BackupManager::BackupCreate(Backup backup)
{
  return Backup(backup.get_backupList());
}

void BackupManager::PointCreate(Backup *backup, bool pointType, bool storageType)  //storageType = true - Archive, else Separate
{
  if (backup->get_pointList().empty() && !pointType)
    throw ("First Point should be FullType");

  RestorePoint *point;
  PointManager pointManager;

  point = pointManager.CreatePoint(pointType, *backup);
  backup->AddPoint(*point);

  if (storageType)
    point->ArchiveStorage();
  else
    point->SeparateStorage();
}

void BackupManager::PointCleaner(Backup *backup, vector<int> cleanType)
{
  CleanerSelector cleanerSelector;
  cleanerSelector.cleanPoint(*backup, std::move(cleanType));
  //cleaner.Clean(backup);
}

