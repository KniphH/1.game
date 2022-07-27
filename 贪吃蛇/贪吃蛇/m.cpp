#include<iostream>
#include"interface.hpp"
using namespace std;
int clic()
{
	if (_kbhit())
		return _getch();
}
int main()
{
	srand(unsigned(time(NULL)));
	string map[29][29];//地图
	short x = 15, y = 15,//蛇头
		remove[700][2],
		direction = 0,
		body[29][29],//蛇身
		star_x = rand() % 24 + 2, star_y = rand() % 24 + 2,
		length = 3,
		times = 0;//移动次数
	while (1)
	{
		int j = 0; int i = 0;
		remove[times][0] = x, remove[times][1] = y;
		switch (clic()) {
		case 119:
			direction = 1; x--; times++; break;
		case 100:
			direction = 2; y++; times++; break;
		case 97:
			direction = 3; y--; times++; break;
		case 115:
			direction = 4; x++; times++; break;
		default:
			if (direction == 1)
			{
				x--; times++;
			}
			if (direction == 2)
			{
				y++; times++;
			}
			if (direction == 3)
			{
				y--; times++;
			}
			if (direction == 4)
			{
				x++; times++;
			}
			Sleep(100);
		}

		if (direction != 0)
		{
			body[x][y] ++;
		}
		for (i = 0; i < 29; i++)
		{
			for (j = 0; j < 29; j++)
			{
				if (remove[times - length][0] == i && remove[times - length][1] == j)
				{
					body[i][j] = 0;
				}
				if (1 == body[i][j])
				{
					map[i][j] = "■";
				}
				else if (star_x == i && star_y == j)
				{
					map[i][j] = "☆";
				}
				else if (body[i][j] == 0)
				{
					map[i][j] = "  ";
				}
				if (body[i][j] == 2 || x > 28 || x < 0 || y>28 || y < 0 || times>600)
				{
					goto end;
				}
				cout << map[i][j];
				if (star_x == x && star_y == y)
				{
					star_x = rand() % 24 + 2;
					star_y = rand() % 24 + 2;
					length++;
				}
			}
			cout << "│" << endl;
		}
		cout << "──────────────────────────────────────────────────────────┘time:" << 60 - times / 10 << "s length:" << length << " ";
		cls();
	}
end:
	cout << "you die!\n";
	system("pause");
	return 0;
}
