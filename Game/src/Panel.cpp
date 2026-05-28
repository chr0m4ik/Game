#include "../includes/Panel.hpp"

void Panel::addFrame(Frame frame) {
    frames.push_back(std::move(frame));
}

const Frame* Panel::getFrame(size_t index) const {
    if (index < 1 || index > frames.size()) return nullptr;
    return &frames[index - 1];
}

size_t Panel::frameCount() const {
    return frames.size();
}

const std::vector<Frame>& Panel::getAllFrames() const {
    return frames;
}