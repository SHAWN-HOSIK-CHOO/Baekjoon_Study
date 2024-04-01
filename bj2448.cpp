/*
    출처 : https://nim-code.tistory.com/85
*/
#include <iostream>
#include <algorithm>
#include <cstring>

int N;
char star[3100][6200] = {' ', };

void Draw(int n, int x, int y)
{
    if(n == 3)
    {
        star[x][y] = '*';
		star[x + 1][y - 1] = '*';
		star[x + 2][y - 2] = '*';
		star[x + 2][y - 1] = '*';
		star[x + 2][y] = '*';
		star[x + 2][y + 1] = '*';
		star[x + 2][y + 2] = '*';
		star[x + 1][y + 1] = '*';
    }
    else
    {
        Draw(n / 2, x, y);
        Draw(n / 2, x + n / 2, y - n / 2);
        Draw(n / 2, x + n / 2, y + n / 2);
    }
}

int main()
{
    std::cin>>N;

    memset(star, ' ', sizeof(star));

    Draw(N, 0, N - 1);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 2 * N - 1; j++)
        {
            std::cout<<star[i][j];
        }
        std::cout<<'\n';
    }

    return 0;
}