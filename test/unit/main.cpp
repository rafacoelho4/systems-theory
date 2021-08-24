/*! 
 *  \file main.cpp
 */
#ifndef  MAIN_UNIT_TESTS
#define MAIN_UNIT_TESTS

#include "unit_tests.h"
#include "unit_model.h"
#include "unit_stock.h"
#include "unit_flow.h"

int main(){
    run_unit_tests_Stock();
    run_unit_tests_Flow();
    run_unit_tests_Model();
    return true;
}

#endif