#pragma once

/*
	This is the class that handles the game engine
*/
class Engine
{
private:
	// Private variables
	sf::RenderWindow* m_window;
	sf::VideoMode m_videoMode;
	sf::Event m_event;
	std::string m_windowName;

	// Private functions
	void initVars();
	void initWindow();
	void pollEvents();
public:
	// Constructors and destructors
	Engine();
	virtual ~Engine();

	// Accessors
	const bool isRunning() const;

	// Functions
	void render();
	void update();
};

