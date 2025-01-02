#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"

class GameState : public State {
private:

	Entity player;

public:

	GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~GameState();

	//void checkForQuit();

	void endState() override;
	void updateInput(const float& dt) override;
	void update(const float& dt) override;
	void render(sf::RenderTarget* target) override;
};


#endif