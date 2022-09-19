#include "goodstudent.h"

//GOOD STUDENT FUNCTION ====================================================//
void GoodStudent::setGPA(const float& gpa)                 { this->gpa = gpa; }
void GoodStudent::setBestReward(const string& reward)      { this->bestRewardName = reward; }
float GoodStudent::getGPA()                         { return this->gpa; }
string GoodStudent::getBestReward()                 { return this->bestRewardName; }

void GoodStudent::insertData() {
    Student::insertData();
    cout << "Nhap GPA: "; cin >> this->gpa;
    cout << "Nhap thanh tich: "; cin >> this->bestRewardName;
    this->setLevel(good);
}

void GoodStudent::showInfo() {
    Student::showInfo();
    cout << " - GPA: " << gpa << " - Reward: " << bestRewardName << endl;
}

bool GoodStudent::operator < (GoodStudent another) {
    return (this->gpa > another.getGPA());       // < : sap xep tang dan;    > : sap xep giam dan
}
