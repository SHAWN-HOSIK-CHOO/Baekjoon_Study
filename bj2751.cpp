#include <iostream>
#include <vector>

int N;
std::vector<int> v;

void Merge_Sort(int start, int end)
{
    if(start == end) return;

    int mid = (start + end) / 2;
    int left = start;
    int right = mid + 1;

    std::vector<int> tmp;

    Merge_Sort(left, mid);
    Merge_Sort(right, end);

    while (left <= mid && right <= end)
    {
        if(v[left] <= v[right]) tmp.push_back(v[left++]);
        else tmp.push_back(v[right++]);
    }

    while (left <= mid)
    {
        tmp.push_back(v[left++]);
    }
    
    while (right <= end)
    {
        tmp.push_back(v[right++]);
    }

    for(int i = start, j = 0; i <= end; i++, j++)
    {
        v[i] = tmp[j];
    }   
    
}

int main()
{
    std::cin>>N;
    v.assign(N , 0);

    for(int i = 0; i < N; i++)
    {
        std::cin>>v[i];
    }

    Merge_Sort(0, N - 1);

    for(int num : v)
    {
        std::cout<<num<<'\n';
    }

    return 0;
}