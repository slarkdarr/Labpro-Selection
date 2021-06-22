#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	size_t N, Q;

	cin >> N;

	long int A[N];

	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	cin >> Q;

	size_t L[Q];
	size_t R[Q];
	for (size_t i = 0; i < Q; i++)
	{
		cin >> L[i] >> R[i];
	}

	long int med[Q];

	for (size_t i = 0; i < Q; i++)
	{
		long int part_array[(R[i]-L[i])+1];
		int j = 0;
		for (size_t k = L[i]-1; k < R[i]; k++)
		{
			part_array[j] = A[k];
			j++;
		}
		size_t len = sizeof(part_array) / sizeof(part_array[0]);
		sort(part_array, part_array+len);

		if ((R[i] - L[i] + 1) % 2 == 0)
		{
			med[i] = part_array[((R[i]-L[i]+1)/2)-1];
		}
		else
		{
			med[i] = part_array[(R[i]-L[i])/2];
		}
	}

	for (size_t i = 0; i < Q; i++)
	{
		cout << med[i] << endl;
	}

	return 0;
}
