/*
    출처 : https://yabmoons.tistory.com/270
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>

#define inf 987654321

int N, M, ans = -inf;
int arr[1000][1000];
bool visited[1000][1000] = {false, };

std::vector<std::pair<int, int>> v;
std::vector<int> size;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y, int idx)
{
    std::queue<std::pair<int,int>> q, qq;
    q.push({x, y});
    qq.push({x, y});

    visited[x][y] = true;
    int ret = 1;

    while (!q.empty())
    {
        int cur_x = q.front().first;
        int cur_y = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int new_x = cur_x + dx[i];
            int new_y = cur_y + dy[i];

            if(new_x < 0 || new_y < 0 || new_x >= N || new_y >= M) continue;

            if(arr[new_x][new_y] == 1 && !visited[new_x][new_y])
            {
                ret++;
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
                qq.push({new_x, new_y});
            }
        }
    }

    while (!qq.empty())
    {
        int cur_x = qq.front().first;
        int cur_y = qq.front().second;
        qq.pop();

        arr[cur_x][cur_y] = idx;
    }
    size.push_back(ret);
    return ret;
}

int main()
{
    std::cin>>N>>M;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            std::cin>>arr[i][j];

            if(arr[i][j] == 0) v.push_back({i, j});
        }
    }

    int idx = 1;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(arr[i][j] == 1 && !visited[i][j])
            {
                int temp = bfs(i, j, idx);
                ans = std::max(ans, temp);
                idx++;
            }
        }
    }

    for(int i = 0; i < v.size(); i++)
    {
        std::set<int> group;
        int x = v[i].first;
        int y = v[i].second;
        int tmp_sz = 0;
        int cnt = 0;

        for(int j = 0; j < 4; j++)
        {
            int xx = x + dx[j];
            int yy = y + dy[j];

            if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;

            if(arr[xx][yy] != 0 && group.find(arr[xx][yy]) == group.end())
            {
                group.insert(arr[xx][yy]);
                tmp_sz = tmp_sz + size[arr[xx][yy] - 1] + 1;
                cnt++;
            }
        }

        tmp_sz -= cnt - 1;
        ans = std::max(ans, tmp_sz);
    }

    std::cout<<ans;

    return 0;
}