/*! 
 *  \file model_impl.cpp
 */
#include "model_impl.h"
#include "stock_impl.h"

ModelImpl::ModelImpl() : name("unnamed") {
    std::string new_name = "default";
    id = unnamed_counter();
    new_name += std::to_string(id);
    name = new_name;
};
ModelImpl::ModelImpl(const std::string n) {
    // If the name passad as argument contains "default", then we discard that name
    // Names with the substring "default" in them are reserved
    if (n.find("default") != std::string::npos) {
        std::string new_name = "default";
        id = unnamed_counter();
        new_name += std::to_string(id);
        name = new_name;
    } else {
        name = n;
    }
};
ModelImpl::ModelImpl(const ModelImpl&m) {
    std::cout << "COPY CONSTRUCTOR FOR MODEL CALLED" << std::endl;
    if(this == &m) return;
    // Free all the stocks
    for(auto it : stock_list) {
        delete it;
    }
    // Free all flows
    for(auto it : flow_list) {
        delete it;
    }
    // Copying stocks
    for(auto it : m.stock_list) {
        Stock *copy = it->clone();
        copy->setName(it->getName());
        copy->setValue(it->getValue());
        stock_list.push_back(copy);
    }
    // Copying flows
    for(auto fit : m.flow_list) {   
        Flow *fcopy = fit->create();
        fcopy->setName(fit->getName());

        // Go through all my new stocks and find the origin and destination
        for(auto sit : stock_list) {
            if(sit->getName() == fit->getOrigin()->getName()) {
                fcopy->setOrigin(sit);
            }
            // not if else because a flow can have the same stock as both origin and destination
            if (sit->getName() == fit->getDestination()->getName()) {
                fcopy->setDestination(sit);
            }
        }
        // After finding the real origin and destination, flow is added to flow_list
        flow_list.push_back(fcopy);
    }
    name = m.name;
};
ModelImpl::~ModelImpl() {
    for(std::list<Stock*>::iterator sit = stock_list.begin(); sit!=stock_list.end(); sit++) {
        delete *sit;
    }

    for(std::list<Flow*>::iterator fit = flow_list.begin(); fit!=flow_list.end(); fit++) {
        delete *fit;
    }

    for(std::list<Model*>::iterator mit = model_list.begin(); mit!=model_list.end(); mit++) {
        delete *mit;
    }

    stock_list.clear();
    flow_list.clear();
    model_list.clear();
};
std::string ModelImpl::getName() const {
    return name;
}
void ModelImpl::setName(std::string n) {
    name = n;
}
void ModelImpl::add(Stock &s) {
    stock_list.push_back(&s);
};
void ModelImpl::add(Flow &f) {
    flow_list.push_back(&f);
};
void ModelImpl::execute(const int start, const int end, const int increment) {
    int m_start = start, m_end = end, m_increment = increment;
    
    if(increment <= 0) m_increment = 1;
    if(end < 0) m_end = 1;
    if(start < 0) m_start = 0;
    if(start >= end) m_start = m_end - 1;

    for(int i = m_start; i < m_end; i+=m_increment) {
        
        std::list<long double> values;
        for(std::list<Flow*>::iterator j = flow_list.begin(); j!=flow_list.end(); j++) {
            values.push_back((*j)->execute());
        }

        std::list<long double>::iterator it = values.begin();
        for(std::list<Flow*>::iterator j = flow_list.begin(); j!=flow_list.end(); j++, it++) {
            (*j)->getOrigin()->setValue((*j)->getOrigin()->getValue() - values.front());
            (*j)->getDestination()->setValue((*j)->getDestination()->getValue() + values.front());

            values.pop_front();
        }
    }
}
ModelImpl& ModelImpl::operator= (const ModelImpl&m) {
    std::cout << "ATRIBUTION OPERATOR FOR MODEL CALLED" << std::endl;
    if(this == &m) return *this;
    // Free all the stocks
    for(auto it : stock_list) {
        delete it;
    }
    // Free all flows
    for(auto it : flow_list) {
        delete it;
    }
    // Copying stocks
    for(auto it : m.stock_list) {
        Stock *copy = it->clone();
        copy->setName(it->getName());
        copy->setValue(it->getValue());
        stock_list.push_back(copy);
    }
    // Copying flows
    for(auto fit : m.flow_list) {   
        Flow *fcopy = fit->create();
        fcopy->setName(fit->getName());

        // Go through all my new stocks and find the origin and destination
        for(auto sit : stock_list) {
            if(sit->getName() == fit->getOrigin()->getName()) {
                fcopy->setOrigin(sit);
            }
            // not if else because a flow can have the same stock as both origin and destination
            if (sit->getName() == fit->getDestination()->getName()) {
                fcopy->setDestination(sit);
            }
        }
        // After finding the real origin and destination, flow is added to flow_list
        flow_list.push_back(fcopy);
    }
    name = m.name;
    return *this;
}
void ModelImpl::report() {
    int i = 0;
    for(std::list<Stock*>::iterator it = stock_list.begin(); it!=stock_list.end(); it++, i++) {
        std::cout << "REPORT" << std::endl;
        std::cout << &(it);
    }
}
std::ostream& operator<< (std::ostream& os, const ModelImpl &m) {
    os << "Model: " << m.getName() << std::endl;
    os << "Stocks: " << std::endl;
    for(std::list<Stock*>::const_iterator it = m.stock_list.begin(); it!=m.stock_list.end(); it++) {
        std::cout << *it;
    }
    os << "Flows: " << std::endl;
    for(std::list<Flow*>::const_iterator it = m.flow_list.begin(); it!=m.flow_list.end(); it++) {
        std::cout << *it;
    }
    return os;
}
Stock* ModelImpl::createStock(const std::string name, const double value) {
    Stock* s = new StockImpl(name, value);
    stock_list.push_back(s);
    return s;
};
Model* ModelImpl::createModel(const std::string name) {
    Model* m = new ModelImpl(name);
    model_list.push_back(m);
    return m;
};