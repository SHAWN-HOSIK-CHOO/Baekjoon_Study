/*
    출처 : https://yabmoons.tistory.com/158
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int N, M;
std::vector<std::vector<int>> rect;

void dp()
{
    int length = 0;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= M; j++)
        {
            if(rect[i][j] != 0)
            {
                rect[i][j] = std::min(std::min(rect[i][j - 1], rect[i - 1][j]), rect[i - 1][j - 1]) + 1;

                if(length < rect[i][j])
                {
                    length = rect[i][j];
                }
            }
        }
    }

    std::cout<<length * length<<'\n';
}

int main()
{
    std::cin>>N>>M;
    rect.assign(N + 1, std::vector<int>(M + 1, 0));

    for(int i = 1; i <= N; i++)
    {
        std::string input;
        std::cin>>input;

        for(int j = 0; j < input.length(); j++)
        {
            rect[i][j + 1] = input[j] - '0';
        }
    }

    dp();

    return 0;
}