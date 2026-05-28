#ifndef _TOY_HPP_
#define _TOY_HPP_

#include <vector>
#include <memory>
#include <string>
#include "Property.hpp"

class Frame;

class Toy {
public:
    explicit Toy(std::vector<std::unique_ptr<Property>> props);
    Toy(const Toy& other);
    Toy& operator=(const Toy& other);
    Toy(Toy&& other) = default;
    Toy& operator=(Toy&& other) = default;

    bool matchesFrame(const Frame& frame) const;
    std::string toString() const;
    const std::vector<std::unique_ptr<Property>>& getProperties() const;
private:
    std::vector<std::unique_ptr<Property>> properties;
};

#endif // _TOY_HPP_