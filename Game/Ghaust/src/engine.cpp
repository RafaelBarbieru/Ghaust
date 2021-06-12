#include <stdafx.h>
#include <rng.h>

#include "engine.h"

#ifdef _DEBUG
#define CLEAR_WINDOW_BG_COLOR sf::Color(57, 255, 20, 255)
#define VIDEO_MODE_STYLE sf::Style::Default
#endif

#ifndef _DEBUG
#define CLEAR_WINDOW_BG_COLOR sf::Color::Black
#define VIDEO_MODE_STYLE sf::Style::Fullscreen
#endif

namespace ghaust
{
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
		m_videoMode.height = 512.f;
		m_videoMode.width = 512.2;
		m_windowName = "Ghaust: Haunted";

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
	void Engine::render(ghaust::GameObject& object)
	{
		// Clear
		this->m_window->clear(CLEAR_WINDOW_BG_COLOR);

		// Draw
		m_window->draw(object.getSprite());

		// Display
		this->m_window->display();

	}

	void Engine::update()
	{
		// Event polling
		this->pollEvents();
	}

}
