#include <iostream>

using namespace std;

// Menggunakan 'Memoization Technique'
long int knapsackRec(int K, long int P[], int W[], int i, long int** dp)
{
	if (i < 0)
	{
		return 0;
	}

	if (dp[i][K] != -1)
	{
		return dp[i][K];
	}

	if (W[i] > K)
	{
		dp[i][K] = knapsackRec(K, P, W, i-1, dp);
		return dp[i][K];
	}
	else
	{
		dp[i][K] = max(P[i] + knapsackRec(K-W[i], P, W, i-1, dp),
			knapsackRec(K, P, W, i-1, dp));
		return dp[i][K];
	}
}

long int knapsack(int K, long int P[], int W[], int len)
{
	long int** dp;
	dp = new long int*[len];

	for (int i = 0; i < len; i++)
	{
		dp[i] = new long int[K+1];
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < K+1; j++)
		{
			dp[i][j] = -1;
		}
	}
	return knapsackRec(K, P, W, len-1, dp);
}

int main()
{
	int N, K;

	cin >> N >> K;

	long int P[N];
	int W[N];
	for (int i = 0; i < N; i++)
	{
		cin >> P[i] >> W[i];
	}

	int len = sizeof(P)/sizeof(P[0]);

	cout << knapsack(K, P, W, len);

	return 0;
}
