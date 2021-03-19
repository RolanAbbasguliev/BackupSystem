#include "PointManager.h"

#include <utility>

RestorePoint* PointManager::CreatePoint(bool type, Backup backup)
{
  RestorePoint *restorePoint = RestorePointSelector::createPoint(type, std::move(backup));
  return restorePoint;
}

