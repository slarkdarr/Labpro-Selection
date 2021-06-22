#include <iostream>

using namespace std;

int main() {
	int N, L, R;
	cin >> N;
	cin >> L;
	cin >> R;

	int aN[N];
	for (int i = 0; i < N; i++)
	{
		cin >> aN[i];
	}

	int count = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if ((L <= aN[i] + aN[j]) and (aN[i] + aN[j] <= R))
			{
				count += 1;
			}
		}
	}
	cout << count;

	return 0;
}
