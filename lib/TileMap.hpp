#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable
{
private:

    sf::VertexArray m_vertices;
    sf::Texture     m_tileset;

   /* void draw(sf::RenderTarget&, sf::RenderStates) const override;*/

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        // apply the transform
        states.transform *= getTransform();

        // apply the tileset texture
        states.texture = &this->m_tileset;

        // draw the vertex array
        target.draw(this->m_vertices, states);
    }

public:

    bool load(const std::filesystem::path&, sf::Vector2u, const int*, unsigned int, unsigned int);
};

#endif