#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	texture.loadFromFile("gfx/Beach_Ball.png");
	Ball[0].setTexture(&texture);
	Ball[0].setSize(sf::Vector2f(50, 50));
	Ball[0].setPosition(50, 400);
	Ball[0].setCollisionBox(sf::FloatRect(0, 0, 30, 30));

	
	texture.loadFromFile("gfx/Beach_Ball.png");
	Ball[1].setTexture(&texture);
	Ball[1].setSize(sf::Vector2f(50, 50));
	Ball[1].setPosition(1000, 400);
	Ball[1].setCollisionBox(sf::FloatRect(0, 0, 30, 30));

	
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{

}

// Update game objects
void Level::update(float dt)
{
	Ball[0].move(speed1*dt,0);
	Ball[1].move(-speed2 * dt, 0);
	

	if (Ball[0].getPosition().x + Ball[0].getSize().x > window->getSize().x)
	{
		speed1 = -speed1;
	}
	if (Ball[0].getPosition().x < 0)
	{
		speed1 = -speed1;
	}

	if (Ball[1].getPosition().x + Ball[1].getSize().x > window->getSize().x)
	{
		speed2 = -speed2;
	}
	if (Ball[1].getPosition().x < 0)
	{
		speed2 = -speed2;
	}

	if (Collision::checkBoundingBox(&Ball[0], &Ball[1]))
	{
		Ball[0].setPosition(Ball[0].getPosition().x - 10, Ball[0].getPosition().y);
		speed1 = -speed1;
		speed2 = -speed2;
		
	}

	/*if (Collision::checkBoundingCircle(&Ball[0], &Ball[1]))
	{
		Ball[0].setPosition(Ball[0].getPosition().x - 10, Ball[0].getPosition().y);
		speed1 = -speed1;
		speed2 = -speed2;
	}*/ 


	
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(Ball[0]);
	window->draw(Ball[1]);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}