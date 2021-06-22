#include <iostream>
#include <climits>

using namespace std;

int main()
{
	size_t N;

	cin >> N;

	long int A[N];
	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// Variasi Algoritma Kadane

	long int min_ended_here = LONG_MAX;	// Nilai minimum dimana indeksnya berhenti di indeks ini
	long int min_until_now = LONG_MAX;	// Nilai minimum sejauh ini
	for (size_t i = 0; i < N; i++)
	{
		if (min_ended_here > 0) // Jika min_ended_here > 0, tidak mungkin jika dijumlahkan
								// dengan bilangan lain menghasilkan minimum
		{
			min_ended_here = A[i];
		}

		else 	// Jika min_ended_here < 0, ada kemungkinan untuk menghasilkan minimum value
				// jika dijumlahkan dengan bilangan lain
		{
			min_ended_here += A[i];
		}

		// Nilai minimum sampai sekarang merupakan nilai minimum antara
		// nilai minimum dimana indeksnya berhenti di indeks i dengan
		// nilai minimum sampai sekarang
		min_until_now = min(min_ended_here, min_until_now);
	}

	cout << min_until_now;

	return 0;
}
