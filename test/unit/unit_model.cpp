/*! 
 *  \file unit_model.cpp
 */

#include "unit_model.h"

using namespace std;

void unit_Model_constructor() {
    cout << "MODEL CONSTRUCTOR TEST STARTING..." << endl;

    // TEST 1 - DEFAULT CONSTRUCTOR
    ModelImpl *def = new ModelImpl();

    assert(def->getName() == "default1");

    // TEST 2 - NAME CONSTRUCTOR
    ModelImpl *nam = new ModelImpl("Name constructor");

    assert(nam->getName() == "Name constructor");

    // TEST 3 - SIMPLE COPY CONSTRUCTOR
    ModelImpl m1("Atribution");
    Stock *s1 = m1.createStock(new StockImpl("stock1", 100));
    Stock *s2 = m1.createStock(new StockImpl("stock2", 20));

    m1.createFlow(new ExponentialFlow("exp", s1, s2));
    m1.createFlow(new LogisticFlow("log", s2, s1));

    cout << "model constructor" << endl;
    ModelImpl m2 = m1;

    // TEST 4 - MODELS SAME NAME
    assert(m2.getName() == m1.getName());
    assert(m2.getName() == "Atribution");

    // TEST 5 - STOCKS HAVE SAME NAME AND VALUE
    assert(m1.stock_list.front()->getName() == m2.stock_list.front()->getName());
    assert(fabs(m1.stock_list.front()->getValue() - m2.stock_list.front()->getValue()) < 0.0001);
    assert(m1.stock_list.back()->getName() == m2.stock_list.back()->getName());
    assert(fabs(m1.stock_list.back()->getValue() - m2.stock_list.back()->getValue()) < 0.0001);

    // TEST 6 - DIFFERENT STOCK ADDRESSES
    assert(&(m1.stock_list.front()) != &(m2.stock_list.front())); 
    assert(&(m1.stock_list.back()) != &(m2.stock_list.back())); 
    assert(m1.stock_list.front() != m2.stock_list.front()); 
    assert(m1.stock_list.back() != m2.stock_list.back()); 

    // TEST 7 - FLOWS HAVE THE SAME NAME
    assert(m1.flow_list.front()->getName() == m2.flow_list.front()->getName());
    assert(m1.flow_list.back()->getName() == m2.flow_list.back()->getName());

    // TEST 8 - FLOWS POINT TO DIFFERENT ADDRESSES
    assert(&(*m1.flow_list.front()->getOrigin()) != &(*m2.flow_list.front()->getOrigin()));
    assert(&(*m1.flow_list.front()->getDestination()) != &(*m2.flow_list.front()->getDestination()));
    assert(&(*m1.flow_list.back()->getOrigin()) != &(*m2.flow_list.back()->getOrigin()));
    assert(&(*m1.flow_list.back()->getDestination()) != &(*m2.flow_list.back()->getDestination()));

    // TEST 9 - FLOWS FROM MODEL 1 POINT TO STOCKS FROM MODEL 1
    assert(m1.flow_list.front()->getOrigin() == m1.stock_list.front());
    assert(m1.flow_list.front()->getDestination() == m1.stock_list.back());
    assert(m1.flow_list.back()->getOrigin() == m1.stock_list.back());
    assert(m1.flow_list.back()->getDestination() == m1.stock_list.front());

    // TEST 10 - FLOWS FROM MODEL 2 POINT TO STOCKS FROM MODEL 2
    assert(m2.flow_list.front()->getOrigin() == m2.stock_list.front());
    assert(m2.flow_list.front()->getDestination() == m2.stock_list.back());
    assert(m2.flow_list.back()->getOrigin() == m2.stock_list.back());
    assert(m2.flow_list.back()->getDestination() == m2.stock_list.front());

    // TEST 11 - RUNNING MODEL 2. MODEL 1 SHOULD STAY THE SAME.
    m2.execute();

    assert(fabs(m1.stock_list.front()->getValue() - 100) < 0.0001);
    assert(fabs(m1.stock_list.back()->getValue() - 20) < 0.0001);

    assert(fabs(m2.stock_list.front()->getValue() - 40.9604) < 0.0001);
    assert(fabs(m2.stock_list.back()->getValue() - 79.0396) < 0.0001);

    delete s1, s2;

    cout << "MODEL CONSTRUCTOR TEST ENDED." << endl;
};

