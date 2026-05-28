#include "./includes/GameUI.hpp"
#include "./includes/SceneBuilder.hpp"
#include <iostream>
#include <limits>
#include <string>

void GameUI::run() {
    std::cout << "=== Игра 'Сопоставь предмет' ===\n";
    int difficulty = chooseDifficulty();
    GameScene scene = SceneBuilder::buildScene(difficulty);
    scene.startGame();

    while (!scene.isGameOver()) {
        displayGameInfo(scene);
        auto actions = scene.getAvailableActions();
        int choice = getActionChoice(actions);
        std::vector<int> params;
        if (choice == 2) { // выбрать игрушку
            std::cout << "Введите номер игрушки: ";
            int idx = readInt(1, static_cast<int>(scene.player.toyCount()));
            params.push_back(idx);
        } else if (choice == 3) { // поместить в отверстие
            std::cout << "Введите номер отверстия: ";
            int idx = readInt(1, static_cast<int>(scene.panel.frameCount()));
            params.push_back(idx);
        }
        ActionResult res = scene.processAction(choice, params);
        showMessage(res.message);
        if (res.scoreEarned > 0) {
            std::cout << "Текущий счёт: " << scene.getScore() << "\n";
        }
        if (res.gameOver) break;
    }
    std::cout << "Игра окончена. Финальный счёт: " << scene.getScore() << "\n";
}

int GameUI::chooseDifficulty() {
    std::cout << "Выберите сложность:\n1 - Лёгкая (только форма)\n2 - Средняя (форма+цвет)\n3 - Сложная (форма+цвет+размер)\n";
    return readInt(1, 3);
}

void GameUI::displayGameInfo(const GameScene& scene) {
    std::cout << "\n--- Ход игры ---\n";
    std::cout << "Счёт: " << scene.getScore() << "\n";
    std::cout << "Игрушек осталось: " << scene.player.toyCount() << "\n";
    if (scene.player.hasCurrentToy()) {
        std::cout << "Выбрана игрушка: " << scene.player.getCurrentToy()->toString() << "\n";
    } else {
        std::cout << "Игрушка не выбрана.\n";
    }
}

int GameUI::getActionChoice(const std::vector<std::string>& actions) {
    std::cout << "\nДоступные действия:\n";
    for (size_t i = 0; i < actions.size(); ++i) {
        std::cout << i+1 << ". " << actions[i] << "\n";
    }
    return readInt(1, static_cast<int>(actions.size())) - 1; // возвращаем 0-based
}

std::vector<int> GameUI::getParametersForAction(int action, const GameScene& scene) {
    // Параметры запрашиваются непосредственно перед вызовом, поэтому здесь пусто
    return {};
}

void GameUI::showMessage(const std::string& msg) {
    std::cout << msg << "\n";
}

int GameUI::readInt(int min, int max) {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail() || value < min || value > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Ошибка! Введите число от " << min << " до " << max << ": ";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}