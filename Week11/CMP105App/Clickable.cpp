#include "Clickable.h"
#include <iostream>
Clickable::Clickable()
{
	window = nullptr;
	isMouseOver = false;

	for (size_t i = 0; i < 3; i++)
	{
		sprite[i].loadFromFile("gfx/PlaySheet.png", sf::IntRect(i * 64, 0, 64, 64));
	}
	
	setTexture(&sprite[UP]);
	setSize(sf::Vector2f(sprite[UP].getSize()));
	setCollisionBox(0, 0, getSize().x, getSize().y);
	
	setCollider(true);
	setOrigin(getSize().x / 2, getSize().y / 2);

}

Clickable::Clickable(sf::RenderWindow* nWindow, sf::Font* font)
{
	window = nWindow;
	isMouseOver = false;
	for (size_t i = 0; i < 3; i++)
	{
		sprite[i].loadFromFile("gfx/PlaySheet.png", sf::IntRect(i * 64, 0, 64, 64));
	}

	setTexture(&sprite[UP]);
	setSize(sf::Vector2f(sprite[UP].getSize()));
	setCollisionBox(0, 0, getSize().x, getSize().y);

	setCollider(true);
	setOrigin(getSize().x / 2, getSize().y / 2);
	
}

Clickable::~Clickable()
{
}

void Clickable::clickResponse()
{
}

bool Clickable::click()
{
	return clicked;
}

void Clickable::handleInput(float dt)
{
	sf::Vector2i mousePos = { input->getMouseX(), input->getMouseY() };

	if (Collision::checkBoundingBox(this, mousePos))
	{
		
		isMouseOver = true;

		if (input->isLeftMouseDown())
		{
			//setFillColor(sf::Color(0, 255, 0, 128));
			clicked = true;
			setTexture(&sprite[DOWN]);
		}
		else
		{
			clicked = false;
			setTexture(&sprite[OVER]);
		}
	}
	else
	{
		setTexture(&sprite[UP]);
		//setFillColor(sf::Color(255,0,0,128));
		isMouseOver = false;
	}
	
}

void Clickable::update(float dt)
{
}

void Clickable::drawText()
{
	window->draw(text);
}

sf::Text Clickable::getText()
{
	return text;
}
