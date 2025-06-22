#include "Tapper.h"

#include<iostream>

Tapper::Tapper()
{
}

Tapper::Tapper(std::vector <Lane*>* nLane, std::vector<Beer*>* nBeerVec, Money* nMoney)
{
	for (size_t i = 0; i < 3; i++)
	{
		sprite[i].loadFromFile("gfx/Tapper.png", sf::IntRect(i * 64, 0, 64, 64));
	}
	setTexture(&sprite[0]);
	setSize({ 64,64 });

	beer.setSize({ 64, 64 });
	beerSprite.loadFromFile("gfx/Beer.png");
	beer.setTexture(&beerSprite);
	beer.setPosition(getPosition());
	for (size_t i = 0; i < 7; i++)
	{
		beerAnim.addFrame(sf::IntRect(i * 64, 0, 64, 64));
	}
	beerAnim.setLooping(false);
	beer.setTextureRect(beerAnim.getCurrentFrame());
	pourSpeed = .05;
	beerAnim.setFrameSpeed(pourSpeed);
	beer.setScale(.75,.75);
	beer.setFillColor(sf::Color::Transparent);

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
	if(isPouring)
	{
		isFull = true;
		//if (timer.getElapsedTime().asSeconds() > .4)
		//{
		//	isFull = true;

		//	timer.restart();
		//}
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
		beer.setPosition(getPosition());
	}


	if (getPosition().x <= 90)
	{
		//move(100 * dt, 0);
		setPosition(getPosition().x + (100 * dt), lane->at(currentLane)->getPosition().y - 32);
		beer.setPosition(getPosition());
	}
	else
	{
		//move(xMov * dt * 200, 0);
		setPosition(getPosition().x + (xMov*100 * dt), lane->at(currentLane)->getPosition().y - 32);
		beer.setPosition(getPosition());
	}

	//isHeld = input->isPressed(sf::Keyboard::Space);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		isHeld = true;
		if(pourTimer.getElapsedTime().asSeconds()>.4)
			isPouring = true;
	}
	else
	{
		isHeld = false;
		pourTimer.restart();
		isPouring=false;
	}
    
	//std::cout << sf::Keyboard::isKeyPressed(sf::Keyboard::Space)<< std::endl;
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && beerAnim.getCurrentFrameNum()==6)
	{
		isFull = false;
		isPouring = false;
		Beer* temp = new Beer(currentLane,money);
		temp->setPosition(getPosition().x,getPosition().y+16);
		beerVec->push_back(temp);
		beerAnim.stop();
		beer.setFillColor(sf::Color::Transparent);

	}
	//std::cout << isHeld;

}

void Tapper::update(float dt)
{
	//beerAnim.animate(dt);
	//beer.setTextureRect(beerAnim.getCurrentFrame());
	
	for (size_t i = 0; i < lane->size(); i++)
	{
		if (Collision::checkBoundingBox(this,(lane->at(i))))
		{

			if (isHeld)
			{
				pour();
				//beerAnim.animate(dt);
				//beer.setTextureRect(beer.getTextureRect());
				beer.setFillColor(sf::Color::White);
				beerAnim.play(true);
				beerAnim.animate(dt);
				beer.setTextureRect(beerAnim.getCurrentFrame());
				
			}
			else if(isHeld)
			{
				
				beer.setFillColor(sf::Color::Transparent);
				beerAnim.stop();
				beer.setTextureRect(beerAnim.getCurrentFrame());
			
			}
		}
		//if (Collision::checkBoundingBox(this, sf::Vector2i(lane->at(i)->getEndBar().left, lane->at(i)->getEndBar().top)))
		//{
		//	if (isHeld)
		//	{
		//		pour();
		//	}
		//}
		//std::cout << pourTimer.getElapsedTime().asSeconds() << std::endl;
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

sf::RectangleShape Tapper::getBeer()
{
	return beer;
}

//void Tapper::addLanes(std::vector <Lane*>* nLane)
//{
//	lane=nLane;
//}


