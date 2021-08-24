/*! 
 *  \file stock.h
 */
#ifndef STOCK_H
#define STOCK_H

/// \cond
#include <iostream>
#include <string>
/// \endcond

/*! \class Stock
 *  \brief Part of a group of interacting, interdependent parts that form a complex whole.
 *   
 *  Stocks will storage soma kind of value and will interact with other Stocks through flows.
 */
class Stock {
public:
    /**
     * Virtual destructor.
     *
     */
    virtual ~Stock() {};
    /**
     * Get Name.
     * 
     * \return The name of the Stock.
     *
     */
    virtual std::string getName() const = 0;
    /**
     * Set Name
     * 
     * \param n The name of the Stock.
     * \return Nothing to return.
     *
     */
    virtual void setName(const std::string n) = 0;
    /**
     * Get Value.
     * 
     * \return The current value of the Stock.
     *
     */
    virtual double getValue() const = 0;
    /**
     * Set Value
     * 
     * \param v The desired value for the Stock.
     * \return Nothing to return.
     *
     */
    virtual void setValue(const double v) = 0;
    // Overloading extraction operation
    friend std::ostream& operator<< (std::ostream& os, const Stock &s);
    /**
     * Clone method.
     * 
     * \return Reference to new Stock with copied values.
     *
     */
    virtual Stock* clone() const = 0;
    /**
     * Create method.
     * 
     * \return Reference to Stock.
     *
     */
    virtual Stock* create() const = 0;
};

#endif