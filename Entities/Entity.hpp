#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Entity {
protected:
	
	sf::RectangleShape shape;
	float movementSpeed;

public:

	Entity();
	virtual ~Entity();

	virtual void move(const float& dt, const float dir_x, const float dir_y);

	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget* target);

};


#endif