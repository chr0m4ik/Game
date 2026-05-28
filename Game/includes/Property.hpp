#ifndef _PROPERTY_HPP_
#define _PROPERTY_HPP_

#include <memory>
#include <string>
#include "Utility.hpp"

class Property {
public:
    virtual ~Property() = default;
    virtual bool matches(const Property& other) const = 0;
    virtual std::unique_ptr<Property> clone() const = 0;
    virtual std::string toString() const = 0;
};

class ShapeProperty : public Property {
public:
    ShapeProperty(ShapeType shape);
    bool matches(const Property& other) const override;
    std::unique_ptr<Property> clone() const override;
    std::string toString() const override;
    ShapeType getShape() const;
private:
    ShapeType shape;
};

class ColorProperty : public Property {
public:
    ColorProperty(ColorType color);
    bool matches(const Property& other) const override;
    std::unique_ptr<Property> clone() const override;
    std::string toString() const override;
    ColorType getColor() const;
private:
    ColorType color;
};

class SizeProperty : public Property {
public:
    SizeProperty(SizeType size);
    bool matches(const Property& other) const override;
    std::unique_ptr<Property> clone() const override;
    std::string toString() const override;
    SizeType getSize() const;
private:
    SizeType size;
};

#endif // _PROPERTY_HPP_