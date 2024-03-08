/*
    출처 : https://yabmoons.tistory.com/205
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>

using namespace std;

int num;
set<pair<pair<string,string>,string>> visited;
pair<pair<string, string>, string> initial_State;

bool IsComplete(string a, string b, string c)
{
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != 'A') return false;
    }

    for(int i = 0; i < b.length(); i++)
    {
        if(b[i] != 'B') return false;
    }

    for(int i = 0; i < c.length(); i++)
    {
        if(c[i] != 'C') return false;
    }

    return true;
}

string RemoveTop(string s)
{
    string tmp;
    for(int i = 0; i < s.length() - 1; i++)
    {
        tmp += s[i];
    }

    return tmp;
}

void bfs()
{
    queue<pair<pair<pair<string, string>, string>, int>> q;
    q.push({initial_State, 0});
    visited.insert(initial_State);

    while (!q.empty())
    {
        string a = q.front().first.first.first;
        string b = q.front().first.first.second;
        string c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(IsComplete(a, b, c)) 
        {
            cout<<cnt<<'\n';
            return;
        }

        if(a.length() > 0)
        {
            string aa = RemoveTop(a);
            string bb = b + a[a.length() - 1];

            if(visited.find({{aa, bb}, c}) == visited.end())
            {
                visited.insert({{aa, bb}, c});
                q.push({{{aa, bb}, c}, cnt + 1});
            }

            string cc = c + a[a.length() - 1];
            if(visited.find({{aa, b}, cc}) == visited.end())
            {
                visited.insert({{aa, b}, cc});
                q.push({{{aa, b}, cc}, cnt + 1});
            }
        }

        if(b.length() > 0)
        {
            string bb = RemoveTop(b);
            string aa = a + b[b.length() - 1];

            if(visited.find({{aa, bb}, c}) == visited.end())
            {
                visited.insert({{aa, bb}, c});
                q.push({{{aa, bb}, c}, cnt + 1});
            }

            string cc = c + b[b.length() - 1];
            if(visited.find({{a, bb}, cc}) == visited.end())
            {
                visited.insert({{a, bb}, cc});
                q.push({{{a, bb}, cc}, cnt + 1});
            }
        }

        if(c.length() > 0)
        {
            string cc = RemoveTop(c);
            string aa = a + c[c.length() - 1];

            if(visited.find({{aa, b}, cc}) == visited.end())
            {
                visited.insert({{aa, b}, cc});
                q.push({{{aa, b}, cc}, cnt + 1});
            }

            string bb = b + c[c.length() - 1];
            if(visited.find({{a, bb}, cc}) == visited.end())
            {
                visited.insert({{a, bb}, cc});
                q.push({{{a, bb}, cc}, cnt + 1});
            }
        }
    }
    
}

int main()
{
    for(int i = 0; i < 3; i++)
    {
        std::cin>>num;

        if(i == 0)
        {
            if(num == 0)
            {
                initial_State.first.first = "";
            }
            else
            {
                string a; 
                cin>>a;

                initial_State.first.first = a;
            }
        }
        else if(i == 1)
        {
            if(num == 0)
            {
                initial_State.first.second = "";
            }
            else
            {
                string b;
                cin>>b;

                initial_State.first.second = b;
            }
        }
        else if(i == 2)
        {
            if(num == 0)
            {
                initial_State.second = "";
            }
            else
            {
                string c;
                cin>>c;

                initial_State.second = c;
            }
        }
    }

    bfs();

    return 0;
}

