/*! 
 *  \file model.h
 */
#ifndef MODEL_H
#define MODEL_H

/// \cond
#include <iostream>
#include <string>
#include <list>
/// \endcond

#include "flow.h"
/*! \class Model
 *  \brief A model represents a scenario where stocks and flows will act upon a certain period of time.
 *   
 *  More text about model.
 */
class Model {
public:
    /**
     * Virtual destructor.
     *
     */
    virtual ~Model() {};
    /**
     * Get Name.
     * 
     * \return The name of the Model.
     *
     */
    virtual std::string getName() const = 0;
    /**
     * Set Name
     * 
     * \param n The name of the Model.
     * \return Nothing to return.
     *
     */
    virtual void setName(const std::string n) = 0;
    /**
     * Execution function that runs the model.
     * 
     * \param start The initial time. Set to be 0 if not informed.
     * \param end When the execution will end. Set to be 100 if not informed.
     * \param increment The increment of time. Set to be 1 if not informed.
     * \return Nothing to return.
     *
     */
    virtual void execute(const int start, const int end, const int increment) = 0;
    /**
     * Adds a Stock to a Model.
     * 
     * \param s The Stock that will be added.
     * \return Nothing to return.
     *
     */
    virtual void add(Stock&s) = 0;
    /**
     * Adds a Flow to a Model.
     * 
     * \param f The Flow that will be added.
     * \return Nothing to return.
     *
     */
    virtual void add(Flow&f) = 0;
    /**
     * Lists the result of the execution of the model.
     *
     */
    virtual void report() = 0;
    /**
     * Factory Method for creating Stocks. The new Stock is added to stock_list.
     * 
     * \return Reference to Stock that was just created.
     *
     */
    // virtual Stock* createStock(Stock *s) = 0;
    virtual Stock* createStock(const std::string name, const double value) = 0;
    /**
     * Factory Method for creating Flows. The new Flow is added to flow_list.
     * 
     * \return Reference to Flow that was just created.
     *
     */
    // virtual Flow* createFlow(Flow *f) = 0;
    template <typename FLOW>
    Flow* createFlow(const std::string name, Stock* origin, Stock*destination);
    /**
     * Factory Method for creating Model.
     * 
     * \return Reference to Model that was just created.
     *
     */
    Model* createModel(const std::string name);
};

#endif