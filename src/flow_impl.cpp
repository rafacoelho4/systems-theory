/*! 
 *  \file flow_impl.cpp
 */

#include "flow_impl.h"

FlowImpl::FlowImpl() {
    std::string new_name = "default";
    id = unnamed_counter();
    new_name += std::to_string(id);
    name = new_name;
    origin = nullptr;
    destination = nullptr;
};
FlowImpl::FlowImpl(const std::string n) {
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
    origin = nullptr;
    destination = nullptr;
};
FlowImpl::FlowImpl(const std::string n, Stock *o, Stock *d) {
    if (n.find("default") != std::string::npos) {
        std::string new_name = "default";
        id = unnamed_counter();
        new_name += std::to_string(id);
        name = new_name;
    } else {
        name = n;
    }
    origin = o;
    destination = d;
};
FlowImpl::FlowImpl(const FlowImpl&f) : name(f.getName()), origin(f.getOrigin()), destination(f.getDestination()) {};
FlowImpl::~FlowImpl() {};
std::string FlowImpl::getName() const {
    return name;
}
void FlowImpl::setName(const std::string n) {
    name = n;
}
Stock* FlowImpl::getOrigin() const {
    return origin;
};
void FlowImpl::setOrigin(Stock* o) {
    origin = o;
};
Stock* FlowImpl::getDestination() const {
    return destination;
};
void FlowImpl::setDestination(Stock* d) {
    destination = d;
};
FlowImpl& FlowImpl::operator= (const FlowImpl& F) {
    if(this == &F) return *this;
    origin = F.origin;
    destination = F.destination;
    return *this;
}
std::ostream& operator<< (std::ostream& os, const Flow &f) {
    os << "FlowImpl: " << f.getName() << std::endl;
    os << "Origem: " << f.getOrigin()->getName() << " - " << f.getOrigin()->getValue() << std::endl;
    os << "Destino: " << f.getDestination()->getName() << " - " << f.getDestination()->getValue() << std::endl;
    return os;
}

ExponentialFlow::ExponentialFlow() {};
ExponentialFlow::ExponentialFlow(const std::string name) : FlowImpl(name) {};
ExponentialFlow::ExponentialFlow(const std::string name, Stock* origin, Stock*destination) : FlowImpl(name, origin, destination) {};
ExponentialFlow::~ExponentialFlow() {};
double ExponentialFlow::execute() {
    return 0.01 * getOrigin()->getValue();
};
ExponentialFlow* ExponentialFlow::create() const {
    return new ExponentialFlow();
}

LogisticFlow::LogisticFlow() {};
LogisticFlow::LogisticFlow(const std::string name) : FlowImpl(name) {};
LogisticFlow::LogisticFlow(const std::string name, Stock* origin, Stock*destination) : FlowImpl(name, origin, destination) {};
LogisticFlow::~LogisticFlow() {};
double LogisticFlow::execute() {
    return 0.01 * getDestination()->getValue() * (1 - getDestination()->getValue()/70);
};
LogisticFlow* LogisticFlow::create() const {
    return new LogisticFlow();
}