/*! 
 *  \file flow.h
 */
#ifndef FLOW_H
#define FLOW_H

/// \cond
#include <string>
/// \endcond

#include "stock.h"
/*! \class Flow
 *  \brief A flow represents a relationship between entities and determine how energy/mass/force/knowledge will move.
 *   
 *  More text about flow.
 */
class Flow {
public:
    /**
     * Virtual destructor.
     *
     */
    virtual ~Flow() {};
    /**
     * Get Name.
     * 
     * \return The name of the Flow.
     *
     */
    virtual std::string getName() const = 0;
    /**
     * Set Name
     * 
     * \param n The name of the Flow.
     * \return Nothing to return.
     *
     */
    virtual void setName(const std::string n) = 0;
    /**
     * Get Origin.
     * 
     * \return The Stock origin of the Flow.
     *
     */
    virtual Stock* getOrigin() const = 0;
    /**
     * Set Origin
     * 
     * \param o The origin of the Flow.
     * \return Nothing to return.
     *
     */
    virtual void setOrigin(Stock* o) = 0;
    /**
     * Get Destination.
     * 
     * \return The Stock destination of the Flow.
     *
     */
    virtual Stock* getDestination() const = 0;
    /**
     * Set Destination
     * 
     * \param o The destination of the Flow.
     * \return Nothing to return.
     *
     */
    virtual void setDestination(Stock* d) = 0;
    /**
     * Executes the flow. Set to be purely virtual because it will be overwritten in child classes.
     * 
     * \return Value that should be taken from \a origin and added to \a destination.
     *
     */
    virtual double execute() = 0;
    // Cout
    // virtual friend std::ostream& operator<< (std::ostream& os, const Flow &f) = 0;
    /**
     * Create method. Will return the correct concrete child class later on.
     * 
     * \return Reference to Flow.
     *
     */
    virtual Flow* create() const = 0;
};

#endif