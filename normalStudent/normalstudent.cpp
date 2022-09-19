#include "normalstudent.h"

//NORMAL STUDENT FUNCTION ==================================================//
void NormalStudent::setEnglishScore(const int& escore)  { this->englishScore = escore; }
void NormalStudent::setEntryScore(const float& tscore)  { this->entryTestScore = tscore; }
int NormalStudent::getEnglishScore()                    { return this->englishScore; }
float NormalStudent::getEntryScore()                    { return this->entryTestScore; }
void NormalStudent::insertData() {
    Student::insertData();
    cout << "Nhap TOEIC Score: "; cin >> this->englishScore;
    cout << "Nhap Test Score: "; cin >> this->entryTestScore;
    this->setLevel(normal);
}
void NormalStudent::showInfo() {
    Student::showInfo();
    cout << " - TOEIC: " << englishScore << " - Test: " << entryTestScore << endl;
}
bool NormalStudent::operator < (NormalStudent another) {
    return (this->englishScore > another.getEnglishScore());     // > : sap xep tang dan;    < : sap xep giam dan
}
