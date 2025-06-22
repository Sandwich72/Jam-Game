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



	bgSprite.loadFromFile("gfx/map (2).png");
	bg.setTexture(&bgSprite);
	bg.setSize(sf::Vector2f(window->getSize()));
	bg.setOrigin(bg.getSize().x / 2, bg.getSize().y / 2);
	bg.setPosition(window->getDefaultView().getCenter());

	//UI


	money = new Money(window, &font);
	money->setInput(in);

	patSpawnedThisRound = 0;
	day=0;

	for (int i = 0; i < 4; i++)
	{
		lane.push_back(new Lane(i, &patOnScreen, &beer,&patSpawnedThisRound,&day));

	}

	tapper = new Tapper(&lane, &beer, money);
	tapper->setInput(in);

}

Level::~Level()
{

}


void Level::endDay()
{
	gameState->setCurrentState(State::HOMELEVEL);
	day++;
	patSpawnedThisRound = 0;
}


// handle user input
void Level::handleInput(float dt)
{
	if (input->isPressed(sf::Keyboard::Escape))
	{
		window->close();
	}

	money->handleInput(dt);
	tapper->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	//std::cout<<audio->getMusic()->getVolume()<<std::endl;
	tapper->update(dt);

	//std::cout << lane[0]->getEndBar().left << "     " << tapper->getPosition().x << std::endl;

	for (int i = 0; i < lane.size(); i++)
	{
		lane[i]->update(dt);



		for (int j = 0; j < beer.size(); j++)
		{
			if (beer[j]->getLane() == i)
			{
				beer[j]->update(dt);
				if (Collision::checkBoundingBox(beer[j], lane[i]->getEndBar()))
				{
					beer[j]->collisionResponse(lane[i]);
				}

				for (int k = 0; k < patOnScreen.size(); k++)
				{
					if (Collision::checkBoundingBox(beer[j], patOnScreen[k]))
					{
						beer[j]->collisionResponse(patOnScreen[k]);
						patOnScreen[k]->collisionResponse(beer[j]);
					}
				}

				if (beer[j]->getIsDrank())
				{
					delete beer[j];
					beer.erase(beer.begin() + j);

				}
			}
		}
		
		for (int j = 0; j < patOnScreen.size(); j++)
		{
			if (patOnScreen[j]->getLane() == i)
			{
				patOnScreen[j]->update(dt);
				if (patOnScreen[j]->getSatisfied() == true)
				{
					delete patOnScreen[j];
					patOnScreen.erase(patOnScreen.begin() + j);
					
				}
			}
		}
	}

	if (maxPatrons[day] == patSpawnedThisRound && patOnScreen.size() == 0)
	{
		endDay();
	}
	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(bg);
	window->draw(*tapper);
	
	for (int i = 0; i < lane.size(); i++)
	{
		window->draw(*lane[i]);
	}
	window->draw(tapper->getBeer());
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
	endDraw();
}



