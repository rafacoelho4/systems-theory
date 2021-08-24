/*! 
 *  \file flow_impl.h
 */
#ifndef FLOW_IMPL_H
#define FLOW_IMPL_H

/// \cond
#include <string>
/// \endcond

#include "flow.h"
/*! \class FlowImpl
 *  \brief FlowImpl brief description
 *   
 */
class FlowImpl : public Flow {
protected:
    std::string name; /**< The name of the Flow. */
    Stock* origin; /**< The Stock that originates the Flow. */
    Stock* destination; /**< The Stock that the Flow targets. */
    int id; /**< Unnamed Flows will receive default name like default1, default2... */
    static int unnamed_counter() {
        static int unnamed_counter = 1;
        return unnamed_counter++;
    }
public:
    /**
     * Default constructor for Flow class.
     *
     */
    FlowImpl();
    /**
     * Constructor for Flow class that sets the name.
     * 
     * \param name Name of the Flow.
     *
     */
    FlowImpl(const std::string name);
    /**
     * Constructor for Flow class that sets the name, origin Stock and destination Stock.
     * 
     * \param name Name of the Flow.
     * \param origin The Stock that the flow originates from.
     * \param destination Where the flow will go.
     *
     */
    FlowImpl(const std::string name, Stock* origin, Stock*destination);
    /**
     * Virtual destructor.
     *
     */
    virtual ~FlowImpl();
    /**
     * Get Name.
     * 
     * \return The name of the Flow.
     *
     */
    std::string getName() const;
    /**
     * Set Name
     * 
     * \param n The name of the Flow.
     * \return Nothing to return.
     *
     */
    void setName(const std::string n);
    /**
     * Get Origin.
     * 
     * \return The Stock origin of the Flow.
     *
     */
    Stock* getOrigin() const;
    /**
     * Set Origin
     * 
     * \param o The origin of the Flow.
     * \return Nothing to return.
     *
     */
    void setOrigin(Stock* o);
    /**
     * Get Destination.
     * 
     * \return The Stock destination of the Flow.
     *
     */
    Stock* getDestination() const;
    /**
     * Set Destination
     * 
     * \param o The destination of the Flow.
     * \return Nothing to return.
     *
     */
    void setDestination(Stock* d);
    /**
     * Executes the flow. Set to be purely virtual because it will be overwritten in child classes.
     * 
     * \return Value that should be taken from \a origin and added to \a destination.
     *
     */
    virtual double execute() = 0;
    // Cout
    friend std::ostream& operator<< (std::ostream& os, const Flow &f); 
    virtual Flow* create() const = 0;
private:
    /**
     * Copy constructor set to private.
     * 
     * \param f Flow that will be copied.
     *
     */
    FlowImpl(const FlowImpl&f);
    /**
     * Operator for atribution overloaded and set to private.
     * 
     * \param f Address to Flow that will be copied.
     * \return Reference to Flow that now has the same atributes as the argument \a f
     *
     */
    FlowImpl& operator= (const FlowImpl&f);
};

/*! \class ExponentialFlow
 *  \brief Flow that dictates the relationship between Stocks to be: 0.01 * origin;
 *   
 *  More text about exponential flow.
 */
class ExponentialFlow : public FlowImpl {
public:
    /**
     * Default constructor for ExponentialFlow class.
     *
     */
    ExponentialFlow();
    /**
     * Constructor for ExponentialFlow class that sets the name.
     * 
     * \param name Name of the Flow.
     *
     */
    ExponentialFlow(const std::string name);
    /**
     * Constructor for ExponentialFlow class that sets the name, origin Stock and destination Stock.
     * 
     * \param name Name of the flow.
     * \param origin The Stock that the flow originates from.
     * \param destination Where the flow will go.
     *
     */
    ExponentialFlow(const std::string name, Stock* origin, Stock*destination);
    /**
     * Virtual destructor.
     *
     */
    virtual ~ExponentialFlow();
    /**
     * Overwrites the function execute from parent class Flow. 
     * Has the same goal: to calculate the value that will pass from origin to destination.
     * 
     * \return Value that should be taken from \a origin and added to \a destination.
     *
     */
    double execute();
    /**
     * Create function overwriting its parent's create abstract function.
     * 
     * \return New ExponentialFlow pointer variable;
     *
     */
    ExponentialFlow* create() const;
};

/*! \class LogisticFlow
 *  \brief Flow that dictates the relationship between Stocks to be: 0.01 * destination * (1 - destination/70);
 *   
 *  More text about logistic flow.
 */
class LogisticFlow : public FlowImpl {
public:
    /**
     * Default constructor for LogisticFlow class.
     *
     */
    LogisticFlow();
    /**
     * Constructor for LogisticFlow class that sets the name.
     * 
     * \param name Name of the Flow.
     *
     */
    LogisticFlow(const std::string name);
    /**
     * Constructor for LogisticFlow class that sets the name, origin Stock and destination Stock.
     * 
     * \param name Name of the flow.
     * \param origin The Stock that the flow originates from.
     * \param destination Where the flow will go.
     *
     */
    LogisticFlow(const std::string name, Stock* origin, Stock*destination);
    /**
     * Virtual destructor.
     *
     */
    virtual ~LogisticFlow();
    /**
     * Overwrites the function execute from parent class Flow. 
     * Has the same goal: to calculate the value that will pass from origin to destination.
     * 
     * \return Value that should be taken from \a origin and added to \a destination.
     *
     */
    double execute();
    /**
     * Create function overwriting its parent's create abstract function.
     * 
     * \return New LogisticFlow pointer variable;
     *
     */
    LogisticFlow* create() const;
};

#endif