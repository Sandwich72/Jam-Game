#include "Money.h"

Money::Money()
{
}

Money::Money(sf::RenderWindow* nWindow, sf::Font* font)
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
	setFillColor(sf::Color(255, 255, 255, 128));
	setCollider(true);
	setOrigin(getSize().x / 2, getSize().y / 2);
	setPosition(window->getDefaultView().getSize().x * .8, window->getDefaultView().getSize().y * .10);
	text.setPosition(getPosition());
	text.setCharacterSize(24);
	text.setPosition(getPosition());
	text.setString("balls");
	text.setFont(*font);

	cash = 0;

}

Money::~Money()
{
}

void Money::update(float dt)
{

}

void Money::addMoney(int nCash)
{
	cash += nCash;
	text.setString("£" + std::to_string(cash));
}

int Money::getMoney()
{
	return cash;
}
