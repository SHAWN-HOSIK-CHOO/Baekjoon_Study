/*
    출처 :  https://cocoon1787.tistory.com/317
*/
#include <iostream>
#include <algorithm>

using namespace std;
#define INF 987654321

int T, K;
int sum[501], file[501], dp[501][501];

int main()
{
	cin >> T;

	while (T--)
	{
		cin >> K;
		for (int i = 1; i <= K; i++)
		{
			cin >> file[i];
			sum[i] = sum[i - 1] + file[i];
		}

		for (int i = 1; i <= K; i++)            // 구해야하는 범위의 크기
		{
			for (int j = 1; j <= K - i; j++)    // 합치는 범위의 시작점  
			{
				dp[j][i + j] = INF;
				for (int k = j; k < i + j; k++) // 중간점
				{
					dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + sum[i + j] - sum[j - 1]);
                    // 출처 : https://roadtosuccess.tistory.com/70
                    // 여기서 sum[end] - sum[start-1]를 하는 이유는 다음의 예시에 나와있다.
                    // 40 30 30 50 파일 크기가 있을 때, 40 +30으로 Y1 파일을 만들고 30 + 50으로 Y2 파일을 만든다. Y1과 Y2를 합칠때의 비용 150이 들기 때문에 sum을 더해주는 것이다. 
				}
			}
		}

		cout << dp[1][K] << endl;

	}

}