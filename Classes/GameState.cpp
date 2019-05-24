//
//  GameState.cpp
//  DiegoBall-mobile
//
//  Created by Diego Torres on 29/04/2019.
//

#include "GameState.hpp"

GameState::GameState () {
    _isBallFree = false;
}

void GameState::setBallFree(bool value) {
    _isBallFree = value;
}

bool GameState::isBallFree() {
    return _isBallFree;
}
