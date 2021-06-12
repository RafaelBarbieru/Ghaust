#pragma once

#include "../../enemies/ghost.h"

namespace ghaust
{
	class Bedlamite : public ghaust::Ghost
	{
	public:
		// Functions
		virtual void setup() override;
		virtual void loadTextures() override;
		virtual sf::Sprite update(const int xPos, const int yPos) override;

		// Constructors and destructors
		Bedlamite(bool shouldBeScaledUp);
		virtual ~Bedlamite();
	};
}


