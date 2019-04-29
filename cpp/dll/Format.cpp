#include <iostream>
#include <cstring>
#include "Format.h"
using namespace std;

Format::Format(int num, int age, char *name) :_num(num), _age(age)
{
	strncpy(_name, name, sizeof(_name));
}
void Format::showData()
{
	cout <<"|"<<_num<<"|"<<_age<<"|"<<_name << "|" << endl;
}
int Format::getNum()
{
	return _num;
}
int Format::getAge()
{
	return _age;
}
char* Format::getName()
{
	return _name;
}
void Format::setMember(int num, int age, char *name) {
	_num = num;
	_age = age;
	strncpy(_name, name, sizeof(_name));
}