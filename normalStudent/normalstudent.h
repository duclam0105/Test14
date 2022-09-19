#ifndef __NORMAL_H
#define __NORMAL_H

#include "student.h"

class NormalStudent : public Student {
    int englishScore;
    float entryTestScore;
public:
    void setEnglishScore(const int&);
    void setEntryScore(const float&);
    int getEnglishScore();
    float getEntryScore();
    void insertData();
    void showInfo();
    bool operator < (NormalStudent another);
};

#endif // !__NORMAL_H
