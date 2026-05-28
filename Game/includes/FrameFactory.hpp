#ifndef _FRAMEFACTORY_HPP_
#define _FRAMEFACTORY_HPP_

#include "Frame.hpp"

class FrameFactory {
public:
    static Frame createRandomFrame(int propertyCount);
    static Frame createFrameFromToy(const Toy& toy); // точная копия свойств
};

#endif // _FRAMEFACTORY_HPP_