void unit_Model_destructor() {
    cout << "MODEL DESTRUCTOR TEST STARTING..." << endl;

    // TEST 1 - DEFAULT DESTRUCTOR    
    ModelImpl *def = new ModelImpl("Destructor");

    delete def;

    // assert(def == nullptr);

    cout << "MODEL DESTRUCTOR TEST ENDED." << endl;
};

void unit_Model_getName() {
    cout << "MODEL GET NAME TEST STARTING..." << endl;

    // TEST 1 - DEFAULT MODEL GET NAME
    ModelImpl *def = new ModelImpl();

    assert(def->getName() == "default2");

    // TEST 2 - CONST MODEL GET NAME
    const ModelImpl con("My Const Name");

    assert(con.getName() == "My Const Name");

    cout << "MODEL GET NAME TEST ENDED." << endl;
}

void unit_Model_setName() {
    cout << "MODEL SET NAME TEST STARTING..." << endl;

    // TEST 1 - DEFAULT MODEL SET NAME
    ModelImpl *set = new ModelImpl();
    set->setName("My Name");

    assert(set->getName() == "My Name");

    // TEST 2 - OVERWRITE NAME
    ModelImpl over("Original Name");
    over.setName("New Name");

    assert(over.getName() == "New Name");

    cout << "MODEL SET NAME TEST ENDED." << endl;
}

void unit_Model_execute() {
    cout << "MODEL EXECUTE TEST STARTING..." << endl;

    // TEST 1 - DEFAULT EXECUTION
    ModelImpl *m1 = new ModelImpl("Default Model");
    Stock *s1 = m1->createStock(new StockImpl("pop1", 100));
    Stock *s2 = m1->createStock(new StockImpl("pop2", 0));
    m1->createFlow(new ExponentialFlow("exponencial", s1, s2));
    m1->execute();

    assert(fabs(s1->getValue() - 36.6032) < 0.0001);
    assert(fabs(s2->getValue() - 63.3968) < 0.0001);

    // TEST 2 - INCREMENT EXECUTION
    ModelImpl *m2 = new ModelImpl("Increment Model");
    Stock *stock1 = m2->createStock(new StockImpl("pop1", 100));
    Stock *stock2 = m2->createStock(new StockImpl("pop2", 0));
    m2->createFlow(new ExponentialFlow("exponencial increment", stock1, stock2));
    m2->execute(0, 100, 2);

    assert(fabs(stock1->getValue() - 60.5006) < 0.0001);
    assert(fabs(stock2->getValue() - 39.4994) < 0.0001);
    
    cout << "MODEL EXECUTE TEST ENDED." << endl;
}

void unit_Model_add() {
    cout << "MODEL ADD TEST STARTING..." << endl;

    // TEST 1 - ADDING STOCK
    ModelImpl *st = new ModelImpl("Adding Stock");
    StockImpl s("stock", 1);

    st->add(s);

    assert(st->stock_list.front()->getName() == "stock");

    // TEST 2 - ADDING FLOW
    ModelImpl *ft = new ModelImpl("Adding Stock");
    ExponentialFlow f("flow");

    ft->add(f);

    assert(ft->flow_list.front()->getName() == "flow");

    // TEST 3 - ADDING FLOWS
    ModelImpl model1("Test 3");
    Flow *f1 = new ExponentialFlow("F1");
    Flow *f2 = new ExponentialFlow("F2");
    Flow *f3 = new ExponentialFlow("F3");
    Flow *f4 = new ExponentialFlow("F4");
    Flow *f5 = new ExponentialFlow("F5");

    model1.add(*f1); model1.add(*f2); model1.add(*f3); model1.add(*f4); model1.add(*f5);

    int flow_count = 0;
    for(std::list<Flow*>::iterator it = model1.flow_list.begin(); it != model1.flow_list.end(); it++) {
        flow_count++;
    }

    assert( flow_count == 5 );

    // TEST 4 - ADDING STOCKS
    ModelImpl model2("Test 2");
    Stock *s1 = new StockImpl("Q1", 10);
    Stock *s2 = new StockImpl("Q2", 20);
    Stock *s3 = new StockImpl("Q3", 30);
    Stock *s4 = new StockImpl("Q4", 40);
    Stock *s5 = new StockImpl("Q5", 50);

    model2.add(*s1); model2.add(*s2); model2.add(*s3); model2.add(*s4); model2.add(*s5);

    int stock_count = 0;
    for(std::list<Stock*>::iterator it = model2.stock_list.begin(); it != model2.stock_list.end(); it++ ) {
        stock_count++;
    }

    assert( stock_count == 5 );

    cout << "MODEL ADD TEST ENDED." << endl;
}

