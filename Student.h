#pragma once
#include <fstream>
#include <sstream>
#include <string>

struct Student {
    std::string name;
    std::string sclass;
    float papperMass;
};

struct Class {
    std::string name;
    float papperMass;
};

class StudentEnor{
private:
    std::ifstream f;
    Student cur;
    bool over;
public:
    enum FileError{MissingInputFile};
    StudentEnor(const std::string &str) throw (FileError);
    void first() {next();}
    void next();
    Student current() const { return cur; }
    bool end() const { return over; }
};

class ClassEnor{
private:
    StudentEnor tt;
    Class cur;
    bool over;
public:
    ClassEnor(const std::string &str): tt(str) { };
    void first() {tt.first(); next();}
    void next();
    Class current() const { return cur; }
    bool end() const { return over; }
};

