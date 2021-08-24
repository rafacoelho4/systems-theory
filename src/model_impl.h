/*! 
 *  \file model_impl.h
 */
#ifndef MODEL_IMPL_H
#define MODEL_IMPL_H

/// \cond
#include <iostream>
#include <string>
#include <list>
/// \endcond
#include "model.h"
// #include "stock_impl.h"

/*! \class Model
 *  \brief A model represents a scenario where stocks and flows will act upon a certain period of time.
 *   
 *  More text about model.
 */
class ModelImpl : public Model {
protected:
    std::string name; /**< The name of the Model */
    int id; /**< Unnamed Models will receive default name like default1, default2... */
    static int unnamed_counter() {
        static int unnamed_counter = 1;
        return unnamed_counter++;
    }
public:
    std::list<Stock*> stock_list; /**< List of Stocks inside the Model */
    std::list<Flow*> flow_list; /**< List of Flows inside the Model */

    std::list<Model*> model_list; /**< List of Flows inside the Model */
    /**
     * Default constructor for Model class.
     *
     */
    ModelImpl();
    /**
     * Constructor for Model class that sets the name.
     * 
     * \param name The name of the Model.
     *
     */
    ModelImpl(const std::string name);
    /**
     * Copy constructor will be useful to copy objects.
     * 
     * \param m Model that will be copied.
     *
     */
    ModelImpl(const ModelImpl&m);
    /**
     * Virtual destructor.
     *
     */
    virtual ~ModelImpl();
    /**
     * Get Name.
     * 
     * \return The name of the Model.
     *
     */
    std::string getName() const;
    /**
     * Set Name
     * 
     * \param n The name of the Model.
     * \return Nothing to return.
     *
     */
    void setName(const std::string n);
    /**
     * Execution function that runs the model.
     * 
     * \param start The initial time. Set to be 0 if not informed.
     * \param end When the execution will end. Set to be 100 if not informed.
     * \param increment The increment of time. Set to be 1 if not informed.
     * \return Nothing to return.
     *
     */
    void execute(const int start = 0, const int end = 100, const int increment = 1);
    /**
     * Adds a Stock to a Model.
     * 
     * \param s The Stock that will be added.
     * \return Nothing to return.
     *
     */
    void add(Stock&s);
    /**
     * Adds a Flow to a Model.
     * 
     * \param f The Flow that will be added.
     * \return Nothing to return.
     *
     */
    void add(Flow&f);
    /**
     * Operator for atribution overloaded.
     * 
     * \param m Address to Model that will be copied.
     * \return Reference to Model that now has the same atributes as the argument \a m
     *
     */
    ModelImpl& operator= (const ModelImpl&m);
    /**
     * Lists the result of the execution of the model.
     *
     */
    void report();
    // Cout
    friend std::ostream& operator<< (std::ostream& os, const ModelImpl &m);
    /**
     * Factory Method for creating Stocks. The new Stock is added to stock_list.
     * 
     * \return Reference to Stock that was just created.
     *
     */
    Stock* createStock(const std::string name, const double value);
    /**
     * Factory Method for creating Flows. The new Flow is added to flow_list.
     * 
     * \return Reference to Flow that was just created.
     *
     */
    template <typename TFLOW>
    Flow* createFlow(const std::string name, Stock* origin, Stock*destination) {
        Flow* f = new TFLOW(name, origin, destination);
        flow_list.push_back(f);
        return f;
    }
    /**
     * Factory Method for creating Model.
     * 
     * \return Reference to Model that was just created.
     *
     */
    Model* createModel(const std::string name);
};

#endif