void unit_Model_atributionOperator() {
    cout << "MODEL ATRIBUTION OPERATOR TEST STARTING..." << endl;

    // TEST 1 - SELF ATRIBUTION
    ModelImpl one("Himself");

    one = one;

    assert(one.getName() == "Himself");

    // TEST 2 - ATRIBUTION ONE TO ANOTHER
    ModelImpl m1("Atribution");
    Stock *s1 = m1.createStock(new StockImpl("stock1", 100));
    Stock *s2 = m1.createStock(new StockImpl("stock2", 20));

    m1.createFlow(new ExponentialFlow("exp", s1, s2));
    m1.createFlow(new LogisticFlow("log", s2, s1));

    ModelImpl m2("Other");

    m2 = m1;

    // TEST 3 - MODELS SAME NAME
    assert(m2.getName() == m1.getName());
    assert(m2.getName() == "Atribution");

    // TEST 4 - STOCKS HAVE SAME NAME AND VALUE
    assert(m1.stock_list.front()->getName() == m2.stock_list.front()->getName());
    assert(fabs(m1.stock_list.front()->getValue() - m2.stock_list.front()->getValue()) < 0.0001);
    assert(m1.stock_list.back()->getName() == m2.stock_list.back()->getName());
    assert(fabs(m1.stock_list.back()->getValue() - m2.stock_list.back()->getValue()) < 0.0001);

    // REVISAO
    // Stock *s;
    // . &s => endereço da variável ponteiro
    // . *s = conteúdo que o ponteiro aponta
    // . &(*s) , s => endereço do conteudo do ponteiro que é o que esta guardado na minha variavel ponteiro

    // TEST 5 - DIFFERENT STOCK ADDRESSES
    assert(&(m1.stock_list.front()) != &(m2.stock_list.front())); // Comparando endereço do ponteiro Stock*
    assert(&(m1.stock_list.back()) != &(m2.stock_list.back())); // "sao ponteiros diferentes"
    assert(m1.stock_list.front() != m2.stock_list.front()); // Comparando o endereço do conteúdo de Stock* (passa sem usar dll)
    assert(m1.stock_list.back() != m2.stock_list.back()); // "os conteudos estao guardados em lugares diferentes"

    // TEST 6 - FLOWS HAVE THE SAME NAME
    assert(m1.flow_list.front()->getName() == m2.flow_list.front()->getName());
    assert(m1.flow_list.back()->getName() == m2.flow_list.back()->getName());

    // TEST 7 - FLOWS POINT TO DIFFERENT ADDRESSES
    assert(&(*m1.flow_list.front()->getOrigin()) != &(*m2.flow_list.front()->getOrigin())); // Comparando endereço do conteudo de Stock*
    assert(&(*m1.flow_list.front()->getDestination()) != &(*m2.flow_list.front()->getDestination())); // que é apontado pelo Flow*
    assert(&(*m1.flow_list.back()->getOrigin()) != &(*m2.flow_list.back()->getOrigin())); // "flows do model 1 apontam pra stocks do model 1"
    assert(&(*m1.flow_list.back()->getDestination()) != &(*m2.flow_list.back()->getDestination())); // Compara tanto Origem quanto Destino

    // TEST 8 - FLOWS FROM MODEL 1 POINT TO STOCKS FROM MODEL 1
    assert(m1.flow_list.front()->getOrigin() == m1.stock_list.front());
    assert(m1.flow_list.front()->getDestination() == m1.stock_list.back());
    assert(m1.flow_list.back()->getOrigin() == m1.stock_list.back());
    assert(m1.flow_list.back()->getDestination() == m1.stock_list.front());

    // TEST 9 - FLOWS FROM MODEL 2 POINT TO STOCKS FROM MODEL 2
    assert(m2.flow_list.front()->getOrigin() == m2.stock_list.front());
    assert(m2.flow_list.front()->getDestination() == m2.stock_list.back());
    assert(m2.flow_list.back()->getOrigin() == m2.stock_list.back());
    assert(m2.flow_list.back()->getDestination() == m2.stock_list.front());

    // TEST 10 - RUNNING MODEL 2. MODEL 1 SHOULD STAY THE SAME.
    m2.execute();

    assert(fabs(m1.stock_list.front()->getValue() - 100) < 0.0001);
    assert(fabs(m1.stock_list.back()->getValue() - 20) < 0.0001);

    assert(fabs(m2.stock_list.front()->getValue() - 40.9604) < 0.0001);
    assert(fabs(m2.stock_list.back()->getValue() - 79.0396) < 0.0001);

    delete s1, s2;

    cout << "MODEL ATRIBUTION OPERATOR TEST ENDED." << endl;
}

