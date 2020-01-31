#include <vector>
#include "glut.h"
#include "graphics.h"
#include "maze.h"

Cell::Cell()
{
	left = top = right = bottom = true;
	visited = false;
}
void Cell::Draw(int x, int y)
{
	glColor3d(0, 0, 0);
	if (left)
		DrawLine(x, y, x, y + 1);
	if (top)
		DrawLine(x, y + 1, x + 1, y + 1);
	if (right)
		DrawLine(x + 1, y + 1, x + 1, y);
	if (bottom)
		DrawLine(x + 1, y, x, y);
}



Maze::Maze()
{

}
void Maze::RemoveWalls()
{
	RemoveWallsR(0, 0);

	// Remove top and bottom wall
}

void Maze::RemoveWallsR(int i, int j)
{
	cells[i][j].visited = true;

	while (true)
	{
		// record legal possibilitites between LEFT, UP, RIGHT, DOWN
		enum MOVES { LEFT, UP, RIGHT, DOWN };
		std::vector<MOVES> moves;

		// check for a legal LEFT move
		if (i - 1 >= 0 && !cells[i - 1][j].visited)
		{
			moves.push_back(LEFT);
		}

		// check other 3 directions

		if (moves.size() == 0)
		{
			return;
		}

		// pick which direction randomly
		int r = rand() % moves.size();

		if (moves[r] == LEFT)
		{
			cells[i][j].left = false;
			cells[i - 1][j].right = false;
			RemoveWallsR(i - 1, j);
		}
		// Likewise for other 3 directions

	}

}
void Maze::Draw()
{
	for (int i = 0; i < WIDTH; i++)
		for (int j = 0; j < HEIGHT; j++)
			cells[i][j].Draw(i, j);
}
