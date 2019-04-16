#include "grid.h"


grid::grid(RenderWindow *window, int col)
{
	currentWindow = window;

	const int columns = 24;
	const int rows = 16;

	RectangleShape grid[columns][rows];
	Vector2f cellSize(cellSizes, cellSizes);

	for (int i = 0; i < columns; i++) {
		for (int j = 0; j < rows; j++) {

			grid[i][j].setSize(cellSize);
			grid[i][j].setOutlineColor(outlineColour);
			grid[i][j].setOutlineThickness(outlineThickness);			

			grid[i][j].setPosition(i*cellSize.x + 2.5f, j*cellSize.y + 2.5f);

			node *cellNode = new node(grid[i][j]);
			cellNode->colVal = i;
			cellNode->rowVal = j;
			listOfNodes.push_back(*cellNode);

			
						
			//currentWindow->draw(grid[i][j]);
		}
	}

	draw();
	assignNeighbours();
}


grid::~grid()
{
}

void grid::draw()
{

	for (int i = 0; i < listOfNodes.size(); i++)
	{
		/*listOfNodes[i].cellRef.setSize(cellSize);
		listOfNodes[i].cellRef.setOutlineColor(outlineColour);
		listOfNodes[i].cellRef.setOutlineThickness(outlineThickness);*/

		//std::cout << "X: " << listOfNodes[2].cellRef.getPosition().x << " Y: " << listOfNodes[2].cellRef.getPosition().y << std::endl

		listOfNodes[i].update();
		currentWindow->draw(listOfNodes[i].cellRef);
	}
}

void grid::assignNeighbours()
{
	for (int i = 0; i < listOfNodes.size(); i++)
	{
		for (int j = 0; j < listOfNodes.size(); j++)
		{
			//FIND NORTH NEIGHBOUR
			if(listOfNodes[j].rowVal == listOfNodes[i].rowVal - 1 && listOfNodes[j].colVal == listOfNodes[i].colVal)
			{
				listOfNodes[i].north = &listOfNodes[j];
			}

			//FIND SOUTH NEIGHBOUR
			if (listOfNodes[j].rowVal == listOfNodes[i].rowVal + 1 && listOfNodes[j].colVal == listOfNodes[i].colVal)
			{
				listOfNodes[i].south = &listOfNodes[j];
			}

			//FIND WEST NEIGHBOUR
			if (listOfNodes[j].rowVal == listOfNodes[i].rowVal && listOfNodes[j].colVal == listOfNodes[i].colVal -1)
			{
				listOfNodes[i].west = &listOfNodes[j];
			}

			//FIND EAST NEIGHBOUR
			if (listOfNodes[j].rowVal == listOfNodes[i].rowVal + 1 && listOfNodes[j].colVal == listOfNodes[i].colVal + 1)
			{
				listOfNodes[i].east = &listOfNodes[j];
			}
		}
	}	
}
