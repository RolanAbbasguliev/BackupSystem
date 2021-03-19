#include "RestorePoint.h"
#include <filesystem>
#include <fstream>
int RestorePoint::rid = 0;


long RestorePoint::get_restorePointSize()
{
  return this->restorePointSize;
}

RestorePoint::RestorePoint()
{
  this->id = rid++;
  string str =  "My Point[" + to_string(this->id) + "]" ;
  this->name = str;
  this->restorePointSize = 0;

}

/*
void RestorePoint::PrintRestoreFiles()
{
  for (auto & restoreFile : this->restoreFiles)
    cout << "FILE: " << restoreFile.getPath();
}
*/

void RestorePoint::GetChangeTime(const string &path)
{
  for (int i = 0; i < this->restoreFiles.size(); i++)
  {
    if (restoreFiles[i].get_path() == path)
       restoreFiles[i].FileLastMod();
  }

}

void RestorePoint::set_restorePointSize(long size)
{
  this->restorePointSize = size;
}

vector<FileType> RestorePoint::get_restoreFiles()
{
  return this->restoreFiles;
}

void RestorePoint::AddRestoreFile(FileType file)
{
  this->restoreFiles.push_back(file);
  this->set_restorePointSize(this->get_restorePointSize() + file.get_fileSize());
}



Time RestorePoint::get_creationTime()
{
  return this->creationTime;
}

bool RestorePoint::operator==(const RestorePoint &restorePoint)
{
  bool flag = false;
  if (name == restorePoint.name && id == restorePoint.id && restorePointSize == restorePoint.restorePointSize &&
      creationTime == restorePoint.creationTime && restoreFiles.size() == restorePoint.restoreFiles.size())
  {
     for (int i = 0; i < restoreFiles.size(); i++)
     {
       if (restoreFiles[i] == restorePoint.restoreFiles[i])
       {
         if (i == restoreFiles.size() - 1)
           flag = true;
       }
       flag = false;
     }
  }
  return  flag;
}

void RestorePoint::ArchiveStorage()
{
  static int id;
  string line;

  string archiveName = "Archive[" + to_string(id) + "].txt";
  id++;


  ofstream out_file (archiveName);
  for (int i = 0; i < this->get_restoreFiles().size(); i++)
  {
    ifstream ini_file (this->get_restoreFiles()[i].get_path());

    if (ini_file && out_file)
    {
      while (getline(ini_file, line))
        out_file << line << "\n";
    }
    else
      cout << "Error coppying";
    ini_file.close();
  }
  out_file.close();
}

void RestorePoint::SeparateStorage()
{
  static int id;
  string line;



  for (int i = 0; i < this->get_restoreFiles().size(); i++)
  {
    string copyFile = this->get_restoreFiles()[i].get_path() + "copy[" + to_string(id) + "]";
    id++;

    ofstream out_file (copyFile);
    ifstream ini_file (this->get_restoreFiles()[i].get_path());
    if (ini_file && out_file)
    {
      while (getline(ini_file, line))
        out_file << line << "\n";
    }
    else
      cout << "Error coppying";
    ini_file.close();
    out_file.close();
  }



}

string RestorePoint::get_name()
{
  return this->name;
}

