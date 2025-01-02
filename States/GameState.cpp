#include "GameState.hpp"

// Constructor
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys) : State(window, supportedKeys) {}

// Destructor
GameState::~GameState()
{

}



void GameState::endState()
{
	std::cout << "Ending State...!" << std::endl;
}

void GameState::updateInput(const float& dt)
{
	// Checks if user pressed ESC key which means he closes the game!
	this->checkForQuit();

	// Update Player Input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		this->player.move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->player.move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->player.move(dt, 0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->player.move(dt, 1.f, 0.f);
	}
}

void GameState::update(const float& dt)
{
	this->updateInput(dt);

	this->player.update(dt);
}

void GameState::render(sf::RenderTarget* target = nullptr)
{
	if (!target) {
		target = this->window;
	}
	this->player.render(target);
}