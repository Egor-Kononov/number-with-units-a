#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <stdexcept>
#include <string>
#include <vector>

using namespace ariel;
using namespace std;


ifstream units_file{"units.txt"};


TEST_CASE("addition and subtraction"){
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a{10, "ton"};
    NumberWithUnits b{5000, "kg"};

    CHECK((a+b) == NumberWithUnits{15,"ton"});
    CHECK((b+a) == NumberWithUnits{15000,"ton"});
    CHECK((a-b) == NumberWithUnits{5,"ton"});
    CHECK((b-a) == NumberWithUnits{-5000,"ton"});
    a += b;
    CHECK(a == NumberWithUnits{15,"ton"});
    b -= a;
    CHECK(b == NumberWithUnits{-10000,"kg"});

    NumberWithUnits d{20, "USD"};
    CHECK_THROWS(a+d);
    CHECK_THROWS(d+b);
    CHECK(-a == NumberWithUnits{-15,"ton"});
}

TEST_CASE("inc/dec operators"){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{30, "m"};
    CHECK(++a == NumberWithUnits{31, "m"});
    CHECK(--a == NumberWithUnits{30, "m"});
    CHECK(a++ == NumberWithUnits{30, "m"});
    CHECK(a == NumberWithUnits{31, "m"});
    CHECK(a-- == NumberWithUnits{31, "m"});
    CHECK(a == NumberWithUnits{30, "m"});
}

TEST_CASE("Multiplication operator "){
    NumberWithUnits::read_units(units_file);
    NumberWithUnits a{10, "sec"};

    CHECK((a*5) == NumberWithUnits{50, "sec"});
    CHECK((100*a) == NumberWithUnits{1000, "sec"});
}

TEST_CASE("Comparison operators"){
    NumberWithUnits::read_units(units_file);

    CHECK_EQ(NumberWithUnits{1000, "USD"}  , NumberWithUnits{3330, "ILS"});
    CHECK_EQ(NumberWithUnits{1, "hour"}  , NumberWithUnits{3600, "sec"});
    CHECK_NE(NumberWithUnits{1000, "USD"}  , NumberWithUnits{3333, "ILS"});
    CHECK_NE(NumberWithUnits{1001, "USD"}  , NumberWithUnits{3330, "ILS"});

    CHECK_LT(NumberWithUnits{2, "ton"}  , NumberWithUnits{3000, "kg"});
    CHECK_GT(NumberWithUnits{5000, "g"}, NumberWithUnits{3, "kg"});
    CHECK_NE(NumberWithUnits{2, "m"}  , NumberWithUnits{3000, "cm"});

    CHECK_LT(NumberWithUnits{9000, "cm"} , NumberWithUnits{3000, "m"});
    CHECK_GT(NumberWithUnits{1, "km"}, NumberWithUnits{10000, "cm"});
}
