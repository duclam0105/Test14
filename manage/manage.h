#ifndef __MANAGE_H
#define __MANAGE_H

#include "Lib.h"
#include "student.h"
#include "goodstudent.h"
#include "normalstudent.h"
#include "exception.h"

class Manage {
    vector<shared_ptr<Student>> v;
    int numberGoodStudent = 0;
    int numberNormalStudent = 0;
public:
    ~Manage() {
        /*if (!v.empty()) {
            for (shared_ptr<Student> i : v) {
                delete(i);
            }
        }*/
    }
    void addData();
    void delData(const string&);
    void findData(const string&);
    void showList();
    void showMemberData(const unsigned int&);
    void changeData(const int&);
    void recruitFunction(const int&);
    int getNumberGood();
    int getNumberNormal();
    vector< shared_ptr<GoodStudent>> sortGoodStudent();             //unused
    vector< shared_ptr<NormalStudent>> sortNormalStudent();         //unused
    void showPassedGoodStudent(int, const int&);                         //nhap vao so luong sinh vien pass
    void showPassedNormalStudent(int, const int&);                       //nhap vao so luong sinh vien pass
    void selectionSort();
    int sizeList() {
        return v.size();
    }
};

#endif // !__MANAGE_H
