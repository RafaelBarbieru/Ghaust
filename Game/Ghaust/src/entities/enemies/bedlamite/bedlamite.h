#pragma once

#include "../ghost.h"

class Bedlamite : public Ghost
{
public:
	// Functions
	virtual void setup() override;
	virtual void loadTextures() override;
	virtual sf::Sprite spawn(const int xPos, const int yPos) override;
	
	// Constructors and destructors
	Bedlamite(bool shouldBeScaledUp);
	virtual ~Bedlamite();
};

