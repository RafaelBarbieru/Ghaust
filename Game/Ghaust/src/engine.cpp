#include <stdafx.h>
#include <rng.h>

#include "engine.hpp"
#include "entities/enemies/bedlamite.hpp"

#ifdef _DEBUG
#define CLEAR_WINDOW_BG_COLOR sf::Color(57, 255, 20, 255)
#define VIDEO_MODE_STYLE sf::Style::Titlebar | sf::Style::Close
#endif

#ifndef _DEBUG
#define CLEAR_WINDOW_BG_COLOR sf::Color::Black
#define VIDEO_MODE_STYLE sf::Style::Fullscreen
#endif


/*
	@return void

	Initializes useful inner variables
*/
void Engine::initVars()
{
	m_window = nullptr;
}

/*
	@return void

	Initializes the current window
*/
void Engine::initWindow()
{
	// Initializing the video mode
	m_videoMode.height = sf::VideoMode::getDesktopMode().height - 70;
	m_videoMode.width = sf::VideoMode::getDesktopMode().width;
	m_windowName = "Ghaust";

	// Initializing the window
	m_window = new sf::RenderWindow(
		m_videoMode, 
		m_windowName, 
		VIDEO_MODE_STYLE
	);
}

/*
	@return void

	Polls the events
*/
void Engine::pollEvents()
{
	// Event polling
	while (m_window->pollEvent(m_event))
	{
		switch (m_event.type)
		{

		// Window closure
		case sf::Event::Closed:
			m_window->close();
			break;
		
		// Keyboard events
		case sf::Event::KeyPressed:			
			switch (m_event.key.code)
			{
				// The window can be closed with the Escape key
				case sf::Keyboard::Escape:			
					m_window->close();
					break;
			}
		}
	}
}

/*
	Constructor
*/
Engine::Engine()
{
	this->initVars();
	this->initWindow();
}

/*
	Destructor
*/
Engine::~Engine()
{
	delete this->m_window;
}

/*
	@return bool

	Whether the current window is open
*/
const bool Engine::isRunning() const
{
	return this->m_window->isOpen();
}

/*
	@return void

	Renders the scene, clearing the previous data in the buffer, drawing the new one
	and finally displaying it.
*/
void Engine::render()
{
	// Clear
	this->m_window->clear(CLEAR_WINDOW_BG_COLOR);

	// Draw

	// Drawing background rectangle set to black
	sf::RectangleShape backgroundRectangle(
		sf::Vector2f(
			this->m_window->getSize().x, 
			this->m_window->getSize().y
		)
	);
	backgroundRectangle.setFillColor(sf::Color::Black);
	this->m_window->draw(backgroundRectangle);

	// Drawing a Bedlamite
	unsigned short int randomNumber = RNG::btw0And1();
	printf("%d", randomNumber);
	Bedlamite bedlamite(64, 64, false);
	sf::Sprite bedlamiteSprite = bedlamite.spawn(200, 200);
	this->m_window->draw(bedlamiteSprite);

	// Display
	this->m_window->display();
	
}

void Engine::update()
{	
	// Event polling
	this->pollEvents();
}
