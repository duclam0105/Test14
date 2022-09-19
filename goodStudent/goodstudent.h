#ifndef __GOOD_H
#define __GOOD_H

#include "student.h"

class GoodStudent : public Student {
    float gpa;
    string bestRewardName;
public:
    void setGPA(const float&);
    void setBestReward(const string&);
    float getGPA();
    string getBestReward();
    void insertData();
    void showInfo();
    bool operator < (GoodStudent another);
};

#endif // !__GOOD_H
