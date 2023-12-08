/*
    출처 : https://yabmoons.tistory.com/74
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

int S;
std::queue<std::pair<std::pair<int,int>, int>> q; // {{screen count,screen count} time}
std::vector<std::vector<bool>> visited(1001,std::vector<bool>(1001,false));


void BFS()
{
    while(!q.empty())
    {
        int screenCount = q.front().first.first;
        int clipCount = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if(screenCount == S)
        {
            std::cout<<time;
            break;
        }

        //화면에서 클립보드로 복사
        if(screenCount > 0 && screenCount <= S)
        {
            if(!visited[screenCount][screenCount])
            {
                visited[screenCount][screenCount] = true;
                q.push(std::make_pair(std::make_pair(screenCount,screenCount), time + 1));
            }
        
            //화면에서 이모티콘 한가지 제거
            if(!visited[screenCount - 1][clipCount])
            {
                visited[screenCount - 1][clipCount] = true;
                q.push(std::make_pair(std::make_pair(screenCount - 1, clipCount), time + 1));
            }
        }
        
        //클립보드에서 화면으로 복사
        if(clipCount > 0 && clipCount + screenCount <= S)
        {
            if(!visited[clipCount + screenCount][clipCount])
            {
                visited[clipCount + screenCount][clipCount] = true;
                q.push(std::make_pair(std::make_pair(clipCount + screenCount, clipCount), time + 1));
            }
        }

    }
}

int main()
{
    std::cin>>S;
    
    q.push(std::make_pair(std::make_pair(1,0),0));
    visited[1][0] = true;

    BFS();

    return 0;
}