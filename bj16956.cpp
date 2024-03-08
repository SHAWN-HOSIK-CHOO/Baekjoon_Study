#include <iostream>
#include <vector>
#include <string>

int R, C;
bool flag = false;
std::vector<std::string> v;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    std::cin>>R>>C;
    v.assign(R, " ");

    for(int i = 0; i < R; i++)
    {
        std::cin>>v[i];
    }

    for(int x = 0; x < R; x++)
    {
        for(int y = 0; y < C; y++)
        {
            if(v[x][y] == 'W')
            {
                for(int n = 0; n < 4; n++)
                {
                    int nx = x + dx[n];
                    int ny = y + dy[n];

                    if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

                    if(v[nx][ny] == 'S')
                    {
                        std::cout<<0;
                        return 0;
                    }
                    else
                    {
                        if(v[nx][ny] == '.') v[nx][ny] = 'D';
                    }
                }
            }
        }
    }

    std::cout<<1<<'\n';

    for(std::string x : v)
    {
        std::cout<<x<<'\n';
    }

    return 0;
}