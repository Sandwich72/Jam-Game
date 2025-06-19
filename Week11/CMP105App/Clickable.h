#pragma once
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
class Clickable : public GameObject
{
public:
	Clickable();
	Clickable(sf::RenderWindow* nWindow, sf::Font* font);
	~Clickable();
	virtual void clickResponse();
	bool click();
	void handleInput(float dt);
	virtual void update(float dt);
	void drawText();
	sf::Text getText();

protected:
	enum States { UP, OVER, DOWN };
	bool isMouseOver;
	sf::Texture sprite[3];
	bool clicked;
	sf::RenderWindow* window;
	sf::Text text;
};

