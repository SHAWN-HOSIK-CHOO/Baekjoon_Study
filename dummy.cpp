#include <iostream>
#include <vector>

int main()
{
    std::vector<std::vector<int>> A{
            {1,3,2,5,7},
            {6,3,5,3,0},
            {3,5,15,15,15},
            {15,0,9,8,7},
            {0,0,0,0,0}
    };

    std::vector<std::vector<int>> B{
            {2,1,2,7,8},
            {1,5,5,1,3},
            {0,3,15,15,15},
            {0,0,9,8,7},
            {0,0,0,0,0}
    };

    std::vector<std::vector<int>> C;
    C.assign(5,std::vector<int>(5,0));

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            int res = 0;
            for (int k = 0; k < 5; k++)
            {
                /* code */
                res += A[i][k] * B[k][j];
            }
            C[i][j] = res;
        }
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            std::cout<<C[i][j]<<" ";
        }
        std::cout<<'\n';
    }

    return 0;
}