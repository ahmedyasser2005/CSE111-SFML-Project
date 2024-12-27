#include "../lib/GameState.hpp"

GameState::GameState(sf::RenderWindow* window) : State(window)
{

}

GameState::~GameState()
{
}

void GameState::updateKeybinds(const float& dt)
{
	this->checkForQuit();
}

void GameState::endState()
{
	std::cout << "Ending State...!" << std::endl;
}

void GameState::update(const float& dt)
{
	this->updateKeybinds(dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		std::cout << "Move Left!" << std::endl;
	}
}

void GameState::render(sf::RenderTarget* target = nullptr)
{
}