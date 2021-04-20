#include <iostream>
#include <fstream>
#include "NumberWithUnits.hpp"
using namespace std;


namespace ariel{

    void NumberWithUnits::read_units(ifstream & file){}


    NumberWithUnits NumberWithUnits::operator--(){
        this->number -=1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int){
        NumberWithUnits copy = *this;
        this->number -=1;
        return copy;
    }

    NumberWithUnits NumberWithUnits::operator++(){
        this->number +=1;
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int){
        NumberWithUnits copy = *this;
        this->number +=1;
        return copy;
    }

    NumberWithUnits operator*(NumberWithUnits& n, double num){
        return NumberWithUnits{n.number*num,n._str};
    }
    NumberWithUnits operator*(double num, NumberWithUnits& n){
        return NumberWithUnits{n.number*num,n._str};
    }


    NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator + (const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator + (){
        return *this;
    }
    NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator - (const NumberWithUnits& other){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator - (){
        return NumberWithUnits {this->number*(-1) , this->_str};
    }

    // const NumberWithUnits operator-(const NumberWithUnits& a,const NumberWithUnits b);
    // const NumberWithUnits operator+(const NumberWithUnits& a,const NumberWithUnits b);


    bool operator==(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator>(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator<(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }
    bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b){
        return true;
    }



    ostream& operator<< (ostream& os, const NumberWithUnits& num){
        return os << num.number << "[" << num._str << "]" << endl;
    }

    istream& operator >> (istream& is, NumberWithUnits num){
        string out;
        return is >> num.number >> out >> num._str;
    }

}