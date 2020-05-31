#ifndef _FORMAT_H
#define _FORMAT_H
#include "CommonDeclaration.h"

class Format
{
private:
    int _num;
    int _age;
    char _name[NAME_LENGTH];
public:
    Format(int num, int age, char *name);
    void showData();
    int getNum();
    int getAge();
    char* getName();
    void setMember(int num, int age, char *name);
};
#endif
