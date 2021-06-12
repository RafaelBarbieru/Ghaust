#pragma once

#include "entities/gameObject.h"

namespace ghaust
{
	enum class GhostType
	{
		Bedlamite,
		LilCrook,
		Demon
	};

	enum class DamageType
	{
		Sanity,
		Paralysis,
		None
	};

	class Ghost : public ghaust::GameObject
	{
	protected:

		// Protected variables
		// Meta
		sf::Vector2i m_size;					// The sprite's size.
		bool m_trueSize;						// false = is scaled up | true = remains at 64x64 px.
		float m_scaleFactor;					// Multiplying m_size to this will scale up the sprite.
		sf::Sprite m_sprite;					// The current sprite of the ghost.
		sf::Texture m_texture;					// The current texture of the ghost.	
		std::string m_pathToTextures;			// Directory in which the texture images are found.
		std::vector<std::string> m_textures;	// The names of the texture variants the ghost can have.

		// Functional
		bool m_canBeScared;						// Whether the ghost is affected by a Ghost-Spooker.
		std::vector<DamageType> m_damageType;	// The types of damage the ghost does to the player.

		// Protected functions
		virtual void setup() = 0;										// Ghost type setup.
		virtual void loadTextures() = 0;								// Loads the name of the textures the ghost uses.
		virtual sf::Sprite update(const int xPos, const int yPos) = 0;	// Constructs and returns the sprite of the ghost to be drawn;

		// Override functions
		sf::Sprite getSprite() override;
	};
}
