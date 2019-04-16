#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "node.h"
#include <algorithm>

using namespace sf;

class grid
{
public:
	grid(RenderWindow *window, int col);
	~grid();

	float cellSizes = 50.0f;
	Color outlineColour = Color::Black;
	float outlineThickness = 2.0f;

	void draw();
	void assignNeighbours();

	RenderWindow *currentWindow;

	std::vector<node> listOfNodes;

};

