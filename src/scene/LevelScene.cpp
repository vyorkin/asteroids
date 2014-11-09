#include "scene/LevelScene.hpp"

LevelScene::LevelScene() {
    world = new World();
    entityFactory = new EntityFactory(world->getEntityManager());
}

LevelScene::~LevelScene() {
    delete entityFactory;
    delete world;
}

void LevelScene::onInitialize() {
    auto systemManager = world->getSystemManager();

    systemManager->add(new MovementSystem());
    systemManager->add(new RenderingSystem());
    systemManager->add(new InputSystem());

    reset();
}

void LevelScene::onPlay() {
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
}

void LevelScene::onPause() {
}

void LevelScene::onRender() {
    world->process();
}

void LevelScene::onResize(const Size& size) {
    glViewport(0, 0, size.width, size.height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, size.width, 0.0, size.height);
}

void LevelScene::reset() {
    entityFactory->createPlayer();
    for (int i = 0; i <= 10; i++)
        entityFactory->createAsteriod();
}
