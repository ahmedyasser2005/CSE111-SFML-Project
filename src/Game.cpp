#include "../lib/Game.hpp"

// Initilizers

// Game Window Initilizer
void Game::initWindow()
{

    // Settings

    std::string  title      = "Config didn't load!";
    unsigned int fps        = 60;
    bool         vsync      = true;
    bool         windowMode = 0;


	//std::cout << std::filesystem::current_path() << '\n';     // Debugging Purposes

    // Config File
	std::ifstream ifs(static_cast<std::string>(SOLUTION_DIR) + "config/window.ini"); // SOLUTION_DIR is a macro that returns the path to the solution directory and it's defined in CMakeLists.txt
    if (ifs.is_open()) {
        getline(ifs, title);
        ifs >> fps;
        ifs >> vsync;      // 0 for Disable, 1 for Enable
        ifs >> windowMode; // 0 for Windowed, 1 for Fullscreen

        ifs.close();
    }



    // Initlizing

    this->window = new sf::RenderWindow(sf::VideoMode({ 1024u, 720u }), title, sf::Style::Default, static_cast<sf::State>(windowMode));
    this->window->setFramerateLimit(fps);
    this->window->setVerticalSyncEnabled(vsync);
}

void Game::initKeys()
{
    std::ifstream ifs(static_cast<std::string>(SOLUTION_DIR) + "config/supported_keys.ini");
    if (ifs.is_open()) {
        std::string key = "";
        int key_value = 0;
        while (ifs >> key >> key_value) {
            this->supportedKeys[key] = key_value;
        }
    }
    ifs.close();

	// Debug Purposes
	for (auto i : this->supportedKeys) {
		std::cout << "Key: " << i.first << ",\t\tCode: " << i.second << '\n';
	} std::cout << '\n';
}

void Game::initStates()
{
    this->states.push(new GameState(this->window, &this->supportedKeys));
}



// Constructor Destructor Functions

// Constuctor
Game::Game()
{
    this->initWindow();
    this->initKeys();
    this->initStates();
}
// Destructor
Game::~Game()
{
    delete this->window;

    while (!this->states.empty()) {
        delete this->states.top();
        this->states.pop();
    }

}



// Regular Functions

void Game::endApplication()
{
    std::cout << "Ending Application..." << '\n';
}



// Update Functions

// Updates the dt variable with the time it takes to update & render 1 frame.
void Game::updateDt()
{
    this->dt = this->dtClock.restart().asSeconds();
}

// Catches events (Any Action exp: Mouse Click!)
void Game::eventUpdate()
{
    while (const std::optional event = this->window->pollEvent())
    {
        // Catch Events Here

		if (!this->states.empty()) { // If not empty update the state and check if it's time to quit the state.
            this->states.top()->update(this->dt);

            if (this->states.top()->getQuit()) {
            
                this->states.top()->endState();
                delete this->states.top();
                this->states.pop();
            
            }
        }
        else { // If empty just close the program
            this->endApplication();
            this->window->close();
        }

        // End

		if (event->is<sf::Event::Closed>()) // If the user closes the window
        {
            this->window->close();
        }
    }
}

// Updates game state
void Game::update()
{
    this->updateDt();
    this->eventUpdate();
    this->render();
}



// Core Functions

// Draw Items in the screen
void Game::render()
{
    this->window->clear();

    // Draw Things Here
    
    if (!this->states.empty()) {
        states.top()->render(this->window);
    }

    // End

    this->window->display();
}

// Start The Game
void Game::run()
{
    // Game Loop
    while (this->window->isOpen())
    {
        update();
    }
}