void unit_Model_createStock() {
    cout << "MODEL CREATE STOCK TEST STARTING..." << endl;

    // TEST 1: DEFAULT STOCK
    ModelImpl m1("Default create");
    Stock *s1 = m1.createStock(new StockImpl());

    assert(m1.stock_list.size() == 1);
    // cout << m1.stock_list.front()->getName() << endl;
    assert(m1.stock_list.front()->getName() == "default19");
    assert(fabs(m1.stock_list.front()->getValue() - 0) < 0.0001);

    cout << "MODEL CREATE STOCK TEST ENDED." << endl;
}

void unit_Model_createFlow() {
    cout << "MODEL CREATE FLOW TEST STARTING..." << endl;

    // TEST 1: DEFAULT FLOW
    ModelImpl m1("Default create");
    Flow *s1 = m1.createFlow(new ExponentialFlow());

    assert(m1.flow_list.size() == 1);
    assert(m1.flow_list.front()->getOrigin() == nullptr);
    assert(m1.flow_list.front()->getDestination() == nullptr);

    cout << "MODEL CREATE FLOW TEST ENDED." << endl;
}

void run_unit_tests_Model() {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_getName();
    unit_Model_setName();
    unit_Model_execute();
    unit_Model_add();
    unit_Model_atributionOperator();
    unit_Model_createStock();
    unit_Model_createFlow();
}

void unit_cout() {
    cout << "MODEL COUT TEST STARTING..." << endl;

    // TEST 1 - STOCK
    // StockImpl s1("s1", 92);
    // StockImpl s2 = StockImpl();
    // StockImpl *s3 = new StockImpl();
    // Stock *s4 = new StockImpl();
    
    // cout << s1;
    // cout << s2;
    // cout << *s3;
    // cout << *s4;

    // TEST 2 - FLOW
    // ExponentialFlow f1("fun1", &s2, s3);
    // FlowImpl *f2 = new ExponentialFlow("fun2", &s2, s3);
    // Flow *f3 = new ExponentialFlow("fun3", &s2, s3);

    // cout << f1;
    // cout << *f2;
    // cout << &f3;

    // Stock *s1 = new StockImpl();
    // REVISÃO * &
    // cout << &s1 << endl; cout << &s2 << endl; // Endereço da minha variável ponteiro
    // cout << *s1 << endl; cout << *s2 << endl; // Conteúdo que o meu ponteiro aponta
    // cout << &(*s1) << endl; cout << &(*s2) << endl; // Endereço do conteúdo <<< &(*s1) == s1 >>>

    cout << endl << "MODEL COUT TEST ENDED." << endl;
}