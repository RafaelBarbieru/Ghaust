#include "stdafx.h"
#include "engine.h"
#include "entities/enemies/bedlamite/bedlamite.h"

int main()
{
    // Creating the game engine
    ghaust::Engine engine;

    // Creating a Bedlamite
    ghaust::Bedlamite bedlamite(true);

    // Main game loop
    while (engine.isRunning())
    {
        // Update
        engine.update();

        // Render
        engine.render(bedlamite);
    }
	return 0;
}