#ifndef GAME_HPP
#define GAME_HPP

#include "../States/GameState.hpp"

class Game {
private:

    // Attributes
    sf::RenderWindow *window;
    std::stack<State *> states;
    sf::Clock dtClock;
    float dt;

    std::map<std::string, int> supportedKeys;

    // Init Functions
    void initWindow();
    void initKeys();
    void initStates();


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