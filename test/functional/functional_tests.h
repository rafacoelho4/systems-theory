/*! 
 *  \file functional_tests.h
 */
#ifndef  FUNCTIONAL_TESTS_H
#define FUNCTIONAL_TESTS_H

#include <assert.h>
#include <math.h>
#include <iostream>

#include "..\..\src\model_impl.h"
#include "..\..\src\flow_impl.h"

/**
 * Function that tests the exponential system. Will alert if expected results are not met.
 * 
 * \return Nothing to return
 *
 */
void exponentialFuncionalTest();
/**
 * Function that tests the logistic system. Will alert if expected results are not met.
 * 
 * \return Nothing to return
 *
 */
void logisticalFuncionalTest();
/**
 * Function that tests the complex system. Will alert if expected results are not met.
 * 
 * \return Nothing to return
 *
 */
void complexFuncionalTest();

#endif