#include <stdafx.h>
#include <rng.h>
#include "bedlamite.hpp"

/*
	@return void

	Loads the possible texture names of the Bedlamite in memory
	by adding them to the member vector m_textures so that
	it can be loaded randomly later.
*/
void Bedlamite::loadTextures()
{
	m_textures.push_back("bedlamite_1.png");
	m_textures.push_back("bedlamite_2.png");
}

void Bedlamite::doDamage()
{
	printf("I'm doing %f damage", damage);
}

/*
	@return void

	Creates a Bedlamite with a random texture in the specified position.
*/
sf::Sprite Bedlamite::spawn(int xPos, int yPos)
{
	// Loading the texture
	sf::Texture texture;
	unsigned short int randomNumber = RNG::btw0And1();	
	bool isTextureLoaded = m_texture.loadFromFile(m_pathToTextures + m_textures.at(randomNumber));
	if (!isTextureLoaded)
	{
		printf("Error occured while trying to load texture");
	}

	// Creating the sprite
	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, m_size.x, m_size.y));

	// Scaling up the sprite if the trueSize boolean is false
	if (!m_trueSize)
	{
		m_sprite.setScale(4, 4);
	}	
	m_sprite.setPosition(xPos, yPos);
	return m_sprite;
}

Bedlamite::Bedlamite(const unsigned int xSize, const unsigned int ySize, bool trueSize)
{
	// Assigning params to member variables
	m_size = sf::Vector2i(xSize, ySize);
	m_trueSize = trueSize;

	// Loading textures names
	loadTextures();
}

Bedlamite::~Bedlamite()
{

}