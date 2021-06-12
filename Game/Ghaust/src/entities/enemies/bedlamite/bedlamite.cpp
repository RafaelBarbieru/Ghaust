#include <stdafx.h>
#include <rng.h>
#include "bedlamite.h"

namespace ghaust
{
	void Bedlamite::setup()
	{
		// Initializing functional variables
		m_canBeScared = true;
		m_damageType = { DamageType::Sanity };

		// Setting up meta variables
		m_scaleFactor = 4.f;
		m_pathToTextures = "src/entities/enemies/bedlamite/";
		loadTextures();

		// Applying a random texture
		unsigned short int randomNumber = 1;
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
			m_sprite.setScale(m_scaleFactor, m_scaleFactor);
		}
	}

	/*
		@return void

		Loads the possible texture names of the Bedlamite in memory
		by adding them to the member vector m_textures so that
		it can be loaded randomly later.
	*/
	void Bedlamite::loadTextures()
	{
		m_textures.push_back("bedlamite1.png");
		m_textures.push_back("bedlamite2.png");
	}

	/*
		@return void

		Creates a Bedlamite with a random texture in the specified position.
	*/
	sf::Sprite Bedlamite::update(int xPos, int yPos)
	{
		// Updating the Bedlamite's position	
		m_sprite.move(xPos, yPos);
		return m_sprite;
	}

	Bedlamite::Bedlamite(bool shouldBeScaledUp)
	{
		m_trueSize = !shouldBeScaledUp;
		setup();
	}

	Bedlamite::~Bedlamite()
	{

	}
}
