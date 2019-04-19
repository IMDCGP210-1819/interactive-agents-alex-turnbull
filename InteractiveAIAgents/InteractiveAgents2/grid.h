#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include "node.h"
#include <algorithm>
#include <queue>

using namespace sf;

class grid
{
public:
	grid(RenderWindow *window, int col);
	~grid();

	float cellSizes = 50.0f;
	Color outlineColour = Color::Red;
	float outlineThickness = 2.0f;

	void draw();	

	RenderWindow *currentWindow;

	std::vector<node> listOfNodes;

	node* startNode = nullptr;
	node* targetNode = nullptr;

	node* bankNode = nullptr;

	bool PathSet = false;

	void breadthFirst();
	void breadthFirstCheckNode(node* currentNode);
	void DrawPath(node* node);

	bool reachedGoal = false;
	std::vector<node*> currentNodesToCheck = std::vector<node*>();

private:
	void assignNeighbours();
};

