#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Data
{
    Data(std::string namei, int koreani, int englishi, int mathi)
    {
        name = namei;
        korean = koreani;
        english = englishi;
        math = mathi;
    }

    std::string name;
    int korean;
    int english;
    int math;
};

int N;
std::vector<Data> v;

bool Cmp(const Data& d1, const Data& d2)
{
    if(d1.english == d2.english && d1.korean == d2.korean && d1.math == d2.math) 
        return d1.name < d2.name;
    if(d1.korean == d2.korean && d1.english == d2.english)
        return d1.math > d2.math;
    if(d1.korean == d2.korean)
        return d1.english < d2.english;
    
    return d1.korean > d2.korean;
}

int main()
{
    std::cin>>N;

    std::string namet;
    int kt, et, mt;

    for(int i = 0; i < N; i++)
    {
        std::cin>>namet>>kt>>et>>mt;
        v.push_back({namet, kt, et, mt});
    }

    std::sort(v.begin(), v.end(), Cmp);

    for(auto d : v)
    {
        std::cout<<d.name<<'\n';
    }

    return 0;
}