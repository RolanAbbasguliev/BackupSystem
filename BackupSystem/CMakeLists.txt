cmake_minimum_required(VERSION 3.17)
project(BackupSystem)

set(CMAKE_CXX_STANDARD 14)

add_executable(BackupSystem main.cpp TIME/Time.cpp TIME/Time.h FILETYPE/FileType.cpp FILETYPE/FileType.h BACKUP/Backup.cpp BACKUP/Backup.h RESTOREPOINT/RestorePoint.cpp RESTOREPOINT/RestorePoint.h RESTOREPOINT/FullPoint/FullPoint.cpp RESTOREPOINT/FullPoint/FullPoint.h RESTOREPOINT/DeltaPoint/DeltaPoint.cpp RESTOREPOINT/DeltaPoint/DeltaPoint.h RESTOREPOINT/RestorePointSelector.cpp RESTOREPOINT/RestorePointSelector.h RESTOREPOINT/PointManager.cpp RESTOREPOINT/PointManager.h BACKUP/BackupManager.cpp BACKUP/BackupManager.h CLEANER/Cleaner.cpp CLEANER/Cleaner.h CLEANER/CleanerSelector.cpp CLEANER/CleanerSelector.h TIME/Time.cpp)