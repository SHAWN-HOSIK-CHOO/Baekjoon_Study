/*
    출처 : https://ghqls0210.tistory.com/197
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int T, N;
std::vector<int> numbers;
std::vector<bool> check;
std::vector<std::string> answer;

void bfs(int num)
{
    std::queue<std::pair<int,std::string>> q;

    q.push({1, "1"});

    while (!q.empty())
    {
        int x = q.front().first;
        std::string x_str = q.front().second;
        q.pop();

        x %= num;

        if(x_str.size() > 100)
        {
            answer.push_back("BRAK");
            break;
        }

        if(x == 0)
        {
            answer.push_back(x_str);
            break;
        }

        if(check[(x * 10) % num] == false)
        {
            check[(x * 10) % num] = true;
            q.push({(x * 10) % num, x_str + "0"});
        }

        if(check[(x * 10 + 1) % num] == false)
        {
            check[(x * 10) % num + 1] = true;
            q.push({(x * 10 + 1) % num, x_str + "1"}); 
        }
    }

    return;
}

int main()
{
    std::cin>>T;

    for(int i = 0; i < T; i++)
    {
        std::cin>>N;
        numbers.push_back(N);
    }

    for(int i = 0; i < T; i++)
    {
        check.assign(20001, false);
        bfs(numbers[i]);
    }

    for(int i = 0; i < T; i++)
    {
        std::cout<<answer[i]<<'\n';
    }

    return 0;
}
