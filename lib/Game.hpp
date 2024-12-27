#ifndef GAME_HPP
#define GAME_HPP

#include "GameState.hpp"
#include "TileMap.hpp"

class Game {
private:

    // Attributes

    sf::RenderWindow *window;
    std::stack<State *> states;
    sf::Clock dtClock;
    float dt;


    TileMap gameMap;
    


    // Init Functions

    void initWindow();
    void initStates();
    void initMap();

    // Regular Functions

    void endApplication();

    // Update Functions

    void updateDt();
    void eventUpdate();
    void update();

    // Render Functions

    void render();


public:

    // Constructor / Destructor

    Game();
    virtual ~Game();



    // Core Functions

    void run();

};

#endif