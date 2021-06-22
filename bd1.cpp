#include <iostream>

using namespace std;

int main()
{
	int N;

	cin >> N;

	int L[N], R[N];

	for (int i = 0; i < N; i++)
	{
		cin >> L[i] >> R[i];
	}

	int Q;

	cin >> Q;

	int A[Q];
	int count[Q];

	for (int i = 0; i < Q; i++)
	{
		cin >> A[i];
		count[i] = 0;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < Q; j++)
		{
			if (L[i] <= A[j] && A[j] <= R[i])
			{
				count[j]++;
			}
		}
	}

	for (int i = 0; i < Q; i++)
	{
		cout << count[i] << endl;
	}

	return 0;
}
