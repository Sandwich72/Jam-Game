#pragma once
#include "SFML/Graphics.hpp"
class MotivationBar :  public sf::RectangleShape
{
public:
	MotivationBar();
	~MotivationBar();

	int getMot() { return motivation; }
	void setMot(int nMot);

private:
	int motivation;
	sf::Texture sprite[2];
	int motMax;
	sf::RectangleShape bar;
};

