#include "./includes/FrameFactory.hpp"
#include "./includes/Toy.hpp"
#include <cstdlib>

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