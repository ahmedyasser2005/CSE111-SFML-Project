#include "Entity.hpp"

Entity::Entity()
{
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
	this->movementSpeed = 200.f;
}

Entity::~Entity()
{

}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
	this->shape.move({ dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt });
}

void Entity::update(const float& dt)
{
	
}

void Entity::render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
