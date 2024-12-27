#include "../lib/Game.hpp"

// Initilizers

// Game Window Initilizer
void Game::initWindow()
{

    // Settings

    std::string  title      = "Config didn't load!";
    unsigned int fps        = 60;
    bool         vsync      = true;
    bool windowMode         = 0;

    // Config File

    std::ifstream ifs("C:\\Users\\ahmed\\source\\repos\\ahmedyasser2005\\CSE111-SFML-Project\\config\\window.ini");
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
void Game::initStates()
{
    this->states.push(new GameState(this->window));
}
// Game Map Initilizer
void Game::initMap()
{
    constexpr std::array level = {
            0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
            1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
            0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
            0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
            0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
            2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
            0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    if (!this->gameMap.load(
        "C:\\Users\\ahmed\\source\\repos\\ahmedyasser2005\\CSE111-SFML-Project\\assets\\tileset.png",
        { 32, 32 },
        level.data(),
        16, 8
    ))
        throw sf::Exception::runtime_error("Couldn't Load the Map!");
}


// Constructor Destructor Functions

// Constuctor
Game::Game()
{
    this->initWindow();
    this->initStates();
    this->initMap();
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
    std::cout << "Ending Application..." << std::endl;
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

        if (!this->states.empty()) {
            this->states.top()->update(this->dt);

            if (this->states.top()->getQuit()) {
            
                this->states.top()->endState();
                delete this->states.top();
                this->states.pop();
            
            }
        }
        else {
            this->endApplication();
            this->window->close();
        }

        // End

        if (event->is<sf::Event::Closed>())
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

    this->window->draw(this->gameMap);

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