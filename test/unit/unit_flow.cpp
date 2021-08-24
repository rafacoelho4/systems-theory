/*! 
 *  \file unit_flow.cpp
 */
#include "unit_flow.h"

using namespace std;

void unit_Flow_constructor(){
    cout << "FLOW CONSTRUCTOR TEST STARTING..." << endl;

    // TEST 1 - DEFAULT CONSTRUCTOR
    Flow *def = new ExponentialFlow();

    assert(def->getName() == "default1");
    assert(def->getOrigin() == nullptr);
    assert(def->getDestination() == nullptr);

    // TEST 3 - NAME CONSTRUCTOR
    Flow *nam = new LogisticFlow("Name constructor");

    assert(nam->getName() == "Name constructor");
    assert(nam->getOrigin() == nullptr);
    assert(nam->getDestination() == nullptr);

    // TEST 4 - FULL CONSTRUCTOR
    StockImpl s1("Origin", 10), s2("Destination", 20);
    Flow *full = new LogisticFlow("Full constructor", &s1, &s2);

    assert(full->getName() == "Full constructor");
    assert(full->getOrigin() != nullptr);
    assert(full->getDestination() != nullptr);
    assert(full->getOrigin()->getName() == "Origin");
    assert(full->getDestination()->getName() == "Destination");
    assert(fabs(full->getOrigin()->getValue() - 10) < 0.0001);
    assert(fabs(full->getDestination()->getValue() - 20) < 0.0001);

    delete def, nam, full;

    cout << "FLOW CONSTRUCTOR TEST ENDED." << endl;
}

void unit_Flow_destructor(){
    cout << "FLOW DESTRUCTOR TEST STARTING..." << endl;

    // TEST 1 - DEFAULT DESTRUCTOR    
    Flow *def = new ExponentialFlow("Destructor");

    delete def;

    // assert(def == nullptr);

    cout << "FLOW DESTRUCTOR TEST ENDED." << endl;
};

void unit_Flow_getName() {
    cout << "FLOW GET NAME TEST STARTING..." << endl;

    // TEST 1 - DEFAULT FLOW GET NAME
    Flow *def = new ExponentialFlow();

    assert(def->getName() == "default2");

    // TEST 2 - CONST FLOW GET NAME
    const LogisticFlow con("My Const Name");

    assert(con.getName() == "My Const Name");

    delete def;

    cout << "FLOW GET NAME TEST ENDED." << endl;
}

void unit_Flow_setName() {
    cout << "FLOW SET NAME TEST STARTING..." << endl;

    // TEST 1 - DEFAULT FLOW SET NAME
    Flow *set = new ExponentialFlow();
    set->setName("My Name");

    assert(set->getName() == "My Name");

    // TEST 2 - OVERWRITE NAME
    LogisticFlow over("Original Name");
    over.setName("New Name");

    assert(over.getName() == "New Name");

    delete set;

    cout << "FLOW SET NAME TEST ENDED." << endl;
}

void unit_Flow_getOrigin() {
    cout << "FLOW GET ORIGIN TEST STARTING..." << endl;

    // TEST 1 - DEFAULT FLOW GET ORIGIN
    Flow *def = new ExponentialFlow("get origin");

    assert(def->getOrigin() == nullptr);

    // TEST 2 - FLOW GET STOCK AS ORIGIN
    StockImpl s1("stock1", 1), s2("stock2", 2);
    Flow *ori = new ExponentialFlow("Get Origin", &s1, &s2);

    assert(ori->getOrigin() != nullptr);
    assert(ori->getOrigin()->getName() == "stock1");
    assert(fabs(ori->getOrigin()->getValue() - 1) < 0.0001);

    // TEST 2 - CONST FLOW GET NAME
    const LogisticFlow con("My Const Name");

    assert(con.getOrigin() == nullptr);

    delete def, ori;

    cout << "FLOW GET ORIGIN TEST ENDED." << endl;
}

void unit_Flow_setOrigin() {
    cout << "FLOW SET ORIGIN TEST STARTING..." << endl;

    // TEST 1 - DEFAULT FLOW SET Origin
    Flow *set = new ExponentialFlow("set origin");
    StockImpl ori("Default Origin", 1);
    set->setOrigin(&ori);

    assert(set->getOrigin() != nullptr);
    assert(set->getOrigin()->getName() == "Default Origin");
    assert(fabs(set->getOrigin()->getValue() - 1) < 0.0001);

    // TEST 2 - OVERWRITE ORIGIN
    StockImpl s1("Initial Origin", 1), s2("Initial Destination", 2);
    LogisticFlow over("Flow", &s1, &s2);

    StockImpl *s3 = new StockImpl("New Origin", 3);
    over.setOrigin(s3);

    assert(over.getOrigin()->getName() == "New Origin");
    assert(fabs(over.getOrigin()->getValue() - 3) < 0.0001);

    delete set;

    cout << "FLOW SET ORIGIN TEST ENDED." << endl;
}

void unit_Flow_getDestination() {
    cout << "FLOW GET DESTINATION TEST STARTING..." << endl;

    // TEST 1 - DEFAULT FLOW GET DESTINATION
    Flow *def = new ExponentialFlow("get destination");

    assert(def->getDestination() == nullptr);

    // TEST 2 - FLOW GET STOCK AS DESTINATION
    StockImpl s1("stock1", 1), s2("stock2", 2);
    Flow *ori = new ExponentialFlow("Get Destination", &s1, &s2);

    assert(ori->getDestination() != nullptr);
    assert(ori->getDestination()->getName() == "stock2");
    assert(fabs(ori->getDestination()->getValue() - 2) < 0.0001);

    // TEST 2 - CONST FLOW GET DESTINATION
    const LogisticFlow con("My Const Name");

    assert(con.getDestination() == nullptr);

    delete def, ori;

    cout << "FLOW GET DESTINATION TEST ENDED." << endl;
}

void unit_Flow_setDestination() {
    cout << "FLOW SET DESTINATION TEST STARTING..." << endl;

    // TEST 1 - DEFAULT FLOW SET DESTINATION
    Flow *set = new ExponentialFlow("set destination");
    StockImpl dest("Default Destination", 1);
    set->setDestination(&dest);

    assert(set->getDestination() != nullptr);
    assert(set->getDestination()->getName() == "Default Destination");
    assert(fabs(set->getDestination()->getValue() - 1) < 0.0001);

    // TEST 2 - OVERWRITE DESTINATION
    StockImpl s1("Initial Origin", 1), s2("Initial Destination", 2);
    LogisticFlow over("Flow", &s1, &s2);

    StockImpl *s3 = new StockImpl("New Destination", 3);
    over.setDestination(s3);

    assert(over.getDestination()->getName() == "New Destination");
    assert(fabs(over.getDestination()->getValue() - 3) < 0.0001);

    delete set;

    cout << "FLOW SET DESTINATION TEST ENDED." << endl;
}

void run_unit_tests_Flow() {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_getName();
    unit_Flow_setName();
    unit_Flow_getOrigin();
    unit_Flow_setOrigin();
    unit_Flow_getDestination();
    unit_Flow_setDestination();
}