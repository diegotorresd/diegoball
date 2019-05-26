//
//  GameState.cpp
//  DiegoBall-mobile
//
//  Created by Diego Torres on 29/04/2019.
//

#include "GameState.hpp"

GameState::GameState () {
    _isBallFree = false;
    _lives = 3;
    _numBricks = 33;
}

void GameState::setBallFree(bool value) {
    _isBallFree = value;
}

bool GameState::isBallFree() {
    return _isBallFree;
}

int GameState::getLives() {
    return _lives;
}

void GameState::decreaseLives() {
    _lives--;
}

int GameState::getNumBricks() {
    return _numBricks;
}

void GameState::decreaseNumBricks() {
    _numBricks--;
}
