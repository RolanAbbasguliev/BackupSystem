#include "RestorePointSelector.h"

RestorePoint *RestorePointSelector::createPoint(bool type, Backup backup)
{
  RestorePoint *restorePoint = nullptr;
  if (type)
    restorePoint = new FullPoint(backup);
  else
    restorePoint = new DeltaPoint(&backup);
  return restorePoint;
}
