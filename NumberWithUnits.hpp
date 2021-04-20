#pragma once
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <utility>

namespace ariel{

    class NumberWithUnits
    {
    private:
        double number;
        std::string _str;
    public:
        NumberWithUnits(double num,std::string str):number(num),_str(str){}
        static void read_units(std::ifstream& units_file);
        double getNumber(){
            return number;
        }
        std::string getUnit(){
            return _str;
        }


        NumberWithUnits operator--();
        NumberWithUnits operator--(int);
        NumberWithUnits operator++();
        NumberWithUnits operator++(int);

        friend NumberWithUnits operator*(NumberWithUnits& n, double num);
        friend NumberWithUnits operator*(double num, NumberWithUnits& n);


        NumberWithUnits& operator+=(const NumberWithUnits& other);
        NumberWithUnits& operator-=(const NumberWithUnits& other);
        NumberWithUnits operator + (const NumberWithUnits& other);
        NumberWithUnits operator + ();
        NumberWithUnits operator - (const NumberWithUnits& other);
        NumberWithUnits operator - ();


        friend bool operator==(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator!=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator>=(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<(const NumberWithUnits& a, const NumberWithUnits& b);
        friend bool operator<=(const NumberWithUnits& a, const NumberWithUnits& b);


        friend std::ostream& operator << (std::ostream& os, const NumberWithUnits& num);
        friend std::istream& operator >> (std::istream& is, NumberWithUnits num);
    };     
}
