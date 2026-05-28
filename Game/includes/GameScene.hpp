#ifndef _GAMESCENE_HPP_
#define _GAMESCENE_HPP_

#include "Player.hpp"
#include "Panel.hpp"
#include <string>
#include <vector>

struct ActionResult {
    bool success;
    std::string message;
    bool gameOver;
    int scoreEarned;
};

class GameScene {
public:
    GameScene(Player player, Panel panel, int difficulty);

    std::vector<std::string> getAvailableActions() const;
    ActionResult processAction(int action, const std::vector<int>& params);
    int getScore() const;
    bool isGameOver() const;
    void startGame();
    
    Player& getPlayer();
    const Player& getPlayer() const;
    Panel& getPanel();
    const Panel& getPanel() const;

private:
    Player player;
    Panel panel;
    int score;
    int difficultyLevel;
    bool gameOver;

    int calculatePoints() const;
};

#endif // _GAMESCENE_HPP_