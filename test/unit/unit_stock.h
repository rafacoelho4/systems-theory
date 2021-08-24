/*! 
 *  \file unit_stock.h
 */
#ifndef UNIT_STOCK
#define UNIT_STOCK

/// \cond
#include <assert.h>
#include <math.h>
#include <iostream>
/// \endcond

#include "..\..\src\stock_impl.h"

void run_unit_tests_Stock();
/**
 * Unit test constructor.
 *
 */
void unit_Stock_constructor();
/**
 * Unit test destructor.
 *
 */
void unit_Stock_destructor();
/**
 * Unit test get value.
 *
 */
void unit_Stock_getValue();
/**
 * Unit test set value.
 *
 */
void unit_Stock_setValue();
/**
 * Unit test get name.
 *
 */
void unit_Stock_getName();
/**
 * Unit test set name.
 *
 */
void unit_Stock_setName();
/**
 * Unit test atribution operator.
 *
 */
void unit_Stock_atributionOperator();
/**
 * Unit test binary operator.
 *
 */
void unit_Stock_binaryOperators();
/**
 * Unit test stocks that are created without a name.
 *
 */
void unit_Stock_Unnamed_Stock();

#endif

