#include "./includes/GameScene.hpp"

GameScene::GameScene(Player p, Panel pan, int diff)
    : player(std::move(p)), panel(std::move(pan)), score(0), difficultyLevel(diff), gameOver(false) {}

void GameScene::startGame() {
    gameOver = false;
    score = 0;
}

std::vector<std::string> GameScene::getAvailableActions() const {
    std::vector<std::string> actions;
    actions.push_back("Посмотреть игрушки");
    actions.push_back("Посмотреть отверстия");
    actions.push_back("Выбрать игрушку");
    actions.push_back("Поместить игрушку в отверстие");
    actions.push_back("Завершить игру");
    return actions;
}

int GameScene::calculatePoints() const {
    // база 10 очков * сложность
    return 10 * difficultyLevel;
}

ActionResult GameScene::processAction(int action, const std::vector<int>& params) {
    ActionResult res{false, "", gameOver, 0};

    if (action == 0) {
        std::string msg = "Ваши игрушки:\n";
        const auto& toys = player.getToys();
        if (toys.empty()) msg += "Нет игрушек.\n";
        else {
            for (size_t i = 0; i < toys.size(); ++i) {
                msg += std::to_string(i+1) + ". " + toys[i].toString() + "\n";
            }
        }
        res.message = msg;
        res.success = true;
    }
    else if (action == 1) {
        std::string msg = "Отверстия на панели:\n";
        const auto& frames = panel.getAllFrames();
        for (size_t i = 0; i < frames.size(); ++i) {
            msg += std::to_string(i+1) + ". " + frames[i].toString() + "\n";
        }
        res.message = msg;
        res.success = true;
    }
    else if (action == 2) {
        if (params.empty()) {
            res.message = "Не указан номер игрушки.";
            return res;
        }
        int idx = params[0];
        if (player.selectToy(idx)) {
            res.message = "Выбрана игрушка №" + std::to_string(idx);
            res.success = true;
        } else {
            res.message = "Неверный номер игрушки.";
        }
    }
    else if (action == 3) {
        if (!player.hasCurrentToy()) {
            res.message = "Сначала выберите игрушку (действие 2).";
            return res;
        }
        if (params.empty()) {
            res.message = "Не указан номер отверстия.";
            return res;
        }
        int holeIdx = params[0];
        const Frame* frame = panel.getFrame(holeIdx);
        if (!frame) {
            res.message = "Неверный номер отверстия.";
            return res;
        }
        const Toy* toy = player.getCurrentToy();
        if (toy->matchesFrame(*frame)) {
            // Успех!
            int points = calculatePoints();
            score += points;
            player.removeCurrentToy();
            res.scoreEarned = points;
            res.success = true;
            if (player.toyCount() == 0) {
                gameOver = true;
                res.gameOver = true;
                res.message = "Игрушки закончились! Игра завершена.\nВаш счёт: " + std::to_string(score);
            } else {
                res.message = "Успех! Игрушка подошла. +" + std::to_string(points) + " очков.";
            }
        } else {
            res.message = "Неудача! Эта игрушка не подходит для данного отверстия.";
        }
    }
    else if (action == 4) {
        gameOver = true;
        res.gameOver = true;
        res.success = true;
        res.message = "Игра завершена досрочно. Финальный счёт: " + std::to_string(score);
    }
    else {
        res.message = "Неизвестное действие.";
    }
    return res;
}

int GameScene::getScore() const { return score; }
bool GameScene::isGameOver() const { return gameOver; }

Player& GameScene::getPlayer() { return player; }
const Player& GameScene::getPlayer() const { return player; }
Panel& GameScene::getPanel() { return panel; }
const Panel& GameScene::getPanel() const { return panel; }