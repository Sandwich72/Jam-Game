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
#include"Patron.h"
#include "Lane.h"
#include "Tapper.h"
#include "Beer.h"
#include "Money.h"
class Level : public BaseLevel{
public:
	Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud);
	~Level();

	void handleInput(float dt) override;
	void update(float dt) override;
	void render();

private:
	std::vector <Patron*> patOnScreen;
	std::vector <Lane*> lane;
	std::vector <Beer*> beer;
	Tapper* tapper;
	Clickable mush;
	Money* money;
	sf::Font font;
	// Default variables for level class.
};