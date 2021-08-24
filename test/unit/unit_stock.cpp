/*! 
 *  \file unit_stock.cpp
 */
#include "unit_stock.h"

using namespace std;

void unit_Stock_constructor(){
    cout << "STOCK CONSTRUCTOR TEST STARTING..." << endl;

    // TEST 1 - DEFAULT CONSTRUCTOR
    StockImpl *def = new StockImpl();

    assert(def->getName() == "default1");
    assert(fabs(def->getValue() - 0) < 0.0001);

    // TEST 2 - VALUE CONSTRUCTOR
    StockImpl *val = new StockImpl(10);

    assert(fabs(val->getValue() - 10) < 0.0001);
    assert(val->getName() == "default2");

    // TEST 3 - NAME CONSTRUCTOR
    StockImpl *nam = new StockImpl("Name constructor");

    assert(nam->getName() == "Name constructor");
    assert(fabs(nam->getValue() - 0) < 0.0001);

    // TEST 4 - FULL CONSTRUCTOR
    StockImpl *full = new StockImpl("Full constructor", 10);

    assert(full->getName() == "Full constructor");
    assert(fabs(full->getValue() - 10) < 0.0001);

    // TEST 5 - COPY CONSTRUCTOR
    StockImpl original("Original", 100);
    StockImpl copy = original;

    assert(copy.getName() == original.getName());
    assert(copy.getValue() == original.getValue());
    assert(copy.getName() == "Original");
    assert(fabs(copy.getValue() - 100) < 0.0001);

    cout << "STOCK CONSTRUCTOR TEST ENDED." << endl;
}

void unit_Stock_destructor(){
    cout << "STOCK DESTRUCTOR TEST STARTING..." << endl;

    // TEST 1 - DEFAULT DESTRUCTOR    
    StockImpl *est = new StockImpl("Destructor", 1);

    delete est;

    // assert(est == nullptr);

    cout << "STOCK DESTRUCTOR TEST ENDED." << endl;
};

void unit_Stock_getValue() {
    cout << "STOCK GET VALUE TEST STARTING..." << endl;

    // TEST 1 - DEFAULT STOCK GET VALUE
    StockImpl *val = new StockImpl();

    assert(fabs(val->getValue() - 0) < 0.0001);

    // TEST 2 - CONST STOCK GET VALUE
    const StockImpl con(10);

    assert(fabs(con.getValue() - 10) < 0.0001);

    cout << "STOCK GET VALUE TEST ENDED." << endl;
}

void unit_Stock_setValue() {
    cout << "STOCK SET VALUE TEST STARTING..." << endl;

    // TEST 1 - DEFAULT STOCK SET VALUE
    StockImpl *set = new StockImpl("value");
    set->setValue(20);

    assert(fabs(set->getValue() - 20) < 0.0001);

    // TEST 2 - OVERWRITE VALUE
    StockImpl over("overwrite", 30);
    over.setValue(20);

    assert(fabs(over.getValue() - 20) < 0.0001);

    cout << "STOCK SET VALUE TEST ENDED." << endl;
}

void unit_Stock_getName() {
    cout << "STOCK GET NAME TEST STARTING..." << endl;

    // TEST 1 - DEFAULT STOCK GET NAME
    StockImpl *def = new StockImpl();

    assert(def->getName() == "default5");

    // TEST 2 - CONST STOCK GET NAME
    const StockImpl con("My Const Name");

    assert(con.getName() == "My Const Name");

    cout << "STOCK GET NAME TEST ENDED." << endl;
}

void unit_Stock_setName() {
    cout << "STOCK SET NAME TEST STARTING..." << endl;

    // TEST 1 - DEFAULT STOCK SET NAME
    StockImpl *set = new StockImpl();
    set->setName("My Name");

    assert(set->getName() == "My Name");

    // TEST 2 - OVERWRITE NAME
    StockImpl over("Original Name");
    over.setName("New Name");

    assert(over.getName() == "New Name");

    cout << "STOCK SET NAME TEST ENDED." << endl;
}

void unit_Stock_atributionOperator() {
    cout << "STOCK ATRIBUTION OPERATOR TEST STARTING..." << endl;

    // TEST 1 - SELF ATRIBUTION
    StockImpl one("Himself", 1);

    one = one;

    assert(one.getName() == "Himself");
    assert(fabs(one.getValue() - 1) < 0.0001);

    // TEST 2 - ATRIBUTION ONE TO ANOTHER
    const StockImpl s1("Atribution", 10);
    StockImpl s2("Other", 5);

    s2 = s1;

    assert(s2.getName() == "Atribution");
    assert(fabs(s2.getValue() - 10) < 0.0001);

    cout << "STOCK ATRIBUTION OPERATOR TEST ENDED." << endl;
}

void unit_Stock_binaryOperators() {
    std::cout << "STOCK BINARY OPERATORS OVERLOADING TEST STARTING..." << std::endl;

    StockImpl s1("s1", 10), s2("s2", 20);

    // TEST 1 - MULTIPLICATION
    assert(fabs((s1*20) - 200) < 0.0001);
    assert(fabs((20*s1) - 200) < 0.0001);
    assert(fabs((s1*s2) - 200) < 0.0001);

    // TEST 2 - DIVISION
    assert(fabs((s1/2) - 5) < 0.0001);
    assert(fabs((20/s1) - 2) < 0.0001);
    assert(fabs((s1/s2) - 0.5) < 0.0001);

    // TEST 3 - ADDITION
    assert(fabs((s1+20) - 30) < 0.0001);
    assert(fabs((20+s1) - 30) < 0.0001);
    assert(fabs((s1+s2) - 30) < 0.0001);

    // TEST 4 - SUBTRACTION
    assert(fabs((s1-5) - 5) < 0.0001);
    assert(fabs((20-s1) - 10) < 0.0001);
    assert(fabs((s2-s1) - 10) < 0.0001);

    std::cout << "STOCK BINARY OPERATORS OVERLOADING TEST ENDED." << std::endl;
}

void run_unit_tests_Stock() {
    unit_Stock_constructor();
    unit_Stock_destructor();
    unit_Stock_getValue();
    unit_Stock_setValue();
    unit_Stock_getName();
    unit_Stock_setName();
    unit_Stock_atributionOperator();
    unit_Stock_binaryOperators();
    unit_Stock_Unnamed_Stock();
}

void unit_Stock_Unnamed_Stock() {
    std::cout << "STOCK UNNAMED TEST STARTING..." << std::endl;

    using namespace std;

    // TEST 1 - List of unnamed Stock
    Stock *s1 = new StockImpl();
    Stock *s2 = new StockImpl();
    Stock *s3 = new StockImpl();
    Stock *s4 = new StockImpl();

    assert(s1->getName() == "default11");
    assert(s2->getName() == "default12");
    assert(s3->getName() == "default13");
    assert(s4->getName() == "default14");

    // TEST 2 - Trying to set name with substring "default"
    Stock *def1 = new StockImpl("default");
    Stock *def2 = new StockImpl("default2");

    assert(def1->getName() == "default15");
    assert(def2->getName() == "default16");

    // TEST 3 - Copied Stock
    Stock *ori = new StockImpl();
    Stock *copy = new StockImpl();

    // ori->name = default17
    // copy->name = default18
    copy = ori;
    // ori->name = default17
    // copy->name = default17
    // Is it a problem?

    std::cout << "STOCK UNNAMED TEST ENDED." << std::endl;
}