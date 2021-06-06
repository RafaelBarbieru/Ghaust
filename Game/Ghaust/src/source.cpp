#include "stdafx.h"
#include "engine.hpp"

int main()
{
    // Creating the game engine
    Engine engine;

    // Main game loop
    while (engine.isRunning())
    {
        // Update
        engine.update();

        // Render
        engine.render();
    }
	return 0;
}