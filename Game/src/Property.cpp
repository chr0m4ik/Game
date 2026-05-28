#include "../includes/Property.hpp"
#include <sstream>

// ShapeProperty
ShapeProperty::ShapeProperty(ShapeType s) : shape(s) {}
bool ShapeProperty::matches(const Property& other) const {
    auto* p = dynamic_cast<const ShapeProperty*>(&other);
    return p && p->shape == shape;
}
std::unique_ptr<Property> ShapeProperty::clone() const {
    return std::make_unique<ShapeProperty>(shape);
}
std::string ShapeProperty::toString() const {
    static const char* names[] = {"Circle","Square","Triangle","Star","Rectangle"};
    return std::string("Shape: ") + names[static_cast<int>(shape)];
}
ShapeType ShapeProperty::getShape() const { return shape; }

// ColorProperty
ColorProperty::ColorProperty(ColorType c) : color(c) {}
bool ColorProperty::matches(const Property& other) const {
    auto* p = dynamic_cast<const ColorProperty*>(&other);
    return p && p->color == color;
}
std::unique_ptr<Property> ColorProperty::clone() const {
    return std::make_unique<ColorProperty>(color);
}
std::string ColorProperty::toString() const {
    static const char* names[] = {"Red","Green","Blue","Yellow"};
    return std::string("Color: ") + names[static_cast<int>(color)];
}
ColorType ColorProperty::getColor() const { return color; }

// SizeProperty
SizeProperty::SizeProperty(SizeType s) : size(s) {}
bool SizeProperty::matches(const Property& other) const {
    auto* p = dynamic_cast<const SizeProperty*>(&other);
    return p && p->size == size;
}
std::unique_ptr<Property> SizeProperty::clone() const {
    return std::make_unique<SizeProperty>(size);
}
std::string SizeProperty::toString() const {
    static const char* names[] = {"Small","Medium","Large"};
    return std::string("Size: ") + names[static_cast<int>(size)];
}
SizeType SizeProperty::getSize() const { return size; }