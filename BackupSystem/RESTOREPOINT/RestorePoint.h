#ifndef BACKUPSYSTEM_RESTOREPOINT_H
#define BACKUPSYSTEM_RESTOREPOINT_H

#include <string>
#include "../FILETYPE/FileType.h"

class RestorePoint
{
private:
  string name;
  int id = 0;
  static int rid;
  long restorePointSize = 0;
  Time creationTime;
  vector<FileType> restoreFiles;
public:
  RestorePoint();
  void set_restorePointSize( long size );
  vector<FileType> get_restoreFiles();
  long get_restorePointSize();
  string get_name();

  Time get_creationTime();
  void GetChangeTime(const string& path);

  void AddRestoreFile(FileType file);
  bool operator==(const RestorePoint &restorePoint);

  void ArchiveStorage();
  void SeparateStorage();
};


#endif //BACKUPSYSTEM_RESTOREPOINT_H
