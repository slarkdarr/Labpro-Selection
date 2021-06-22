#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <class T>
void delElement(T arr[], int len, int x, T **res)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if (arr[i] == arr[x])
		{
			break;
		}
	}

	if (i < len)
	{
		len--;
		for (int j = i; j < len; j++)
		{
			arr[j] = arr[j+1];
		}
	}

	T *resarr = new T[len];
	copy(arr, arr+len-1, resarr);
	delete[] res;
	*res = resarr;
}

int main()
{
	int N;

	cin >> N;

	string S[N];
	long int X[N];
	for (int i = 0; i < N; i++)
	{
		cin >> S[i] >> X[i];
	}

	int S_size = sizeof(S)/sizeof(S[0]);
	int X_size = sizeof(X)/sizeof(X[0]);
	string *resS = new string[N];
	long int *resX = new long int[N];
	for (int i = 0; i < N; i++)
	{
		int j = i;
		while (j < N)
		{
			j++;
			if (S[i] == S[j])
			{
				X[i] += X[j];
				delElement<string>(S, S_size, j, &resS);
				delElement<long int>(X, X_size, j, &resX);
				N--;
			}
			// else
			// {
				// j++;
			// }
		}
	}

	for (int i = 0; i < S_size; i++)
	{
		cout << resS[i] << ' ' << resX[i] << endl;
	}
	delete[] resS;
	delete[] resX;

	return 0;
}
