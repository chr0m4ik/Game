#ifndef _FRAME_HPP_
#define _FRAME_HPP_

#include <vector>
#include <memory>
#include <string>
#include "Property.hpp"

class Frame {
public:
    explicit Frame(std::vector<std::unique_ptr<Property>> props);
    Frame(const Frame& other);
    Frame& operator=(const Frame& other);
    Frame(Frame&& other) = default;
    Frame& operator=(Frame&& other) = default;

    std::string toString() const;
    const std::vector<std::unique_ptr<Property>>& getProperties() const;
private:
    std::vector<std::unique_ptr<Property>> properties;
};

#endif // _FRAME_HPP_