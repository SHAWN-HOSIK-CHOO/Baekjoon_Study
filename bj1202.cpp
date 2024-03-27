/*
    출처 :  https://please-amend.tistory.com/entry/%EB%B0%B1%EC%A4%80-1202%EB%B2%88-%EB%B3%B4%EC%84%9D-%EB%8F%84%EB%91%91-Ccpp-%ED%92%80%EC%9D%B4-%EA%B7%B8%EB%A6%BC-%EC%84%A4%EB%AA%85
*/
#include <iostream>
#include <algorithm>
#include <queue>

int N, K, a = 0;
std::vector<std::pair<int, int>> valuable;
std::vector<int> bag;
std::priority_queue<int> pq;

long long Fill(int idx)
{
    while (a < N && valuable[a].first <= bag[idx])
    {
        pq.push(valuable[a++].second);
    }

    if(pq.empty())
    {
        return 0;
    }
    else
    {
        long long ret = pq.top();
        pq.pop();
        return ret;
    }
}

int main()
{
    std::cin>>N>>K;

    for(int i = 0; i < N; i++)
    {
        int tmp1, tmp2;
        std::cin>>tmp1>>tmp2;
        valuable.push_back({tmp1, tmp2});
    }

    for(int i = 0; i < K; i++)
    {
        int tmp3;
        std::cin>>tmp3;
        bag.push_back(tmp3);
    }

    std::sort(valuable.begin(), valuable.end());
    std::sort(bag.begin(), bag.end());

    long long res = 0;

    for(int i = 0; i < K; i++)
    {
        res += Fill(i);
    }

    std::cout<<res;

    return 0;
}