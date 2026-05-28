#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <vector>
#include "Toy.hpp"

class Player {
public:
    void addToy(Toy toy);
    bool selectToy(size_t index);          // index = 1-based
    const Toy* getCurrentToy() const;
    bool hasCurrentToy() const;
    size_t toyCount() const;
    const std::vector<Toy>& getToys() const;
    bool removeCurrentToy();               // returns true if removed
    void clearCurrentToy();                // reset selection
private:
    std::vector<Toy> toys;
    size_t currentToyIndex = 0;            // 0 = none selected
};
#endif //_PLAYER_HPP_