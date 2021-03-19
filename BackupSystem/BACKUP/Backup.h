#ifndef BACKUPSYSTEM_BACKUP_H
#define BACKUPSYSTEM_BACKUP_H

#include <fstream>
#include <string>

#include "../FILETYPE/FileType.h"
#include "../RESTOREPOINT/RestorePoint.h"

using namespace std;

class Backup
{
private:
  vector<FileType> backupList;
  int id = 0;
  static int bid;
  Time creationTime;
  long backupSize = 0;
  vector<RestorePoint> pointList;

public:

  Backup(vector <FileType> fileList);
  int get_id();
  Time get_creationTime();
  vector<FileType> &get_backupList();
  vector<RestorePoint> &get_pointList();
  int get_backupSize();
  int get_pointListSize();

  void BackupUpdateList(vector <FileType> &fileList);


  void AddFile(const FileType& file);
  void RemoveFile(FileType file);
  void BackupResize();   //Counting Current PointList and adding to backupSize var;
  void RemovePoint(RestorePoint point);
  void AddPoint(RestorePoint& point);
};




#endif //BACKUPSYSTEM_BACKUP_H
