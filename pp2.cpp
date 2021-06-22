#include <iostream>
// #include <chrono>

using namespace std;

int main() {
	// auto start = chrono::high_resolution_clock::now();
	int N, L, R;
	cin >> N;
	cin >> L;
	cin >> R;

	int aN[N];
	for (size_t i = 0; i < N; i++)
	{
		cin >> aN[i];
	}

	size_t count = 0;
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = i+1; j < N; j++)
		{
			if ((L <= aN[i] + aN[j]) and (aN[i] + aN[j] <= R))
			{
				count += 1;
			}
		}
	}
	cout << count;
	// auto stop = chrono::high_resolution_clock::now();
	// auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
	// cout << duration.count() << " ms";

	return 0;
}
