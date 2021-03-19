#include <iostream>

#include "RESTOREPOINT/PointManager.h"
#include "BACKUP/BackupManager.h"
#include "CLEANER/CleanerSelector.h"

class Test
{
public:
  void Case1()
  {
    bool pointType = true, storageType = true;
    vector<int> cleanType = {COUNT};

    FileType file1("Test1");
    FileType file2("Test2");
    vector<FileType> fileList = {file1, file2};

    Backup backup(fileList);
    BackupManager backupManager;
    backupManager.BackupCreate(backup);
    backupManager.PointCreate(&backup, pointType, storageType);
    backupManager.PointCreate(&backup, pointType, storageType);
    cout << "CHAIN SIZE: " << backup.get_pointListSize() << endl;
    backupManager.PointCleaner(&backup, cleanType);
    cout << "CHAIN SIZE: " << backup.get_pointListSize() << endl;
    cout << "BACKUP SIZE: " << backup.get_backupSize();
  }
  void Case2()
  {
    bool pointType = true, storageType = true;
    vector<int> cleanType = {SIZE};

    FileType file1("test100");
    FileType file2("test100");
    vector<FileType> fileList = {file1, file2};


    Backup backup(fileList);

    BackupManager backupManager;
    backupManager.BackupCreate(backup);

    backupManager.PointCreate(&backup, pointType, storageType);
    cout << "CHAIN SIZE: " << backup.get_pointList().size() << endl;
    cout << "BACKUP SIZE: " << backup.get_backupSize() << endl;


    backupManager.PointCreate(&backup, pointType, storageType);
    cout << "CHAIN SIZE: " << backup.get_pointList().size() << endl;
    cout << "BACKUP SIZE: " << backup.get_backupSize() << endl;

    backupManager.PointCleaner(&backup, cleanType);
    cout << "CHAIN SIZE: " << backup.get_pointList().size() << endl;
    cout << "BACKUP SIZE: " << backup.get_backupSize() << endl;
  }
  void Case3()
  {
    bool pointType = true, storageType = true;
    vector<int> cleanType = {SIZE};

    FileType file1("Test1");
    FileType file2("Test2");
    vector<FileType> fileList = {file1, file2};


    Backup backup(fileList);

    BackupManager backupManager;
    backupManager.BackupCreate(backup);
    backupManager.PointCreate(&backup, pointType, storageType);


    file1.FileWrite("ADdADADFDF");
    vector<FileType> fileList2 = {file1, file2};

    backup.BackupUpdateList(fileList2);
    pointType = false;
    backupManager.PointCreate(&backup, pointType, storageType);
  }
  void Case4()
  {
    bool pointType = true, storageType = true;
    vector<int> cleanType = {SIZE, COUNT};

    FileType file1("Test1");
    FileType file2("Test2");
    FileType file3("Test3");
    vector<FileType> fileList = {file1, file2};


    Backup backup(fileList);
    backup.AddFile(file3);

    BackupManager backupManager;
    backupManager.BackupCreate(backup);
    backupManager.PointCreate(&backup, pointType, storageType);
    backupManager.PointCreate(&backup, pointType, storageType);
    backupManager.PointCleaner(&backup, cleanType);
    cout << "CHAIN SIZE: " << backup.get_pointList().size() << endl;


  }
};

int main()
{
  Test test;
  test.Case1();
  test.Case2();
  test.Case3();
  test.Case4();

  return 0;
}
