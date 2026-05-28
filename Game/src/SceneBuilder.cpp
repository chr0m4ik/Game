#include "./includes/SceneBuilder.hpp"
#include "./includes/ToyFactory.hpp"
#include "./includes/FrameFactory.hpp"
#include <cstdlib>
#include <ctime>

GameScene SceneBuilder::buildScene(int difficulty) {
    // Инициализация random
    static bool seeded = false;
    if (!seeded) { srand(static_cast<unsigned>(time(nullptr))); seeded = true; }

    Player player;
    Panel panel;

    int numToys = 3 + difficulty;
    // Создаём игрушки и для каждой
    for (int i = 0; i < numToys; ++i) {
        Toy toy = ToyFactory::createRandomToy(difficulty);
        player.addToy(std::move(toy));
        Frame matchingFrame = FrameFactory::createFrameFromToy(player.getToys().back());
        panel.addFrame(std::move(matchingFrame));
    }

    // Добавляем 2 еправильных отверстия
    for (int i = 0; i < 2; ++i) {
        Frame randomFrame = FrameFactory::createRandomFrame(difficulty);
        panel.addFrame(std::move(randomFrame));
    }

    return GameScene(std::move(player), std::move(panel), difficulty);
}