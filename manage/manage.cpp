#include "manage.h"

//MANAGE FUNCTION ==========================================================//
void Manage::addData() {
	int a;
	cout << "1-Good student - 2-Normal student - 0-Back: ";
	cin >> a;
    switch (a) {
    case exit_t:
        return;
    case good_t: {
        shared_ptr<GoodStudent> p(new GoodStudent);
        p->insertData();
        p->showInfo();
        v.push_back(p);
        numberGoodStudent++;
        break;
    }
    case normal_t: {
        shared_ptr<NormalStudent> p(new NormalStudent);
        p->insertData();
        p->showInfo();
        v.push_back(p);
        numberNormalStudent++;
        break;
    }
    default:
        cout << "Nhap sai! Nhap so trong khoang 0 - 3\n";
        break;
    }
    /*sort(v.begin(), v.end()); */                              //Sap xep theo thu tu giam dan ho ten
    selectionSort();
    int q;
    cout << "Ban co muon tiep tuc? 1-Yes - 0-No: ";
    cin >> q;
    if (q == yes) {
        Manage::addData();
    }
}

void Manage::delData(const string& phonenumber) {
    int count = 0;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getPhone() == phonenumber) {
            count++;
            if (v[i]->getLevel() == good) {
                numberGoodStudent--;
            }
            else if (v[i]->getLevel() == normal) {
                numberNormalStudent--;
            }
            /*shared_ptr<Student> tmp = v[i];*/
            v.erase(v.begin() + i);
            i--;
        }
    }
    if (count == 0) {
        cout << "Can not find student has phone number: " << phonenumber << " in list!" << endl;
        return;
    }
    cout << "Delete done!" << endl;
}

void Manage::findData(const string& phonenumber) {
    int count = 0;
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getPhone() == phonenumber) {
            cout << i + 1 << ". ";
            count++;
            showMemberData(i);
        }
    }
    if (count == 0) {
        cout << "Can not find student has phone number: " << phonenumber << " in list!" << endl;
        return;
    }
}

void Manage::showList() {
    if (v.empty()) {
        cout << "No data in list!" << endl;
        return;
    }
    for (int i = 0; i < v.size(); i++) {
        cout << i + 1 << ". ";
        showMemberData(i);
    }
}

void Manage::showMemberData(const unsigned int& index) {
    if (v.empty()) {
        // cout << "No data in list!"<<endl;
        return;
    }
    if (index < v.size()) {
        if (v[index]->getLevel() == good) {
            shared_ptr<GoodStudent> p = dynamic_pointer_cast<GoodStudent>(v[index]);
            p->showInfo();
        }
        else if (v[index]->getLevel() == normal) {
            shared_ptr<NormalStudent> p = dynamic_pointer_cast<NormalStudent>(v[index]);
            p->showInfo();
        }
    }
}

void Manage::changeData(const int& index) {
    if (!v.empty()) {
        if (index < v.size()) {
            v[index]->insertData();
        }
    }
}

vector< shared_ptr<GoodStudent>> Manage::sortGoodStudent() {
    vector< shared_ptr<GoodStudent>> v1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getLevel() == good) {
            v1.push_back(dynamic_pointer_cast<GoodStudent>(v[i]));
        }
    }
    sort(v1.begin(), v1.end());
    return v1;
}

vector< shared_ptr<NormalStudent>> Manage::sortNormalStudent() {
    vector< shared_ptr<NormalStudent>> v2;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getLevel() == good) {
            v2.push_back(dynamic_pointer_cast<NormalStudent>(v[i]));
        }
    }
    sort(v2.begin(), v2.end());
    return v2;
}

void Manage::showPassedGoodStudent(int start_index, const int& numberPassed) {
    vector< shared_ptr<GoodStudent>> v1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getLevel() == good) {
            v1.push_back(dynamic_pointer_cast<GoodStudent>(v[i]));
        }
    }
    sort(v1.begin(), v1.end());
    for (int j = 0; j < numberPassed; j++) {
        cout << start_index + j + 1 << ". ";
        v1[j]->showInfo();
    }
}

void Manage::showPassedNormalStudent(int start_index, const int& numberPassed) {
    vector< shared_ptr<NormalStudent>> v2;
    for (int i = 0; i < v.size(); i++) {
        if (v[i]->getLevel() == normal) {
            v2.push_back(dynamic_pointer_cast<NormalStudent>(v[i]));
        }
    }
    sort(v2.begin(), v2.end());
    for (int j = 0; j < numberPassed; j++) {
        cout << start_index + j + 1 << ". ";
        v2[j]->showInfo();
    }
}

void Manage::recruitFunction(const int& numberRecruit) {
    if (v.empty()) {
        cout << "No data in list!\n";
        return;
    }
    if (numberRecruit <= numberGoodStudent) {
        cout << "Danh sach sinh vien trung tuyen:\n";
        Manage::showPassedGoodStudent(0, numberRecruit);
    }
    else if (numberRecruit > numberGoodStudent) {
        int temp = numberRecruit - numberGoodStudent;
        cout << "Danh sach sinh vien trung tuyen:\n";
        Manage::showPassedGoodStudent(0, numberGoodStudent);
        if (temp >= numberNormalStudent) {
            Manage::showPassedNormalStudent(numberGoodStudent, numberNormalStudent);
        }
        else if (temp < numberNormalStudent) {
            Manage::showPassedNormalStudent(numberGoodStudent, temp);
        }
    }
}

void Manage::selectionSort() {              //  < : GIAM DAN, > : TANG DAN
    //sort Name: A->B->C->....  tang dan
    for(int i_start = 0; i_start < v.size(); i_start++)
    {
        int minIndex = i_start;
        for (int i_current = i_start + 1; i_current < v.size(); i_current++)
        {
            if (v[minIndex]->getFullName() > v[i_current]->getFullName())                   
            {
                minIndex = i_current;
            }
        }
        swap(v[i_start], v[minIndex]);
    }
    //sort Phone number: 9->8->7->6....     giam dan
    for (int i_start = 0; i_start < v.size() - 1; i_start++)
    {
        int minIndex = i_start;
        for (int i_current = i_start + 1; i_current < v.size(); i_current++)
        {
            if (v[minIndex]->getFullName() == v[i_current]->getFullName()) {
                if (v[minIndex]->getPhone() < v[i_current]->getPhone()) {
                    minIndex = i_current;
                }
            }
        }
        swap(v[i_start], v[minIndex]);
    }
}


