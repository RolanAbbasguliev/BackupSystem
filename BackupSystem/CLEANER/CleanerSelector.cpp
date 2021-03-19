//
// Created by Rolan Abbasguliev on 19.03.2021.
//

#include "CleanerSelector.h"

Cleaner *CleanerSelector::cleanPoint(Backup &backup, vector<int> cleanType)
{
  Cleaner *cleaner;

  int N = 0;
  long size = 0;
  int time = 0;
  Time t;

  for (int i = 0; i < cleanType.size(); i++)
  {
    switch (cleanType[i])
    {
      case COUNT:
        cout << "Input chain size: ";
        cin >> N;
        cleaner = new CountClean(N);
        cleaner->Clean(backup);
        break;
      case DATE:
        cout << "Input time: ";
        cin >> time;
        t.setDay(time);
        cleaner = new DateClean(t);
        cleaner->Clean(backup);
        break;
      case SIZE:
        cout << "Input size backup limit: ";
        cin >> size;
        cleaner = new SizeClean(size);
        cleaner->Clean(backup);
        break;
      default:
        cleaner = nullptr;
        break;
    }
  }
  return cleaner;
}
