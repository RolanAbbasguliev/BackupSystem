#include "Backup.h"

int Backup::bid = 0;
Backup::Backup(vector <FileType>  fileList)
{
  this->id = bid++;
  this->backupList = std::move(fileList);
  this->creationTime = Time();
}



void Backup::BackupUpdateList(vector<FileType> &fileList)
{
  this->backupList = std::move(fileList);
}

int Backup::get_id()
{
  return this->id;
}

Time Backup::get_creationTime()
{
  return this->creationTime;
}

vector<FileType> &Backup::get_backupList()
{
  return this->backupList;
}

int Backup::get_backupSize()
{
  return this->backupSize;
}

int Backup::get_pointListSize()
{
  return this->pointList.size();
}

void Backup::AddFile(const FileType& file)
{
  backupList.push_back(file);
}

void Backup::RemoveFile(FileType file)
{
  for (int i = 0; i < backupList.size(); i++)
  {
    if (file.get_path() == backupList[i].get_path())
    {
      backupList[i] = backupList.back();
      backupList.pop_back();
      i--;
    }
  }
}

void Backup::BackupResize()
{
  long size = 0;
  for (auto & i : pointList)
    size += i.get_restorePointSize();
  this->backupSize = size;
}

vector<RestorePoint>& Backup::get_pointList()
{
  return pointList;
}

void Backup::RemovePoint(RestorePoint point)
{
  for (int i = 0; i < this->pointList.size(); i++)
  {
    if (this->pointList[i] == point)
    {
      pointList[i] = pointList.back();
      pointList.pop_back();
      i--;
      this->BackupResize();
    }
  }

}

void Backup::AddPoint(RestorePoint& point)
{
  this->backupSize += point.get_restorePointSize();
  this->pointList.push_back(point);
}

