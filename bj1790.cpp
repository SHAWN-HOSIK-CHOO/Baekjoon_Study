/*
    출처 :  https://softworking.tistory.com/430
*/
#include <iostream>
#include <vector>
#include <string>

#define ll long long

int N, k;

ll Cal_Length(int n)
{
    ll length = 0;
    for(int start = 1, i = 1; start <= n; start *= 10, i++)
    {
        int end = start * 10 - 1;

        if(end > n) end = n;

        length += static_cast<ll>((end - start + 1) * i);
    }

    return length;
}

int Binary_Search(int left, int right, int target)
{
    if(left >= right) return right;

    int mid = (left + right) / 2;
    ll len = Cal_Length(mid);

    if(len < target) return Binary_Search(mid + 1, right, target);
    else return Binary_Search(left, mid, target);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin>>N>>k;

    if(Cal_Length(N) < k)
    {
        std::cout<<-1; 
        return 0;
    }

    int num = Binary_Search(1, N, k);
    int num_Length = Cal_Length(num);

    std::string s = std::to_string(num);

    std::cout<<s[s.size() - 1 - (num_Length - k)];

    return 0;
}