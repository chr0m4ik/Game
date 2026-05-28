#include "../includes/Toy.hpp"
#include "../includes/Frame.hpp"
#include <sstream>

Toy::Toy(std::vector<std::unique_ptr<Property>> props) : properties(std::move(props)) {}

Toy::Toy(const Toy& other) {
    for (const auto& p : other.properties) {
        properties.push_back(p->clone());
    }
}

Toy& Toy::operator=(const Toy& other) {
    if (this != &other) {
        properties.clear();
        for (const auto& p : other.properties) {
            properties.push_back(p->clone());
        }
    }
    return *this;
}

bool Toy::matchesFrame(const Frame& frame) const {
    const auto& frameProps = frame.getProperties();
    if (properties.size() != frameProps.size()) return false;
    for (size_t i = 0; i < properties.size(); ++i) {
        if (!properties[i]->matches(*frameProps[i]))
            return false;
    }
    return true;
}

std::string Toy::toString() const {
    std::ostringstream oss;
    oss << "Toy [";
    for (size_t i = 0; i < properties.size(); ++i) {
        if (i > 0) oss << ", ";
        oss << properties[i]->toString();
    }
    oss << "]";
    return oss.str();
}

const std::vector<std::unique_ptr<Property>>& Toy::getProperties() const {
    return properties;
}