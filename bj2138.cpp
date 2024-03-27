/*
    출처 : https://astrid-dm.tistory.com/429
*/
#include <iostream>
#include <vector>
#include <algorithm>

#define inf 987654321

int N, cnt = 0, ans = inf;
std::vector<int> from_bolb;
std::vector<int> temp_bolb;
std::vector<int> to_bolb;

void Invert(int pivot)
{
    if(pivot > 0) from_bolb[pivot - 1] = (from_bolb[pivot - 1] == 0) ? 1 : 0;
    from_bolb[pivot] = (from_bolb[pivot] == 0) ? 1 : 0;
    if(pivot < N - 1) from_bolb[pivot + 1] = (from_bolb[pivot + 1] == 0) ? 1 : 0;
}

int main()
{
    std::cin>>N;

    from_bolb.assign(N, 0);
    temp_bolb.assign(N, 0);
    to_bolb.assign(N, 0);

    for(int i = 0; i < N; i++)
    {
        char tmp;
        std::cin>>tmp;

        from_bolb[i] = tmp - '0';
    }
    for(int i = 0; i < N; i++)
    {
        char tmp;
        std::cin>>tmp;

        to_bolb[i] = tmp - '0';
    }

    temp_bolb = from_bolb;

    // starting at index 0
    from_bolb[0] = (from_bolb[0] == 0) ? 1 : 0;
    from_bolb[1] = (from_bolb[1] == 0) ? 1 : 0;
    cnt++;

    for(int i = 1; i < N; i++)
    {
        if(from_bolb[i - 1] != to_bolb[i - 1])
        {
            Invert(i);
            cnt++;
        }
    }

    if(from_bolb == to_bolb) ans = std::min(ans, cnt);

    // starting at index 1
    from_bolb = temp_bolb;
    cnt = 0;

    for(int i = 1; i < N; i++)
    {
        if(from_bolb[i - 1] != to_bolb[i - 1])
        {
            Invert(i);
            cnt++;
        }
    }

    if(from_bolb == to_bolb) ans = std::min(ans, cnt);

    if(ans != inf) std::cout<<ans;
    else std::cout<<-1;

    return 0;
}