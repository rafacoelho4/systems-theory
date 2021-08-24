/*! 
 *  \file unit_model.h
 */
#ifndef UNIT_MODEL
#define UNIT_MODEL

/// \cond
#include <assert.h>
#include <math.h>
#include <iostream>
/// \endcond

#include "..\..\src\model_impl.h"
#include "..\..\src\stock_impl.h"
#include "..\..\src\flow_impl.h"

void run_unit_tests_Model();
/**
 * Unit test constructor.
 *
 */
void unit_Model_constructor();
/**
 * Unit test destructor.
 *
 */
void unit_Model_destructor();
/**
 * Unit test get name.
 *
 */
void unit_Model_getName();
/**
 * Unit test set name.
 *
 */
void unit_Model_setName();
/**
 * Unit test execute.
 *
 */
void unit_Model_execute();
/**
 * Unit test add.
 *
 */
void unit_Model_add();
/**
 * Unit test atribution operator.
 *
 */
void unit_Model_atributionOperator();
void unit_Model_createStock();
void unit_Model_createFlow();

void unit_cout();

#endif

