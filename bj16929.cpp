/*
    https://astrid-dm.tistory.com/352
    블로그 참고했습니다. 감사합니다.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

int N,M;
std::vector<int> dx{-1,1,0,0};
std::vector<int> dy{0,0,-1,1};

void DFS(std::vector<std::vector<char>>& map,std::vector<std::vector<bool>>& visited,std::pair<int,int>& startIndex,std::pair<int,int>&& index,int cnt)
{
    visited[index.first][index.second] = true;

    for(int i = 0; i < 4; i++)
    {
        int d_x = index.first + dx[i];
        int d_y = index.second + dy[i];
        if(d_x >= 0 && d_x < N && d_y >= 0 && d_y < M && map[d_x][d_y] == map[index.first][index.second] && visited[d_x][d_y] == false)
        {
            DFS(map,visited,startIndex,{d_x,d_y},cnt+1);
        }
        else if(startIndex.first == d_x && startIndex.second == d_y && cnt >= 4)
        {
            std::cout<<"Yes";
            exit(0);
        }
    }
    visited[index.first][index.second] = false;
}

int main()
{
    std::vector<std::vector<char>> map;
    std::vector<std::vector<bool>> visited;
    std::pair<int,int> startIndex;

    std::cin>>N>>M;

    map.assign(N,std::vector<char>(M,0));
    visited.assign(N,std::vector<bool>(M,false));

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            /* code */
            std::cin>>map[i][j];
            visited[i][j] = false;
        }
    }
        
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!visited[i][j])
            {
                startIndex = std::make_pair(i,j);
                DFS(map,visited,startIndex,{i,j},1);
                visited[i][j] = true;
            }
        }
    }

    std::cout<<"No";

    return 0;
}