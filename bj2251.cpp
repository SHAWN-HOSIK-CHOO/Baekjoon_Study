#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

int A, B, C;
bool Visited[201][201][201] = {false, };
std::vector<int> v;

void bfs()
{
    std::queue<std::pair<int, std::pair<int, int>>> q;
    q.push({0, {0, C}});

    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        if(Visited[a][b][c]) continue;
        if(a == 0) v.push_back(c);

        Visited[a][b][c] = true;

        if(a + b > B) q.push({a + b - B, {B, c}});
        else q.push({0, {a + b, c}});

        if(a + c > C) q.push({a + c - C, {b, C}});
        else q.push({0, {b, a + c}});

        if(b + a > A) q.push({A, {b + a - A, c}});
        else q.push({b + a, {0, c}});

        if(b + c > C) q.push({a, {b + c - C, C}});
        else q.push({a, {0, b + c}});

        if(c + a > A) q.push({A, {b, c + a - A}});
        else q.push({c + a, {b, 0}});

        if(c + b > B) q.push({a, {B, c + b - B}});
        else q.push({a, {c + b, 0}});
    }
    
}

int main()
{
    std::cin>>A>>B>>C;

    bfs();

    sort(v.begin(), v.end());

    for(auto ans : v)
    {
        std::cout<<ans<<" ";
    }

    return 0;
}