#include <iostream>
#include "View.h"
using namespace std;

View::View()
{
	size = 11;
	scale = 2;
	origin = CartPoint();
}

void View::clear()
{
	for (int y = 0; y < view_maxsize; y++)
	{
		for (int x = 0; x < view_maxsize; x++)
		{
			grid[x][y][0] = '.';
			grid[x][y][1] = ' ';
		}
	}
}

bool View::get_subscripts(int &ix, int &iy, CartPoint location)
{
	CartVector PT = (location - this->origin) / this->scale;
	ix = PT.x;
	iy = PT.y;
	if (ix >= 0 || ix <= this->size || iy >= 0 || iy <= this->size)
	{
		return true;
	}
	else
	{
		cout << "An object is outside of display" << endl;
		return false;
	}
}

void View::draw()
{
	
	for (int j = size - 1; j >= -1; j--)
	{
		for (int i = -1; i <= size - 1; i++)
		{
		if (i == -1 && j % 2 == 0)
			{
			cout << j * 2;
			if (j / 5 == 0)
			{
				cout << " ";
			}

			}
		else if (i == -1 && j % 2 != 0)
			{
				cout << "  ";
			}
			else if (j == -1 && i % 2 == 0)
			{
				cout << i * 2;
				if (i / 5 == 0)
				{
					cout << " ";
				}
				cout << "  ";
			}

			if (i >= 0 && j >= 0)
				cout << grid[i][j][0] << grid[i][j][1];

		}
		cout << endl;
	}
}

void View::plot(GameObject* ptr)
{
	int x;
	int y;
	bool valid = get_subscripts(x, y, ptr->get_location());

	if (valid && grid[x][y][0] == '.')
		{
			ptr->drawself(grid[x][y]);
		}
	else if (valid)
		{
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';
		}
	
}

/*void View::plot(GameObject* ptr)
{
	int x;
	int y;

	if (get_subscripts(x, y, ptr->get_location()))
	{
		int temporary = x;
		x = y;
		y = temporary;
		x = 10-x;
		if (grid[x][y][1] == ' ' && grid[x][y][0] == '.')
		{
			ptr->drawself(grid[x][y]);
		}
		else
		{
			grid[x][y][0] = '*';
			grid[x][y][1] = ' ';
		}
	}
}*/

/*void View::draw()
{
	for (int x = 0; x <= size; x++)
	{
		for (int y = 0; y <= size; y++)
		{
			if ((y == 0) && (x%2 == 0))
			{
				int diff = 20 - scale*x;
				cout << diff;
				if (diff < 10)
				{
					cout << " ";
				}

				else if (y == 0)
				{
					cout << " " << " ";
				}

				if ((x == 11) && (y%2 ==0))
				{
					cout << 2*y << " ";
					if ((scale*y) < 10)
					{
						cout << " ";
					}

					cout << grid[x][y][0] << grid[x][y][1];
				}
				cout << endl;
			}
		}
	}
}*/








