#ifndef __LIBRARY_H
#define __LIBRARY_H
/// De bai: https://shareprogramming.net/tong-hop-bai-tap-lap-trinh-huong-doi-tuong-trong-java/#Bai_14
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define yes 1
#define no 0
typedef enum { cmd_exit, cmd_add, cmd_remove, cmd_find, cmd_showlist, cmd_recruit }comand;
typedef enum { exit_t, good_t, normal_t }type_t;

#define PHONE_SET { "090", "098", "091", "031", "035", "038" }
#define PHONE_SIZE 8
#define MIN_RECRUIT 3           //so luong sinh vien toi thieu can tuyen dung
#define MAX_RECRUIT 10          //so luong sinh vien toi da can tuyen dung

typedef enum {
    male,
    female,
    other
}gender;
typedef enum {
    good,
    normal
}level;

bool checkValidName(const string&);
bool checkValidDate(const string&);
bool checkValidPhone(const string&);
void chuanhoaTen(string&);

#endif