#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX 100010

int N, K, cnt = 0;
int gArray[MAX];
int gVisitedCnt[MAX] = {0, };
bool gVisited[MAX] = {false, };

void BFS()
{
    std::queue<std::pair<int, int>> q;
    q.push({N, 0});
    gVisited[N] = true;

    //bool flag = true;

    while (!q.empty())
    {
        int cur = q.front().first;
        int cur_cnt = q.front().second;
        q.pop();

        gVisited[cur] = true;
        /*
        if(!flag && cnt == cur_cnt && cur == K)
        {
            gVisitedCnt[cur]++;
        }
        if(flag && cur == K)
        {
            cnt = cur_cnt;
            flag = false;
            gVisitedCnt[cur]++;
        }
        */
       
       if(cur == K)
       {
            if(gVisitedCnt[cur] == 0)
            {
                cnt = cur_cnt;
                gVisitedCnt[cur]++;
            }
            else if(cnt == cur_cnt)
            {
                gVisitedCnt[cur]++;
            }   
       }

        if(cur + 1 >= 0 && cur + 1 <= MAX && !gVisited[cur + 1])
        {
            q.push({cur + 1, cur_cnt + 1});
        }
        
        if(cur - 1 >= 0 && cur - 1 <= MAX && !gVisited[cur - 1])
        {
            q.push({cur - 1, cur_cnt + 1});
        }

        if(cur * 2 >= 0 && cur * 2 <= MAX && !gVisited[cur * 2])
        {
            q.push({cur * 2, cur_cnt + 1});
        }
    }
}

int main()
{
    std::cin>>N>>K;

    BFS();

    std::cout<<cnt<<'\n'<<gVisitedCnt[K];

    return 0;
}