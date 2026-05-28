#include "../includes/Frame.hpp"
#include <sstream>

Frame::Frame(std::vector<std::unique_ptr<Property>> props) : properties(std::move(props)) {}

Frame::Frame(const Frame& other) {
    for (const auto& p : other.properties) {
        properties.push_back(p->clone());
    }
}

Frame& Frame::operator=(const Frame& other) {
    if (this != &other) {
        properties.clear();
        for (const auto& p : other.properties) {
            properties.push_back(p->clone());
        }
    }
    return *this;
}

std::string Frame::toString() const {
    std::ostringstream oss;
    oss << "Hole [";
    for (size_t i = 0; i < properties.size(); ++i) {
        if (i > 0) oss << ", ";
        oss << properties[i]->toString();
    }
    oss << "]";
    return oss.str();
}

const std::vector<std::unique_ptr<Property>>& Frame::getProperties() const {
    return properties;
}