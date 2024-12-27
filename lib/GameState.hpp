#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

class GameState : public State {
private:



public:

	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	//void checkForQuit();

	void updateKeybinds(const float& dt);
	
	void endState();
	void update(const float& dt);
	void render(sf::RenderTarget* target);

};


#endif