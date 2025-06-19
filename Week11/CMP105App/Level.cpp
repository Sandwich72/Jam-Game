#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
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

	money = new Money(window, &font);
	money->setInput(in);

	for (int i = 0; i < 4; i++)
	{
		lane.push_back(new Lane(&patOnScreen, &beer));
		lane[i]->setPosition(100, 100 * (i + 1));
	}
	//lane.push_back (new Lane(&patOnScreen,&beer));
	//lane.push_back(new Lane(&patOnScreen,&beer));
	//lane[0]->setPosition(100, 100);
	//lane[1]->setPosition(100, 200);
	tapper = new Tapper(&lane,&beer,);
	tapper->setInput(in);
	//tapper->addLanes(&lane);
	//tapper->setPosition(lane[rand() % 4]->getPosition());
	//tapper->setPosition(lane[0]->getPosition().x-32,lane[0]->getPosition().y-32);

	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	mush.handleInput(dt);
	money->handleInput(dt);
	tapper->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	tapper->update(dt);

	for (int i = 0; i < lane.size(); i++)
	{
		lane[i]->update(dt);
	}

	for (int i = 0; i < beer.size(); i++)
	{
		beer[i]->update(dt);

		for (int j = 0; j < patOnScreen.size(); j++)
		{
			if (Collision::checkBoundingBox(beer[i], patOnScreen[j]))
			{
				beer[i]->collisionResponse(patOnScreen[j]);
				patOnScreen[j]->collisionResponse(beer[i]);
			}
		}

		if (beer[i]->getIsDrank())
		{
			delete beer[i];
			beer.erase(beer.begin() + i);
			//money->addMoney(5);
		}
	}


	for (int i = 0; i < patOnScreen.size(); i++)
	{
		patOnScreen[i]->update(dt);
		if (patOnScreen[i]->getSatisfied() == true)
		{
			delete patOnScreen[i];
			patOnScreen.erase(patOnScreen.begin() + i);
		}
	}
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(mush);
	window->draw(*tapper);
	for (int i = 0; i < lane.size(); i++)
	{
		window->draw(*lane[i]);
	}
	for (int i = 0; i < beer.size(); i++)
	{
		window->draw(*beer[i]);
	}
	for (int i = 0; i < patOnScreen.size(); i++)
	{
		window->draw(*patOnScreen[i]);
	}

	window->draw(*money);
	window->draw(money->getText());
	//money->drawText();
	endDraw();
}

