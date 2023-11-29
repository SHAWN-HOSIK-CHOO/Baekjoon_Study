#include <iostream>
#include <vector>
//
int main()
{
    std::vector<std::vector<int>> A{
        {1,3,2,5},
        {7,6,3,5},
        {3,0,3,5}
    };

    std::vector<std::vector<int>> B{
        {2,1,2},
        {7,8,1},
        {5,5,1},
        {3,0,3}
    };

    std::vector<std::vector<int>> C;
    C.assign(4,std::vector<int>(4,0));

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int res = 0;
            for (int k = 0; k < 4; k++)
            {
                /* code */
                res += A[i][k] * B[k][j];
            }
            C[i][j] = res;
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout<<C[i][j]<<" ";
        }
        std::cout<<'\n';
    }

    return 0;
}