#ifndef _SCENEBUILDER_HPP_
#define _SCENEBUILDER_HPP_

#include "GameScene.hpp"

class SceneBuilder {
public:
    static GameScene buildScene(int difficulty); // difficulty 1..3
};

#endif // _SCENEBUILDER_HPP_