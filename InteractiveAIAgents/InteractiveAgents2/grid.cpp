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
			listOfNodes.push_back(*cellNode);

			//currentWindow->draw(grid[i][j]);

		}
	}

	draw();
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

		std::cout << "X: " << listOfNodes[2].cellRef.getPosition().x << " Y: " << listOfNodes[2].cellRef.getPosition().y << std::endl;

		listOfNodes[i].update();

		currentWindow->draw(listOfNodes[i].cellRef);
	}
}
