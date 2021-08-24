/*! 
 *  \file unit_flow.h
 */
#ifndef UNIT_FLOW
#define UNIT_FLOW

/// \cond
#include <assert.h>
#include <math.h>
#include <iostream>
/// \endcond

#include "..\..\src\flow_impl.h"
#include "..\..\src\stock_impl.h"

void run_unit_tests_Flow();
/**
 * Unit test constructor.
 *
 */
void unit_Flow_constructor();
/**
 * Unit test destructor.
 *
 */
void unit_Flow_destructor();
/**
 * Unit test get name.
 *
 */
void unit_Flow_getName();
/**
 * Unit test set name.
 *
 */
void unit_Flow_SetName();
/**
 * Unit test get origin.
 *
 */
void unit_Flow_getOrigin();
/**
 * Unit test set origin.
 *
 */
void unit_Flow_SetOrigin();
/**
 * Unit test get destination.
 *
 */
void unit_Flow_getDestination();
/**
 * Unit test set destination.
 *
 */
void unit_Flow_SetDestination();

#endif

