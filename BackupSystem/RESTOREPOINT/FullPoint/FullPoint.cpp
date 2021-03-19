#include "FullPoint.h"

FullPoint::FullPoint(Backup backup)
{
  for (int i = 0; i < backup.get_backupList().size(); i++)
    this->AddRestoreFile(backup.get_backupList()[i]);
}