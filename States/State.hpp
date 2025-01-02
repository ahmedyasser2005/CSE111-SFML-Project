#ifndef STATE_HPP
#define STATE_HPP

#include "../Entities/Entity.hpp"

class State {
protected:

	sf::RenderWindow *window;
	std::map<std::string, int> *supportedKeys;
	bool quit;

	// Reources
	std::vector<sf::Texture> textures;


public:

	State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
	virtual ~State();

	const bool& getQuit() const;

	virtual void checkForQuit();

	virtual void endState() = 0;
	virtual void updateInput(const float& dt) = 0;
	virtual void update(const float& dt) = 0;
	virtual void render(sf::RenderTarget* target = nullptr) = 0;

};

#endif