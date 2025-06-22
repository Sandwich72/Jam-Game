#include "Home.h"

Home::Home(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	window->setFramerateLimit(60);
	font.loadFromFile("font/vhs-gothic.ttf");
	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	
	//UI

	mush.setPosition(window->getDefaultView().getCenter());
	mush.setInput(in);

	test.setPosition(window->getDefaultView().getCenter().x+64, window->getDefaultView().getCenter().y);
	test.setInput(in);

	bgSprite.loadFromFile("gfx/home.png");
	bg.setTexture(&bgSprite);
	bg.setSize(sf::Vector2f(bgSprite.getSize()));
	bg.setOrigin(bg.getSize().x / 2, bg.getSize().y / 2);
	bg.setPosition(window->getDefaultView().getCenter());

	for (int i = 0; i < 8; i++)
	{
		passTimes[i] = new PassTimes(window, &font, i);
		passTimes[i]->setInput(in);
	}

	
}
Home::~Home()
{
}

void Home::handleInput(float dt)
{
	mush.handleInput(dt);
	test.handleInput(dt);
	for (int i = 0; i < 8; i++)
	{
		passTimes[i]->handleInput(dt);
	}
}

void Home::update(float dt)
{
	if (mush.click())
	{
		gameState->setCurrentState(State::BARLEVEL);
	}
	if (test.click())
	{
		sf::Vector2i mouse = { input->getMouseX(), input->getMouseY() };
		mouse = { static_cast<int>(window->mapPixelToCoords(mouse).x),static_cast<int>(window->mapPixelToCoords(mouse).y) };
		test.setPosition(mouse.x, mouse.y);
		std::cout << "X." << mouse.x << "		Y." << mouse.y << std::endl;
	}
	for (int i = 0; i < 8; i++)
	{
		passTimes[i]->update(dt);
	}
}

void Home::render()
{
	beginDraw();
	window->draw(bg);
	window->draw(mush);
	//window->draw(test);
	for (int i = 0; i < 8; i++)
	{
		//window->draw(*passTimes[i]);
		//window->draw(passTimes[i]->getText());
	}
	endDraw();
}

