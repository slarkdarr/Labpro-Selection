#include <iostream>
#include <string>

using namespace std;

void computeLPSarray(string subs, int M, int lps[])
{
	int len = 0;
	int i = 1;
	lps[0] = 0; // Longest Prefix Suffix pertama pasti 0

	// Hitung lps[i] dari 1 sampai M-1
	while (i < M)
	{
		if (subs[len] == subs[i])
		{
			len++;
			lps[i] = len;
			i++;
		}

		else
		{
			if (len == 0)
			{
				lps[i] = len;
				i++;
			}

			else
			{
				len = lps[len-1];
			}
		}
	}
}

// Hitung hasil dari KMP
int KMPalgorithm(string subs, string str)
{
	int M = subs.length();
	int N = str.length();

	int lps[M]; // Longest Prefix Suffix

	computeLPSarray(subs, M, lps);

	int i = 0; // Indeks substring
	int j = 0; // Indeks string actual

	int count = 0;
	int k = 0;

	while (i < N)
	{
		if (str[i] == subs[j])
		{
			i++;
			j++;
		}
		if (j == M)
		{
			j = lps[j-1];
			count++;
		}
		else if (i < N && subs[j] != str[i])
		{
			if (j != 0)
			{
				j = lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	return count;
}

int main() {
	string S;
	int Q;

	cin >> S;
	cin >> Q;

	string P[Q];
	for (int i = 0; i < Q; i++)
	{
		cin >> P[i];
	}

	for (int i = 0; i < Q; i++)
	{
		// Pakai algoritma KMP
		cout << KMPalgorithm(P[i], S) << endl;
	}

	return 0;
}
