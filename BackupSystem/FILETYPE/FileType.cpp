#include "FileType.h"
#include <filesystem>
#include <iostream>
using namespace std;


#include "FileType.h"

FileType::FileType(const char *path)
{
  this->path = path;
  if (stat(path, &fileInfo) != 0)
    return;

  this->fileTime = Time();
  this->fileModTime = fileTime;
  this->fileSize = this->get_fileSize();


}

long FileType::get_fileSize()
{
  struct stat stat_buf;
  int rc = stat(this->path.c_str(), &stat_buf);
  return rc == 0 ? stat_buf.st_size : -1;
}

vector<string> FileType::ParsFileTimeInfo()
{
  vector <string> timeInfo;

  string param;
  char *fileTime = ctime(&fileInfo.st_mtime);
  string fileTimeStr = string(fileTime);

  for (auto x : fileTimeStr)
  {
    if (x == ' ')
    {
      timeInfo.push_back(param);
      param = "";
    }
    else
    {
      param += x;
    }
  }
  timeInfo.push_back(param);

  return timeInfo;
}

void FileType::FileLastMod()
{
  vector <string> pars = ParsFileTimeInfo();

  //set Month;
  if (pars[1] == "Sep")
    this->fileModTime.setMonth(9);
  else if(pars[1] == "Oct")
    this->fileModTime.setMonth(10);
  else if(pars[1] == "Nov")
    this->fileModTime.setMonth(11);
  else if(pars[1] == "Dec")
    this->fileModTime.setMonth(12);
  else if(pars[1] == "Jan")
    this->fileModTime.setMonth(1);
  else if (pars[1] == "Feb")
    this->fileModTime.setMonth(2);
  else if (pars[1] == "Mar")
    this->fileModTime.setMonth(3);
  else if (pars[1] == "Apr")
    this->fileModTime.setMonth(4);
  else if (pars[1] == "May")
    this->fileModTime.setMonth(5);
  else if (pars[1] == "Jun")
    this->fileModTime.setMonth(6);
  else if (pars[1] == "Jul")
    this->fileModTime.setMonth(7);
  else if (pars[1] == "Aug")
    this->fileModTime.setMonth(8);


  //set Day
  this->fileModTime.setDay(stoi(pars[2]));

  //set Year
  this->fileModTime.setYear(stoi(pars[4]));

  //set Hour
  this->fileModTime.setHour(stoi(pars[3].substr(0,2)));

  //set Min
  this->fileModTime.setMin(stoi(pars[3].substr(3,2)));

  //set Sec
  this->fileModTime.setSec(stoi(pars[3].substr(6,2)));
}

string FileType::get_path()
{
  return this->path;
}


int get_file_size(std::string filename) // path to file
{
  FILE *p_file = NULL;
  p_file = fopen(filename.c_str(),"rb");
  fseek(p_file,0,SEEK_END);
  int size = ftell(p_file);
  fclose(p_file);
  return size;
}

void FileType::FileWrite(string text)
{
  ofstream fout(this->path);
  fout << text;
  fout.close();
  FileLastMod();
  this->isMod = true;
  this->fileSize = this->get_fileSize();
}

Time& FileType::get_fileModTime()
{
  return this->fileModTime;
}

bool FileType::operator==(const FileType &file)
{
  if (path == file.path && fileModTime == file.fileModTime && fileSize == file.fileSize && fileTime == file.fileTime)
    return true;
  return false;
}

Time& FileType::get_fileTime()
{
  return this->fileTime;
}

