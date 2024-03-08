/*
    출처 : https://nim-code.tistory.com/257
*/
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

#define inf 987654321
using namespace std;

struct Pos {
	int x, y;
};

int N, M;
int Lab[50][50];
int visited[50][50];
bool check[50][50];
vector<pair<int,int>> V;
const int dx[] = { -1,1,0,0 };
const int dy[] = { 0,0,-1,1 };
int Min = 987654321;

bool Check() 
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (Lab[i][j] != 1 && visited[i][j] == -1)
				return false;
		}
	}
	return true;
}

int bfs() 
{
	queue<pair<int,int>> q;
	int ret = 0;
	memset(visited, -1, sizeof(visited));
	
	for (int i = 0; i < V.size(); i++) 
    {
		q.push({ V[i].first,V[i].second });
		visited[V[i].first][V[i].second] = 0;
	}

	while (!q.empty()) 
    {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
            
			if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

			if (Lab[nx][ny] != 1 && visited[nx][ny] == -1) 
            {
				visited[nx][ny] = visited[x][y] + 1;
				ret = visited[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
	
	return ret;
}

//바이러스 위치 조합 구하기
void dfs(int x, int y, int cnt) {
	if (cnt == M) 
    {
		int res = bfs();
		if (Check()) if (Min > res) Min = res;
				
		return;
	}
	for (int i = x; i < N; i++) 
    {
		for (int j = y; j < N; j++) 
        {
			if (Lab[i][j] != 2 ||check[i][j] == true)
				continue;

			check[i][j] = true;
			V.push_back({ i,j });
			dfs(i, j, cnt + 1);
			check[i][j] = false;
			V.pop_back();
		}

		y = 0;
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> Lab[i][j];
		}
	}
	dfs(0, 0, 0);
	if (Min == inf)
		Min = -1;
	cout << Min << '\n';
	return 0;
}