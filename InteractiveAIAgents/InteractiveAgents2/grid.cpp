#include "grid.h"


grid::grid(RenderWindow *window, int col)
{
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

			window->draw(grid[i][j]);

		}
	}
}


grid::~grid()
{
}
