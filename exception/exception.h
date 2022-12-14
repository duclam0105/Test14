#ifndef __EXCEPTION_H
#define __EXCEPTION_H

#include "Lib.h"

class nameException:public exception {
    string msg;
public:
    nameException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};
class dateException :public exception {
    string msg;
public:
    dateException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};
class phoneException :public exception {
    string msg;
public:
    phoneException(string mess) {
        msg = mess;
    }
    string what() {
        return msg;
    }
};

#endif // !__EXCEPTION_H
