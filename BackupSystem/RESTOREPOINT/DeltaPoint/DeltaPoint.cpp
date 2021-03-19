#include "DeltaPoint.h"


DeltaPoint::DeltaPoint(Backup *backup)
{

  for (int i = 0; i < backup->get_backupList().size(); i++)
  {
    if (backup->get_backupList()[i].isMod)
      this->AddRestoreFile(backup->get_backupList()[i]);

  }
  /*for (int i = 0; i < backup.get_backupList().size(); i++)
  {
    Time lastChange;
    Time *p = &lastChange;

    for (int j = 0; j < backup.get_pointList().size(); j++)
    {

      Time *date = backup.get_pointList()[j].get_restoreFiles()[i].FileLastMod();
      if (date == nullptr && date > p)
        p = date;
    }
    //check if true;
    if (p != backup.get_backupList()[i].FileLastMod())
      this->AddRestoreFile(backup.get_backupList()[i]);
  }*/
}


