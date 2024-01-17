/*
    출처 : https://yabmoons.tistory.com/75
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <string>

std::string target = "123456780";
std::string input;
std::set<std::string> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = -1;

void bfs()
{
    std::queue<std::pair<std::string,int>> q;
    visited.insert(input);
    q.push({input, 0});

    while (!q.empty())
    {
        std::string cur = q.front().first;
        int cur_cost = q.front().second;
        q.pop();

        if(cur == target)
        {
            ans = cur_cost;
            return;
        }

        int zero = cur.find('0');
        int x = zero / 3;
        int y = zero % 3;

        for(int i = 0; i < 4; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if(xx >= 0 && xx <= 2 && yy >= 0 && yy <= 2)
            {
                std::string next = cur;
                std::swap(next[3 * x + y], next[3 * xx + yy]);

                if(visited.find(next) == visited.end())
                {
                    visited.insert(next);
                    q.push({next, cur_cost + 1});
                }
            }
        }
    }
}

int main()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int in_val;
            std::cin>>in_val;

            input += (in_val + '0');
        }
    }

    bfs();

    std::cout<<ans;

    return 0;
}