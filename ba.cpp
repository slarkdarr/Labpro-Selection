#include <iostream>
#include <string>

using namespace std;

#define NO_OF_CHARS 256

// Menggunakan metode jumlah karakter dalam sebuah array
// Increment value di array count untuk setiap karakter di s1
// dan decrement value untuk setiap karakter di s2
// Jika semua value di array count adalah 0, kedua string anagram
bool isAnagram(string s1, string s2)
{
	int count[NO_OF_CHARS] = {0};
	int i;

	for (i = 0; s1[i] && s2[i]; i++)
	{
		count[s1[i]]++;
		count[s2[i]]--;
	}

	if (s1[i] || s2[i])
	{
		return false;
	}

	for (i = 0; i < NO_OF_CHARS; i++)
	{
		if (count[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N;

	cin >> N;

	vector<string> S(N);
	for (int i = 0; i < N; i++)
	{
		cin >> S[i];
	}

	int count = 0;
	for (int i = 0; i < S.size(); i++)
	{
		int j = i+1;
		while (j < S.size())
		{
			if (isAnagram(S[i], S[j]))
			{
				count++;
				// Jika kedua kata adalah anagram, hapus kedua kata tersebut dari vector
				// sehingga isi vektor hanyalah kata yang tidak memiliki anagram
				S.erase(S.begin()+i);
				S.erase(S.begin()+j-1);
			}
			else
			{
				j++;
			}
		}
	}
	
	// Total anagram adalah count + isi vektor akhir
	cout << count + S.size();

	return 0;
}
