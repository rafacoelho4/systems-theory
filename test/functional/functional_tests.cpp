/*! 
 *  \file functional_tests.cpp
 */
#include "functional_tests.h"

using namespace std;

void exponentialFuncionalTest() {
    cout << "EXPONENTIAL TEST STARTING..." << endl;

    ModelImpl *m = new ModelImpl("Exponential Model");

    Stock *s1 = m->createStock("pop1", 100);
    Stock *s2 = m->createStock("pop2", 0);
    m->createFlow<ExponentialFlow>("exponencial factory", s1, s2);

    m->execute();

    // Valores finais esperados após simulação
    assert(fabs(s1->getValue() - 36.6032) < 0.0001);
    assert(fabs(s2->getValue() - 63.3968) < 0.0001);

    cout << "EXPONENTIAL TEST ENDED." << endl << endl;
}

void logisticalFuncionalTest() {
    cout << "LOGISTIC TEST STARTING..." << endl;

    ModelImpl *m = new ModelImpl("Logistic Model");

    Stock *s1 = m->createStock("p1", 100);
    Stock *s2 = m->createStock("p2", 10);
    m->createFlow<LogisticFlow>("logistic", s1, s2);

    m->execute(0, 100, 1);

    // Valores finais esperados após simulação
    assert(fabs(s1->getValue() - 88.2167) < 0.0001);
    assert(fabs(s2->getValue() - 21.7833) < 0.0001);

    cout << "LOGISTIC TEST ENDED." << endl << endl;
}

void complexFuncionalTest() {
    cout << "COMPLEX TEST STARTING..." << endl;

    ModelImpl *m = new ModelImpl("Complex Model");

    Stock *s1 = m->createStock("Q1", 100);
    Stock *s2 = m->createStock("Q2", 0);
    Stock *s3 = m->createStock("Q3", 100);
    Stock *s4 = m->createStock("Q4", 0);
    Stock *s5 = m->createStock("Q5", 0);
    
    m->createFlow<ExponentialFlow>("f", s1, s2);
    m->createFlow<ExponentialFlow>("g", s1, s3);
    m->createFlow<ExponentialFlow>("t", s2, s3);
    m->createFlow<ExponentialFlow>("r", s2, s5);
    m->createFlow<ExponentialFlow>("u", s3, s4);
    m->createFlow<ExponentialFlow>("v", s4, s1);
    
    m->execute();

    assert(fabs(s1->getValue() - 31.8513) < 0.0001);
    assert(fabs(s2->getValue() - 18.4003) < 0.0001);
    assert(fabs(s3->getValue() - 77.1143) < 0.0001);
    assert(fabs(s4->getValue() - 56.1728) < 0.0001);
    assert(fabs(s5->getValue() - 16.4612) < 0.0001);

    cout << "COMPLEX TEST ENDED." << endl;
};