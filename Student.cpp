#include "Student.h"
#include <iostream>
using namespace std;
StudentEnor::StudentEnor(const std::string &str) throw (FileError)
{
    f.open(str);
    if(f.fail())throw MissingInputFile;
}



void StudentEnor::next()
{
    std::string line, date;
    float mass = 0;
    cur.papperMass = 0;
    getline(f, line);
    if( !(over = f.fail())){
        std::istringstream is(line);

        is >> cur.name >> cur.sclass;      //több tagú név?
        while(!(isdigit(cur.sclass[0]))){
            cur.name += " " + cur.sclass;
            is >> cur.sclass;
        }
        while(is >> date >> mass){
            cur.papperMass = cur.papperMass + mass;
            }
    }
}

void ClassEnor::next()
{
    if(!(over = tt.end())){
        cur.name = tt.current().sclass;
        cur.papperMass = 0;
        for( ; !tt.end() && tt.current().sclass == cur.name; tt.next()){
            cur.papperMass += tt.current().papperMass;
        }
    }
}
