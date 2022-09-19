#ifndef __STUDENT_H
#define __STUDENT_H

#include "Lib.h"

class Student {
    string fullName;
    string DoB;
    gender sex;
    string phoneNumber;
    string univerName;
    level gradeLevel;
public:
    int STT;
    virtual ~Student(){}
    void setFullName(const string&);
    void setDoB(const string&);
    void setGender(const gender&);
    void setPhone(const string&);
    void setUniver(const string&);
    void setLevel(const level&);
    string getFullName();
    string getDoB();
    gender getSex();
    string getPhone();
    string getUniver();
    level getLevel();
    virtual void insertData();
    virtual void showInfo();
    /*virtual bool operator < (Student another);*/
};

#endif // !__STUDENT_H
