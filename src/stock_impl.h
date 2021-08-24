/*! 
 *  \file stock_impl.h
 */
#ifndef STOCK_IMPL_H
#define STOCK_IMPL_H

/// \cond
#include <iostream>
#include <string>
/// \endcond

#include "stock.h"

/*! \class Stock Impl
 *  \brief Impl
 *   
 */
class StockImpl : public Stock {
protected:
    std::string name; /**< The name of the Stock. */
    double value; /**< The current value inside the Stock. */
    int id; /**< Unnamed Stocks will receive default name like default1, default2... */
    static int unnamed_counter() {
        static int unnamed_counter = 1;
        return unnamed_counter++;
    }
public:
    /**
     * Default constructor for Stock class. Will set the name to "unnamed" and value to 0.
     *
     */
    StockImpl();
    /**
     * Constructor for Stock class that sets the initial value. Will set the name to "unnamed".
     * 
     * \param value Initial value of the Stock.
     *
     */
    StockImpl(const double value);
    /**
     * Constructor for Stock class that sets the name and the initial value.
     * 
     * \param name Name of the Stock.
     * \param value Inicial value of the Stock. Will be set to 0 if not informed.
     *
     */
    StockImpl(const std::string name, const double value = 0);
    /**
     * Copy constructor will be useful to copy objects.
     * 
     * \param s Stock that will be copied.
     *
     */
    StockImpl(const Stock&s);
    /**
     * Virtual destructor.
     *
     */
    virtual ~StockImpl();
    /**
     * Get Name.
     * 
     * \return The name of the Stock.
     *
     */
    virtual std::string getName() const;
    /**
     * Set Name
     * 
     * \param n The name of the Stock.
     * \return Nothing to return.
     *
     */
    virtual void setName(const std::string n);
    /**
     * Get Value.
     * 
     * \return The current value of the Stock.
     *
     */
    virtual double getValue() const;
    /**
     * Set Value
     * 
     * \param v The desired value for the Stock.
     * \return Nothing to return.
     *
     */
    virtual void setValue(const double v);
    /**
     * Operator for atribution overloaded.
     * 
     * \param s Address to Stock that will be copied.
     * \return Reference to Stock that now has the same atributes as the argument \a s
     *
     */
    virtual StockImpl& operator= (const StockImpl&s);
    // Binary operators overloaded as member function
    double operator*(const StockImpl&s) const; // s1*s2
    double operator/(const StockImpl&s) const; // s1/s2
    double operator+(const StockImpl&s) const; // s1+s2
    double operator-(const StockImpl&s) const; // s1-s2
    // Binary operators overloaded as friend function
    friend double operator*(const double&value, const StockImpl&s); // s1*s2
    friend double operator/(const double&value, const StockImpl&s); // s1/s2
    friend double operator+(const double&value, const StockImpl&s); // s1+s2
    friend double operator-(const double&value, const StockImpl&s); // s1-s2
    // Overloading extraction operation
    friend std::ostream& operator<< (std::ostream& os, const Stock &s);
    /**
     * Clone method.
     * 
     * \return Reference to new Stock with copied values.
     *
     */
    virtual Stock* clone() const;
    /**
     * Create method.
     * 
     * \return Reference to Stock.
     *
     */
    virtual Stock* create() const;
};

#endif