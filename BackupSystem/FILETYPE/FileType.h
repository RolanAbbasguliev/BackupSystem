#ifndef BACKUPSYSTEM_FILETYPE_H
#define BACKUPSYSTEM_FILETYPE_H

#include "../TIME/Time.h"
#include <iostream>
#include <string>
#include <fstream>
#include <utility>
#include <sys/stat.h>
#include <vector>


using namespace std;

class FileType
{
private:
  string path;
  Time fileTime;
  Time fileModTime;  //last modification parameter
  struct stat fileInfo;
  long fileSize;

public:
  bool isMod = false;
  string message;
  string get_path();
  Time& get_fileModTime();
  Time& get_fileTime();


  FileType(const char *path);
  long get_fileSize();
  vector<string> ParsFileTimeInfo();
  void FileLastMod();
  void FileWrite(string text);

  bool operator==(const FileType &file);

};


#endif //BACKUPSYSTEM_FILETYPE_H
