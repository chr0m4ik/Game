#include "./includes/ToyFactory.hpp"
#include <cstdlib>
#include <ctime>

static ShapeType randomShape() {
    return static_cast<ShapeType>(rand() % 5);
}
static ColorType randomColor() {
    return static_cast<ColorType>(rand() % 4);
}
static SizeType randomSize() {
    return static_cast<SizeType>(rand() % 3);
}

Toy ToyFactory::createRandomToy(int propertyCount) {
    std::vector<std::unique_ptr<Property>> props;
    if (propertyCount >= 1)
        props.push_back(std::make_unique<ShapeProperty>(randomShape()));
    if (propertyCount >= 2)
        props.push_back(std::make_unique<ColorProperty>(randomColor()));
    if (propertyCount >= 3)
        props.push_back(std::make_unique<SizeProperty>(randomSize()));
    return Toy(std::move(props));
}