#ifndef _GAMEUI_HPP_
#define _GAMEUI_HPP_

#include "GameScene.hpp"

class GameUI {
public:
    void run();
private:
    int chooseDifficulty();
    void displayGameInfo(const GameScene& scene);
    int getActionChoice(const std::vector<std::string>& actions);
    std::vector<int> getParametersForAction(int action, const GameScene& scene);
    void showMessage(const std::string& msg);
    int readInt(int min, int max);
};
#endif // _GAMEUI_HPP_