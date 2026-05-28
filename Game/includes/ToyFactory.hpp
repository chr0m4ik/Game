#ifndef _TOYFACTORY_HPP_
#define _TOYFACTORY_HPP_

#include "Toy.hpp"

class ToyFactory {
public:
    static Toy createRandomToy(int propertyCount); // 1,2,3
};

#endif // _TOYFACTORY_HPP_