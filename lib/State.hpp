#ifndef STATE_HPP
#define STATE_HPP

#include <SFML/Graphics.hpp>

#include <iostream>
#include <fstream>

#include <vector>
#include <stack>
#include <map>

class State {
private:

	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;

	bool quit;

public:

	State(sf::RenderWindow* window);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateKeybinds(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

#endif