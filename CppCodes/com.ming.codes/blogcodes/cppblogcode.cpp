//
// Created by Lenovo on 2019/1/30.
//

#include "cppblogcode.h"
#include<iostream>
#include<string>
#include <limits>


using std::cout;
using std::numeric_limits;
using std::endl;
using std::string;

void print_basic_data_types() {
    cout << "type: \t\t" << "************size begin **************" << endl;
    cout << "bool: \t\t" << "Number of bytes occupied" << sizeof(bool);
    cout << "\tmax" << (numeric_limits<bool>::max)();
    cout << "\t\tmin" << (numeric_limits<bool>::min)() << endl;
    cout << "char: \t\t" << "Number of bytes occupied" << sizeof(char);
    cout << "\tmax" << (numeric_limits<char>::max)();
    cout << "\t\tmin" << (numeric_limits<char>::min)() << endl;
    cout << "signed char: \t" << "Number of bytes occupied" << sizeof(signed char);
    cout << "\tmax" << (numeric_limits<signed char>::max)();
    cout << "\t\tmin" << (numeric_limits<signed char>::min)() << endl;
    cout << "unsigned char: \t" << "Number of bytes occupied" << sizeof(unsigned char);
    cout << "\tmax" << (numeric_limits<unsigned char>::max)();
    cout << "\t\tmin" << (numeric_limits<unsigned char>::min)() << endl;
    cout << "wchar_t: \t" << "Number of bytes occupied" << sizeof(wchar_t);
    cout << "\tmax" << (numeric_limits<wchar_t>::max)();
    cout << "\t\tmin" << (numeric_limits<wchar_t>::min)() << endl;
    cout << "short: \t\t" << "Number of bytes occupied" << sizeof(short);
    cout << "\tmax" << (numeric_limits<short>::max)();
    cout << "\t\tmin" << (numeric_limits<short>::min)() << endl;
    cout << "int: \t\t" << "Number of bytes occupied" << sizeof(int);
    cout << "\tmax" << (numeric_limits<int>::max)();
    cout << "\tmin" << (numeric_limits<int>::min)() << endl;
    cout << "unsigned: \t" << "Number of bytes occupied" << sizeof(unsigned);
    cout << "\tmax" << (numeric_limits<unsigned>::max)();
    cout << "\tmin" << (numeric_limits<unsigned>::min)() << endl;
    cout << "long: \t\t" << "Number of bytes occupied" << sizeof(long);
    cout << "\tmax" << (numeric_limits<long>::max)();
    cout << "\tmin" << (numeric_limits<long>::min)() << endl;
    cout << "unsigned long: \t" << "Number of bytes occupied" << sizeof(unsigned long);
    cout << "\tmax" << (numeric_limits<unsigned long>::max)();
    cout << "\tmin" << (numeric_limits<unsigned long>::min)() << endl;
    cout << "double: \t" << "Number of bytes occupied" << sizeof(double);
    cout << "\tmax" << (numeric_limits<double>::max)();
    cout << "\tmin" << (numeric_limits<double>::min)() << endl;
    cout << "long double: \t" << "Number of bytes occupied" << sizeof(long double);
    cout << "\tmax" << (numeric_limits<long double>::max)();
    cout << "\tmin" << (numeric_limits<long double>::min)() << endl;
    cout << "float: \t\t" << "Number of bytes occupied" << sizeof(float);
    cout << "\tmax" << (numeric_limits<float>::max)();
    cout << "\tmin" << (numeric_limits<float>::min)() << endl;
    cout << "size_t: \t" << "Number of bytes occupied" << sizeof(size_t);
    cout << "\tmax" << (numeric_limits<size_t>::max)();
    cout << "\tmin" << (numeric_limits<size_t>::min)() << endl;
    cout << "string: \t" << "Number of bytes occupied" << sizeof(string) << endl;
    // << "\tmax" << (numeric_limits<string>::max)() << "\tmin" << (numeric_limits<string>::min)() << endl;
    cout << "type: \t\t" << "************size end **************" << endl;

};

void set_print_person() {
    Person zhang;
    Person li(19,29);
    zhang.age = 19;
    zhang.id = 13952;
    zhang.name = 'i';
    zhang.sex = 'g';
    li.name = 'j';
    li.sex = 'b';
    cout << "zhang.age is " << zhang.age << "  zhang.name is " << zhang.name << endl;
    cout << "li.age is " << li.age << "  li.id is " << li.id << endl;
}

void  set_print_boxes(){
    Box Box1;                // 声明 Box1，类型为 Box
    Box Box2;                // 声明 Box2，类型为 Box
    double volume = 0.0;     // 用于存储体积

    // box 1 详述
    Box1.setLength(6.0);
    Box1.setBreadth(7.0);
    Box1.setHeight(5.0);

    // box 2 详述
    Box2.setLength(12.0);
    Box2.setBreadth(13.0);
    Box2.setHeight(10.0);

    // box 1 的体积
    volume = Box1.getVolume();
    cout << "Box1 getVolume is :" << volume <<endl;

    // box 2 的体积
    volume = Box2.getVolume();
    cout << "Box2 getVolume is :" << volume <<endl;
}

void set_print_student(){
    Student student;
    student.name='Y';
    cout << "student name is :" << student.name <<endl;
    student.setClassroom('5');
    cout << "student getClassroom is :" << student.getClassroom() <<endl;
    LittleStudent littleStudent;
    littleStudent.setAddress('N');
    cout << "student getAddress is :" << littleStudent.getAddress() <<endl;
}


