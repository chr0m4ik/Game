#include "./includes/FrameFactory.hpp"
#include "./includes/Toy.hpp"
#include <cstdlib>

static ShapeType randomShape() {
    return static_cast<ShapeType>(rand() % 5);
}
static ColorType randomColor() {
    return static_cast<ColorType>(rand() % 4);
}
static SizeType randomSize() {
    return static_cast<SizeType>(rand() % 3);
}

Frame FrameFactory::createRandomFrame(int propertyCount) {
    std::vector<std::unique_ptr<Property>> props;
    if (propertyCount >= 1)
        props.push_back(std::make_unique<ShapeProperty>(randomShape()));
    if (propertyCount >= 2)
        props.push_back(std::make_unique<ColorProperty>(randomColor()));
    if (propertyCount >= 3)
        props.push_back(std::make_unique<SizeProperty>(randomSize()));
    return Frame(std::move(props));
}

Frame FrameFactory::createFrameFromToy(const Toy& toy) {
    std::vector<std::unique_ptr<Property>> clonedProps;
    for (const auto& p : toy.getProperties()) {
        clonedProps.push_back(p->clone());
    }
    return Frame(std::move(clonedProps));
}