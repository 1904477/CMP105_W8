#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string>
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Collision.h"


class Level: public GameObject {
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

	float speed1 = 200;
	float speed2 = 200;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	sf::Texture texture;
	GameObject Ball[2];
	GameObject Sonic;
};