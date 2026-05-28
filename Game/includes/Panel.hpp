#ifndef _PANEL_HPP_
#define _PANEL_HPP_

#include <vector>
#include "Frame.hpp"

class Panel {
public:
    void addFrame(Frame frame);
    const Frame* getFrame(size_t index) const;  // index 1-based, returns nullptr if invalid
    size_t frameCount() const;
    const std::vector<Frame>& getAllFrames() const;
private:
    std::vector<Frame> frames;
};
#endif //_PANEL_HPP_