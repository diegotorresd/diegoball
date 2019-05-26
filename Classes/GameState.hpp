//
//  GameState.hpp
//  DiegoBall-mobile
//
//  Created by Diego Torres on 29/04/2019.
//

#ifndef GameState_hpp
#define GameState_hpp

class GameState {
    bool _isBallFree;
    int _lives;
public:
    GameState();
    bool isBallFree();
    void setBallFree(bool value);
    int getLives();
    void decreaseLives();
};

#endif /* GameState_hpp */
