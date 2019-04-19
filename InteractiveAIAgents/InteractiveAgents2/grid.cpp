#include "grid.h"


grid::grid(RenderWindow *window, int col)
{
	currentWindow = window;

	//defining values for the grid and cells
	const int columns = 24;
	const int rows = 16;

	RectangleShape grid[columns][rows];
	Vector2f cellSize(cellSizes, cellSizes);

	//generate a grid
	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {

			//define values for the cell
			grid[i][j].setSize(cellSize);
			//grid[i][j].setOutlineColor(outlineColour);
			//grid[i][j].setOutlineThickness(outlineThickness);			

			//slightly offset it from directly top left to give it a boundary around the window
			grid[i][j].setPosition(i*cellSize.x + 2.5f, j*cellSize.y + 2.5f);

			//with each grid cell that get's generated, create a node to store it in
			node *cellNode = new node(grid[i][j]);
			cellNode->colVal = i;
			cellNode->rowVal = j;

			//for the node, assign the center of the grid cell to be it's respective values
			cellNode->posX = grid[i][j].getPosition().x + (grid[i][j].getGlobalBounds().width / 2);
			cellNode->posY = grid[i][j].getPosition().y + (grid[i][j].getGlobalBounds().height / 2);

			//store a list of all generated nodes
			listOfNodes.push_back(*cellNode);
		}
	}

	//define an abituary starting node for the time being and push it into the nodes to check for the path algorithm
	startNode = &listOfNodes[58];
	startNode->nodeType = node::start;
	currentNodesToCheck.push_back(startNode);

	bankNode = &listOfNodes[356];
	bankNode->nodeType = node::bank;

	//call the function to assign neighbours for all nodes
	assignNeighbours();
}


grid::~grid()
{
}

//called every tick of the main loop, updates the nodes and draws the grid again using the stored list of nodes
void grid::draw()
{
	for (int i = 0; i < listOfNodes.size(); i++)
	{
		listOfNodes[i].update();
		currentWindow->draw(listOfNodes[i].cellRef);
		currentWindow->draw(listOfNodes[i].cellSprite);
	}
}

void grid::resetValues()
{
	for (size_t i = 0; i < listOfNodes.size(); i++)
	{
		listOfNodes[i].Parent = nullptr;
		if(listOfNodes[i].nodeType == node::path || listOfNodes[i].nodeType == node::checked)
		{
			listOfNodes[i].nodeType = node::empty;
		}
	}

	currentNodesToCheck = std::vector<node*>();
	startNode = targetNode;
	currentNodesToCheck.push_back(startNode);

	targetNode = &listOfNodes[66];
	targetNode->nodeType = node::goal;
	reachedGoal = false;
	PathSet = false;
}

//Loop through each node and find it's respective neighbours and assign them for pathfinding
void grid::assignNeighbours()
{
	//Loop through each node, and then the list again to find each neighbour
	for (int i = 0; i < listOfNodes.size(); i++)
	{
		for (int j = 0; j < listOfNodes.size(); j++)
		{
			//find north neighbour by looking for the node with the same column value but with a -1 row value
			if(listOfNodes[j].rowVal == listOfNodes[i].rowVal - 1 && listOfNodes[j].colVal == listOfNodes[i].colVal)
			{				
				listOfNodes[i].neighbours.push_back(listOfNodes[i].north = &listOfNodes[j]);
			}

			//find east neighbour by looking for the node with the same row value but +1 column value
			if (listOfNodes[j].rowVal == listOfNodes[i].rowVal + 1 && listOfNodes[j].colVal == listOfNodes[i].colVal + 1)
			{
				listOfNodes[i].neighbours.push_back(listOfNodes[i].east = &listOfNodes[j]);
			}

			//find south neighbour by looking for the node with the same column value but 1 higher row value
			if (listOfNodes[j].rowVal == listOfNodes[i].rowVal + 1 && listOfNodes[j].colVal == listOfNodes[i].colVal)
			{
				listOfNodes[i].neighbours.push_back(listOfNodes[i].south = &listOfNodes[j]);
			}

			//find west neighbour by looking for the node with the same row value but 1 less column value
			if (listOfNodes[j].rowVal == listOfNodes[i].rowVal && listOfNodes[j].colVal == listOfNodes[i].colVal - 1)
			{
				listOfNodes[i].neighbours.push_back(listOfNodes[i].west = &listOfNodes[j]);
			}				

			//once neighbour has been found it is assigned respectively into it's own pointer for the node as well pushed into the list of neighbours
		}

		
	}	
}

//draw the path backwards from the goal to the start point by looking through all the parent node path from the goal nope
void grid::DrawPath(node* node)
{
	//set the current node to the be of type path for the colour update
	node->nodeType = node::path;
	if (node->Parent != nullptr)
	{
		//recurring function call going through the parent node of the given node until we reach the start node with a null parent
		DrawPath(node->Parent);
	}
	else
	{
		PathSet = true;

		resetValues();
	}
}

//inital part of the breadth first search
void grid::breadthFirst()
{
	//looks into the current list of nodes to check and makes a copy before clearing it
	//on first call the node to check is the starting node
	std::vector<node*>  initialCheck = currentNodesToCheck;
	currentNodesToCheck = std::vector<node*>();

	//check to see if the goal has been reached and draw the given path if so
	if (reachedGoal && !PathSet)
	{
		DrawPath(targetNode);
	}
	else
	{
		//look through the copied list of check nodes and put them through the checking section
		for (size_t i = 0; i < initialCheck.size(); i++)
		{
			if (reachedGoal) { break; }

			breadthFirstCheckNode(initialCheck[i]);
		}
	}
}

//Perform the breadth first search for a given node
void grid::breadthFirstCheckNode(node* currentNode)
{	
	//looping through all neighbours of the node
	for (node* nextNode : currentNode->neighbours)
	{	
		//asign the current node as been checked
		currentNode->nodeType = node::checked;

		//perform the check on the appropriate (not already checked or an obstacel) given neighbour to see if the goal has been reached
		if (nextNode->nodeType != node::checked && nextNode->nodeType != node::obstacle && nextNode->nodeType != node::invisWall)
		{
			//if the neighbour is the goal 
			if (nextNode->nodeType == node::goal)
			{
				currentNode->nodeType = node::checked;
				targetNode = nextNode;
				targetNode->Parent = currentNode;
				reachedGoal = true;
			}
			else
			{
				//keep track of the paths taken 
				nextNode->Parent = currentNode;

				//check if the current neighbouring node is already in the list of check nodes otherwise add it so the breadth first function above can traverse it
				bool alreadyInNextCheck = false;
				for (node* checkNode : currentNodesToCheck)
				{
					if (checkNode == nextNode)
					{
						alreadyInNextCheck = true;
					}
				}

				if (alreadyInNextCheck == false)
				{
					currentNodesToCheck.push_back(nextNode);
				}
			}
		}

	}
}
