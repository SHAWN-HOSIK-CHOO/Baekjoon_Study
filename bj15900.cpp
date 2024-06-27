#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
/*
    반대로 부모에서 자식으로 가는 아이디어
*/

#define MAX 500001

int N;
std::vector<int> tree[MAX];
std::set<int> visited;
int total_count = 0;

void DFS(int node, int cnt) 
{
	if (tree[node].size() == 1 && node != 1) 
    { 
		total_count += cnt;
		return;
	}

    for (auto child : tree[node]) 
    {
       if(visited.find(child) != visited.end())
            continue;

        visited.insert(child);
        DFS(child, cnt + 1);
        visited.erase(child);
	}
}

int main() 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0); 
    std::cout.tie(0);

	std::cin>>N;

    int tmp1, tmp2;

	for (int i = 1; i <= N - 1; i++) 
    {
		std::cin>>tmp1>>tmp2;

		tree[tmp1].push_back(tmp2);
		tree[tmp2].push_back(tmp1);
	}

    visited.insert(1);
	DFS(1, 0);

	if (total_count % 2 == 1) 
        std::cout << "Yes" << '\n';
	else 
        std::cout << "No" << '\n'; 
	
	return 0;
}