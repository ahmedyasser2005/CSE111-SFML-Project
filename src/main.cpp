#include "../lib/Game.hpp"

// Code Documentation

/*	Ahmed Yasser Eissa

	What I have done so far:
////- Created the Game class (The class that links everything together)
		|-> Created the initWindow function
			runs: when initializing the application window
			responsible: for initializing the application window with the settings from the config file named "window.ini"
			importance: ensures the game window is set up correctly with the desired settings

		|-> Created the initKeys function
			runs: when initializing the supported keys
			responsible: for initializing the supported keys for the game such as W, A, S, D
			importance: allows the game to recognize and respond to key inputs

		|-> Created the initStates function
			runs: when initializing the game states
			responsible: for initializing the game states, starting with the GameState
			importance: sets up the initial state of the game, which is crucial for game flow

		|-> Created the updateDt function
			runs: every frame
			responsible: for updating the delta time, which is the time between the last frame and the current frame
			importance: ensures the game runs at a consistent speed across different machines

		|-> Created the eventUpdate function
			runs: every frame
			responsible: for catching/detecting events/actions happening in the game, such as mouse clicks and keyboard inputs
			importance: allows the game to respond to user inputs and other events

		|-> Created the endApplication function
			runs: before closing the game
			responsible: for performing actions before the game closes, such as saving the game state or settings
			importance: ensures important tasks are completed before the game exits

		|-> Created the update function
			runs: every frame
			responsible: for the main game loop, updating delta time, events, and rendering the game
			importance: keeps the game running and updating correctly

		|-> Created the render function
			runs: every frame
			responsible: for drawing everything in the game, such as the player, enemies, bullets, and background
			importance: ensures the game visuals are updated and displayed correctly

		|-> Created the run function
			runs: to start the game loop
			responsible: for calling the update function/game loop
			importance: triggers the update function to start running

		|-> Created the constructor
			runs: when the game object is created
			responsible: for initializing the game window, game states, supported keys, and other necessary components
			importance: sets up the game correctly when it starts

		|-> Created the destructor
			runs: when the game object is destroyed
			responsible: for deleting the game window, game states, and supported keys
			importance: prevents memory leaks by cleaning up dynamically allocated memory

////- Created the State class (Serves as an interface class for other inherited class of type state)
		|-> Created the constructor
			runs: when the state object is created
			responsible: for initializing the state window, supported keys, and other necessary components
			importance: sets up the state correctly when it starts

		|-> Created the destructor
			runs: when the state object is destroyed
			responsible: for deleting the state window, supported keys, and other components
			importance: prevents memory leaks by cleaning up dynamically allocated memory

		|-> Created the endState function
			runs: when the state is about to end
			responsible: for performing actions before the state ends, such as saving the state
			importance: ensures important tasks are completed before the state exits

		|-> Created the updateInput function
			runs: every frame
			responsible: for updating/catching/detecting input, such as player movement and shooting
			importance: allows the state to respond to user inputs

		|-> Created the update function
			runs: every frame
			responsible: for updating the state, such as player movement and shooting
			importance: keeps the state running and updating correctly

		|-> Created the render function
			runs: every frame
			responsible: for rendering the state, such as the player, enemies, bullets, and background
			importance: ensures the state visuals are updated and displayed correctly

		|-> Created the getQuit function
			runs: when checking if the state is about to end
			responsible: for returning the quit variable
			importance: checks if the state is about to end

		|-> Created the checkForQuit function
			runs: when checking if the state is about to end
			responsible: for checking if the state is about to end
			importance: ensures the state can end correctly

////- Created the GameState class (Inherited from State class)
		* Serves as the main game state
		* Every other state is built on top of this state inside the stack

*/

int main() {
	Game CSE111_SFML_Game_Project;
	CSE111_SFML_Game_Project.run();
}