#include "student.h"

//STUDENT FUNCTION =========================================================//
void Student::setFullName(const string& name)           { this->fullName = name; }
void Student::setDoB(const string& dob)                 { this->DoB = dob; }
void Student::setGender(const gender& s)                { this->sex = s; }
void Student::setPhone(const string& phone)             { this->phoneNumber = phone; }
void Student::setUniver(const string& univer)           { this->univerName = univer; }
void Student::setLevel(const level& lv)                 { this->gradeLevel = lv; }
string Student::getFullName()                           { return this->fullName; }
string Student::getDoB()                                { return this->DoB; }
gender Student::getSex()                                { return this->sex; }
string Student::getPhone()                              { return this->phoneNumber; }
string Student::getUniver()                             { return this->univerName; }
level Student::getLevel()                               { return this->gradeLevel; }
void Student::insertData() {
    string tmp_name, tmp_phone, tmp_date;
    cin.ignore();
    do {
        cout << "Nhap ten: ";
        getline(cin, tmp_name);
        chuanhoaTen(tmp_name);
        if (tmp_name == "0") break;
    } while (!checkValidName(tmp_name));
    this->fullName = tmp_name;
    do {
        cout << "Nhap ngay sinh: ";
        cin >> tmp_date;
        if (tmp_date == "0") break;
    } while (!checkValidDate(tmp_date));
    this->DoB = tmp_date;
    int a;
    do {
        cout << "Nhap gioi tinh: ";
        cin >> a;
    } while ((a < 0) || (a > 2));
    setGender((gender)a);
    do {
        cout << "Nhap so dien thoai: ";
        cin >> tmp_phone;
        if (tmp_phone == "0") break;
    } while (!checkValidPhone(tmp_phone));
    this->phoneNumber = tmp_phone;
    cout << "Nhap truong dai hoc: "; cin >> this->univerName;
}

void Student::showInfo() {
    cout << "Name: " << fullName << " - Birthday: " << DoB << " - Sex: " << sex <<
        " - Phone: " << phoneNumber << " - University: " << univerName << " - Level: " << gradeLevel;
}

//bool Student::operator < (Student another) {
//    return (this->fullName > another.getFullName());
//}
