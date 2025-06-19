#include "Tapper.h"

#include<iostream>

Tapper::Tapper(std::vector <Lane*>* nLane, std::vector<Beer*>* nBeerVec, int* nMoney)
{
	for (size_t i = 0; i < 3; i++)
	{
		sprite[i].loadFromFile("gfx/Tapper.png", sf::IntRect(i * 64, 0, 64, 64));
	}

	setTexture(&sprite[0]);
	setSize({ 64,64 });
	//setScale(.5, .5);
	isHeld = false;
	isFull = false;
	lane = nLane;
	beerVec = nBeerVec;
	setCollisionBox(0, 0, 64, 64);
	isPouring = false;
	setPosition(lane->at(0)->getPosition().x - 32, lane->at(0)->getPosition().y - 32);
	currentLane = 0;
	money = nMoney;
}

Tapper::~Tapper()
{
}

void Tapper::pour()
{
	if (timer.getElapsedTime().asSeconds() > .5)
	{
		isFull = true;

		timer.restart();
	}
}

void Tapper::handleInput(float dt)
{
	
	int8_t xMov = (input->isKeyDown(sf::Keyboard::D) - input->isKeyDown(sf::Keyboard::A));
	int laneSwitch = 0;

	if (!(currentLane<0 || currentLane==lane->size()))
	{
		laneSwitch += input->isPressed(sf::Keyboard::S) - input->isPressed(sf::Keyboard::W);
		currentLane += laneSwitch;


		std::cout << currentLane;
	}
	if (currentLane < 0)
	{
		currentLane = 0;
	}
	if (currentLane == lane->size())
	{
		currentLane =lane->size()-1;
	}
	if (laneSwitch != 0)
	{
		setPosition(lane->at(currentLane)->getPosition().x, lane->at(currentLane)->getPosition().y - 32);
	}
	std::cout << currentLane << std::endl;
	//if (input->isPressed(sf::Keyboard::W) - input->isKeyDown(sf::Keyboard::S))
	//{
	//	
	//	setPosition(lane->at(0)->getPosition().x - 32, lane->at(0)->getPosition().y - 32);
	//}

	if (getPosition().x <= 90)
	{
		//move(100 * dt, 0);
		setPosition(getPosition().x + (100 * dt), lane->at(currentLane)->getPosition().y - 32);
	}
	else
	{
		//move(xMov * dt * 200, 0);
		setPosition(getPosition().x + (xMov*100 * dt), lane->at(currentLane)->getPosition().y - 32);
	}

	isHeld = input->isPressed(sf::Keyboard::Space);
    
	//std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::Space)<< std::endl;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isFull)
	{
		isFull = false;
		isPouring = false;
		Beer* temp = new Beer(money);
		temp->setPosition(getPosition().x,getPosition().y+16);
		beerVec->push_back(temp);


	}
	//std::cout << isHeld;

}

void Tapper::update(float dt)
{
	
	for (size_t i = 0; i < lane->size(); i++)
	{
		if (Collision::checkBoundingBox(this,(lane->at(i))))
		{
			if (isHeld)
			{
				pour();
			}
		}
		
	}
}

void Tapper::collisionResponse(GameObject* collider)
{
	//if (dynamic_cast<Lane*> (collider))
	//{
	//	if (isHeld && !isPouring)
	//	{
	//		isPouring = true;
	//		timer.restart();
	//		pour();
	//	}
	//}

}

//void Tapper::addLanes(std::vector <Lane*>* nLane)
//{
//	lane=nLane;
//}


