#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/BaseLevel.h"
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include"Framework/Collision.h"
#include <string>
#include <iostream>
#include "Clickable.h"
#include"PassTimes.h"

class Home : public BaseLevel
{
public:
	Home(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Home();


	void handleInput(float dt);
	void update(float dt);
	void render();
private:
	sf::RectangleShape bg;
	sf::Texture bgSprite;
	sf::Font font;
	Clickable mush;
	Clickable test;
	enum  Stuff
	{
		BED,
		BOOK,
		GAME,
		COOK,
		BATH,
		POOP,
		TV,
		WORK,

	};
	PassTimes* passTimes[8];
};

