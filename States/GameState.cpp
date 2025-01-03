#include "GameState.hpp"

void GameState::initKeybinds()
{

	std::ifstream ifs(static_cast<std::string>(SOLUTION_DIR) + "config/gamestate_keybinds.ini");
	if (ifs.is_open()) {
		
		std::string action = "";
		std::string key = "";

		while (ifs >> action >> key) {
			this->keybinds[action] = this->supportedKeys->at(key);
		}

	}

	ifs.close();

	// Debug Purposes
	for (auto& i : this->keybinds) {
		std::cout << "Bind: " << i.first << ",\t\tKey: " << i.second << '\n';
	} std::cout << '\n';
}

// Constructor
GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys)
	: State(window, supportedKeys)
{
	this->initKeybinds();
}

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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode(this->keybinds.at("MOVE_UP")))) {
		this->player.move(dt, 0.f, -1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode(this->keybinds.at("MOVE_LEFT")))) {
		this->player.move(dt, -1.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode(this->keybinds.at("MOVE_DOWN")))) {
		this->player.move(dt, 0.f, 1.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode(this->keybinds.at("MOVE_RIGHT")))) {
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