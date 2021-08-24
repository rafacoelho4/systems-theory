/*! 
 *  \file stock_impl.cpp
 */

#include "stock_impl.h"

StockImpl::StockImpl() {
    value = 0;
    std::string new_name = "default";
    id = unnamed_counter();
    new_name += std::to_string(id);
    name = new_name;
};
StockImpl::StockImpl(const double v) {
    value = v;
    std::string new_name = "default";
    id = unnamed_counter();
    new_name += std::to_string(id);
    name = new_name;
};
StockImpl::StockImpl(const std::string n, const double v) {
    value = v;
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
StockImpl::StockImpl(const Stock&s) {
    // std::cout << "Copy constructor stock" << std::endl;
    if(this == &s) return;
    name = s.getName();
    value = s.getValue();
};
StockImpl::~StockImpl() {};
std::string StockImpl::getName() const {
    return name;
}
void StockImpl::setName(std::string n) {
    name = n;
}
double StockImpl::getValue() const {
    return value;
}
void StockImpl::setValue(double v) {
    value = v;
}
StockImpl& StockImpl::operator= (const StockImpl& S) {
    // std::cout << "Atribution operator stock" << std::endl;
    // Guard self assignment
    if(this == &S) return *this;
    name = S.getName();
    value = S.getValue();
    return *this; // allows x = y = z
}
double StockImpl::operator*(const StockImpl&s) const {
    return value * s.getValue();
}
double StockImpl::operator/(const StockImpl&s) const {
    return value / s.getValue();
}
double StockImpl::operator+(const StockImpl&s) const {
    return value + s.getValue();
}
double StockImpl::operator-(const StockImpl&s) const {
    return value - s.getValue();
}

double operator*(const double&value, const StockImpl&s) {
    return value * s.value;
}
double operator/(const double&value, const StockImpl&s) {
    return value / s.value;
}
double operator+(const double&value, const StockImpl&s) {
    return value + s.value;
}
double operator-(const double&value, const StockImpl&s) {
    return value - s.value;
}
std::ostream& operator<< (std::ostream& os, const Stock &s) {
    os << "Stock: " << s.getName() << " - " << s.getValue() << std::endl;
    return os;
}
Stock* StockImpl::clone() const {
    return new StockImpl(*this);
}
Stock* StockImpl::create() const {
    return new StockImpl();
}