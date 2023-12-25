#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
#include <limits>

int N,M;
std::vector<int> gDist;
std::vector<std::vector<std::pair<int,int>>> gMap;
std::vector<int> gParent;

void Dijkstra(int start)
{
    gDist[start] = 0;
    gParent[start] = start;

    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>> pq;
    pq.push({0,start});

    while (!pq.empty())
    {
        /* code */
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(gDist[cur] < cost)
        {
            continue;
        }

        for(int i = 0; i < gMap[cur].size(); i++)
        {
            int next = gMap[cur][i].first;
            int nextCost = gMap[cur][i].second;

            if(gDist[next] > cost + nextCost)
            {
                pq.push({cost + nextCost, next});
                gDist[next] = cost + nextCost;
                gParent[next] = cur;
            }
        }
    }
    
}

int main()
{
    std::cin>>N>>M;
    gDist.assign(N + 1,std::numeric_limits<int>::max());
    gParent.assign(N + 1, 0);
    gMap.assign(N + 1, std::vector<std::pair<int,int>>());

    gMap[0].push_back({0,0});

    for(int i = 0; i < M; i++)
    {
        int a, b, c;

        std::cin>>a>>b>>c;

        gMap[a].push_back({b,c});
    }

    int start, end;
    std::vector<int> Route;

    std::cin>>start>>end;

    Dijkstra(start);

    std::cout<<gDist[end]<<'\n';

    int temp = end;

    while (temp != start)
    {
        /* code */
        Route.push_back(temp);
        temp = gParent[temp];
    }
    Route.push_back(start);

    std::cout<<Route.size()<<'\n';

    std::reverse(Route.begin(),Route.end());

    for(auto a : Route)
    {
        std::cout<<a<<" ";
    }

    return 0;
}