/*
    출처 :  https://scarlettb.tistory.com/64
*/
#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string input;
    std::cin>>input;

    int ans = 0; 
    std::string number;
    bool isMinus = false;

    for(int i = 0; i <= input.size(); i++)
    {
        if(input[i] == '-' || input[i] == '+' || i == input.size())
        {
            if(isMinus)
            {
                ans -= stoi(number);
                number = ""; 
            }
            else
            {
                ans += stoi(number);
                number = "";
            }
        }
        else
        {
            number += input[i];
        }

        // 다음 마이너스까지 가도록 조치
        if(input[i] == '-') isMinus = true;
    }

    std::cout<<ans;

    return 0;
}