#include <iostream>
#include "Student.h"

using namespace std;

bool elso(const string &name, Student& e)
{
    StudentEnor t(name);
    bool l = false;
    for(t.first(); !l && !t.end(); t.next()){

        if(t.current().papperMass>=20){
            l = true;

            e.name = t.current().name;
            e.papperMass = t.current().papperMass;
        }
    }
    return l;
}

Class masodik(const string &name)
{
    ClassEnor t(name);
    Class result;
    result.papperMass = 0;
    for(t.first(); !t.end(); t.next()){
        if(result.papperMass < t.current().papperMass){
            result = t.current();
        }
    }
    return result;
}




#define NORMAL_MODE
#ifndef NORMAL_MODE



int main()
{
    string fname;
    cout << "Filename: "; cin >> fname;

    try{
        Student e;
        if(elso(fname, e)){
            cout << e.name << " tanulo gyujtott legalabb 20 kgt (" << e.papperMass << ")" << endl;
        } else {
            cout << "Nincs olyan diak aki minimum 20 kilot hozott" << endl;
        }
    }catch(StudentEnor::FileError err){
        cerr << "Nemletezo input fájl" << endl;
    }


    try{
        Class result = masodik(fname);

        cout << result.name << " osztaly gyujtotte a legtobb papirt, " << result.papperMass << " kg" << endl;
    }catch(StudentEnor::FileError err){
        cerr << "Nemletezo input fajl" << endl;
    }

    return 0;

}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("1", "t0.txt"){
    Student e;
    CHECK(elso("t0.txt", e));
    CHECK(e.name == "X Y");
    CHECK(e.papperMass == 99);

    Class tt = masodik("t0.txt");

    CHECK(tt.name == "1b");
    CHECK(tt.papperMass == 99);
}

TEST_CASE("2", "t1.txt"){
    Student e;
    CHECK_FALSE(elso("t1.txt", e));

    Class tt = masodik("t1.txt");

    CHECK(tt.name == "4c");
    CHECK(tt.papperMass == 9.5);
}


TEST_CASE("3", "t2.txt"){
    Student e;
    CHECK_FALSE(elso("t2.txt", e));

    Class tt = masodik("t2.txt");

    CHECK(tt.name == "4c");
    CHECK(tt.papperMass == 9.5);
}


TEST_CASE("4", "t3.txt"){
    Student e;
    CHECK(elso("t3.txt", e));
    CHECK(e.name == "Igen Karoly");
    CHECK(e.papperMass == 106);

    Class tt = masodik("t3.txt");

    CHECK(tt.name == "3b");
    CHECK(tt.papperMass == 106);
}

TEST_CASE("5", "t4.txt"){
    Student e;
    CHECK(elso("t4.txt", e));
    CHECK(e.name == "Nagyon Szorgalmas Eszter");
    CHECK(e.papperMass == 100);

    Class tt = masodik("t4.txt");

    CHECK(tt.name == "4c");
    CHECK(tt.papperMass == 110);
}

TEST_CASE("6", "t5.txt"){
    Student e;
    CHECK(elso("t5.txt", e));
    CHECK(e.name == "Nagyon Szorgalmas Eszter");
    CHECK(e.papperMass == 100);

    Class tt = masodik("t5.txt");

    CHECK(tt.name == "4c");
    CHECK(tt.papperMass == 110);
}
#endif
