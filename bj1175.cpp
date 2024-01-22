/*
    출처 : https://yabmoons.tistory.com/310
*/
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

int N, M, startX = 0, startY = 0;
std::vector<std::vector<char>> classroom;
bool visited[51][51][5][2][2];
int dx[4] = {-1, 1,  0, 0};
int dy[4] = { 0, 0, -1, 1};

struct element
{
    int x;
    int y;
    int dir;
    bool visitedC1;
    bool visitedC2;
};


bool Movable(int x, int y)
{
    if(classroom[x][y] == '#')
    {
        return false;
    }
 
    return true;
}

void bfs()
{   
    std::queue<std::pair<element,int>> q;
    q.push({{startX, startY, -1, 0, 0}, 0});
    visited[startX][startY][4][0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first.x;
        int y = q.front().first.y;
        int dir = q.front().first.dir;
        bool c1_visited = q.front().first.visitedC1;
        bool c2_visited = q.front().first.visitedC2;
        int cur_count = q.front().second;
        q.pop();

        if(c1_visited && c2_visited)
        {
            std::cout<<cur_count;
            return;
        }

        for(int i = 0; i < 4; i++)
        {
            if(i == dir)
            {
                continue;
            }

            int xx = x + dx[i];
            int yy = y + dy[i];
            bool c1_visited_tmp = c1_visited;
            bool c2_visited_tmp = c2_visited;

            if(xx >= 0 && xx < N && yy >= 0 && yy < M)
            {
                if(!visited[xx][yy][i][c1_visited][c2_visited] && classroom[xx][yy] != '#')
                {
                    if(classroom[xx][yy] == 'C')
                    {
                        c1_visited_tmp = true;
                    }
                    if (classroom[xx][yy] == 'D')
                    {
                        c2_visited_tmp = true;
                    }

                    visited[xx][yy][i][c1_visited_tmp][c2_visited_tmp] = true;
                    q.push({{xx, yy, i, c1_visited_tmp, c2_visited_tmp}, cur_count + 1});
                }
            }
        }
    }
    std::cout<<-1<<'\n';
}

int main()
{
    std::cin>>N>>M;
    classroom.assign(N, std::vector<char>(M, '#'));

    std::string input;

    int idx = 0;
    for(int i = 0; i < N; i++)
    {
        std::cin>>input;
        for(int j = 0; j < M; j++)
        {
            classroom[i][j] = input[j];
            if(input[j] == 'S')
            {
                startX = i; startY = j;
            }

            if(input[j] == 'C')
            {
               idx++;
               if(idx == 2)
               {
                classroom[i][j] = 'D';
               }
            }
        }
    }

    bfs();

    return 0;
}
