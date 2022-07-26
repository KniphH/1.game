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
	string xy[29][29]; short x = 15, y = 15,remove[1000][2], a = 0, l[29][29], x1 = rand() % 24 + 2, y1 = rand() % 24 + 2, score = 3, s = 0;
	while (1)
	{
		int j = 0;int i = 0;
		remove[s][0] = x,remove[s][1] = y;
		switch (clic()) {
		case 119:
			a = 1; x--; s++; break;
		case 100:
			a = 2; y++; s++; break;
		case 97:
			a = 3; y--; s++;;break;
		case 115:
			a = 4; x++; s++; break;
		default:
			if (a == 1)
			{
				x--; s++;; ;
			}
			else if (a == 2)
			{
				y++; s++; ;;
			}
			else if (a == 3)
			{
				y--; s++; ; ;
			}
			else if (a == 4)
			{
				x++; s++; ; ;
			}
			Sleep(100);
		}
		if (a != 0)
		{
		l[x][y] ++;
		}
		for (i = 0; i < 29; i++)
		{
			for (j = 0; j < 29; j++)
			{
				if (remove[s - score][0] == i && remove[s - score][1] == j)
				{
					l[i][j]=0;
				}
				if (1 == l[i][j])
				{
					xy[i][j] = "■";
				}
				else if (x1 == i && y1 == j)
				{
					xy[i][j] = "☆";
				}
				else if(l[i][j]==0)
				{
					xy[i][j] = "  ";
				}
				if (l[i][j] == 2||x>29||x<0||y>29||y<0)
				{
					goto end;
				}
				cout << xy[i][j];
				if (x1 == x && y1 == y)
				{
					x1 = rand() % 24 + 2;
					y1 = rand() % 24 + 2;
					score++;
				}
			}
			cout << "|" << endl;
		}
		cout << "__________________________________________________________|时间："<<99-(s/10)<<"  长度："<<score;
		cls();
	}
end:
	return 0;
}
