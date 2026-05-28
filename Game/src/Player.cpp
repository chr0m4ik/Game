#include "../includes/Player.hpp"

void Player::addToy(Toy toy) {
    toys.push_back(std::move(toy));
}

bool Player::selectToy(size_t index) {
    if (index < 1 || index > toys.size()) return false;
    currentToyIndex = index - 1;
    return true;
}

const Toy* Player::getCurrentToy() const {
    if (currentToyIndex >= toys.size()) return nullptr;
    return &toys[currentToyIndex];
}

bool Player::hasCurrentToy() const {
    return currentToyIndex < toys.size();
}

size_t Player::toyCount() const {
    return toys.size();
}

const std::vector<Toy>& Player::getToys() const {
    return toys;
}

bool Player::removeCurrentToy() {
    if (currentToyIndex >= toys.size()) return false;
    toys.erase(toys.begin() + currentToyIndex);
    if (toys.empty()) {
        currentToyIndex = 0;
    } else {
        currentToyIndex = 0;
    }
    return true;
}

void Player::clearCurrentToy() {
    currentToyIndex = 0;
}