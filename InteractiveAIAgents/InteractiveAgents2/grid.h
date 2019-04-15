#pragma once
#include <sfml/Graphics.hpp>

using namespace sf;

class grid
{
public:
	grid(RenderWindow *window, int col);
	~grid();

	float cellSizes = 50.0f;
	Color outlineColour = Color::Black;
	float outlineThickness = 2.0f;

};

