/*
    출처 : https://velog.io/@hangyul0801/%EB%B0%B1%EC%A4%8016959c-%EC%B2%B4%EC%8A%A4%ED%8C%90-%EC%97%AC%ED%96%89-1
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 11

int N;
std::pair<int,int> gStart;
std::vector<std::vector<int>> gChess;
bool gVisited[MAX][MAX][MAX * MAX][3] = {false, };
int dX_knight[8] = {-2,-1,1,2,2,1,-1,-2};
int dY_knight[8] = {1,2,2,1,-1,-2,-2,-1};
int dX_bishop[4] = {-1,1,1,-1};
int dY_bishop[4] = {1,1,-1,-1};
int dX_look[4] = {0,0,1,-1};
int dY_look[4] = {1,-1,0,0};

struct Actor
{
	int x;
	int y;
	int type;
	int departure;
	int count = 0;
};

bool isInRange(int x, int y)
{
	if(x < 0 || x >= N || y < 0 || y >= N)
	{
		return false;
	}

	return true;
}

int bfs()
{
	int ret = -1;
	std::queue<Actor> q;
	q.push({gStart.first, gStart.second, 0, 1, 0});
	q.push({gStart.first, gStart.second, 1, 1, 0});
	q.push({gStart.first, gStart.second, 2, 1, 0});

	while (!q.empty())
	{
		Actor cur = q.front();
		q.pop();

		if(cur.departure == N * N)
		{
			if(ret == -1 || ret > cur.count)
			{
				ret = cur.count;
			}
		}

		if(cur.type == 0)
		{
			for(int i = 0; i < 8; i++)
			{
				int nextX = cur.x + dX_knight[i];
				int nextY = cur.y + dY_knight[i];
				int departure = cur.departure;

				if(!isInRange(nextX, nextY))
				{
					continue;
				}

				if(cur.departure + 1 == gChess[nextX][nextY])
				{
					departure++;
				}

				if(!gVisited[nextX][nextY][departure][cur.type])
				{
					gVisited[nextX][nextY][departure][cur.type] = true;
					q.push({nextX, nextY, cur.type, departure, cur.count + 1});
				}
			}
		}
		else if(cur.type == 1)
		{
			for(int i = 0; i < 4; i++)
			{
				for(int j = 1; j < N; j++)
				{
					int nextX = cur.x + dX_bishop[i] * j;
					int nextY = cur.y + dY_bishop[i] * j;
					int departure = cur.departure;

					if(!isInRange(nextX, nextY))
					{
						break;
					}

					if(cur.departure + 1 == gChess[nextX][nextY])
					{
						departure++;
					}

					if(!gVisited[nextX][nextY][departure][cur.type])
					{
						gVisited[nextX][nextY][departure][cur.type] = true;
						q.push({nextX, nextY, cur.type, departure, cur.count + 1});
					}
				}
			}
		}
		else if(cur.type == 2)
		{
			for(int i = 0; i < 4; i++)
			{
				for(int j = 1; j < N; j++)
				{
					int nextX = cur.x + dX_look[i] * j;
					int nextY = cur.y + dY_look[i] * j;
					int departure = cur.departure;

					if(!isInRange(nextX, nextY))
					{
						break;
					}

					if(cur.departure + 1 == gChess[nextX][nextY])
					{
						departure++;
					}

					if(!gVisited[nextX][nextY][departure][cur.type])
					{
						gVisited[nextX][nextY][departure][cur.type] = true;
						q.push({nextX, nextY,cur.type,departure,cur.count + 1});
					}
				}
			}
		}

		for(int i = 0; i < 3; i++)
		{
			if(i == cur.type)
			{
				continue;
			}

			if(!gVisited[cur.x][cur.y][cur.departure][i])
			{
				gVisited[cur.x][cur.y][cur.departure][i] = true;
				q.push({cur.x, cur.y, i, cur.departure, cur.count + 1});
			}
		}
	}
	return ret;
}

int main()
{
	std::cin>>N;

	gChess.assign(N, std::vector<int>(N, 0));

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			std::cin>>gChess[i][j];

			if(gChess[i][j] == 1)
			{
				gStart.first = i;
				gStart.second = j;
			}
		}
	}

	std::cout<<bfs()<<'\n';

	return 0;
}