#include <iostream>

using namespace std;

int main()
{
	long int N;

	cin >> N;

	long int L[N], R[N];

	for (size_t i = 0; i < N; i++)
	{
		cin >> L[i] >> R[i];
	}

	long int Q;

	cin >> Q;

	long int A[Q];
	size_t count[Q];

	for (size_t i = 0; i < Q; i++)
	{
		cin >> A[i];
		count[i] = 0;
	}

	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < Q; j++)
		{
			if (L[i] <= A[j] && A[j] <= R[i])
			{
				count[j]++;
			}
		}
	}

	for (size_t i = 0; i < Q; i++)
	{
		cout << count[i] << endl;
	}

	return 0;
}
