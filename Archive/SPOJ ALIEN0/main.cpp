#include <bits/stdc++.h>
using namespace std;
int compute[3] = {2, 3, 5};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, Q;
	cin >> N >> Q;
	int factor[N][3];
	for(int i = 0; i < N; i++)
	{
		int inputValue;
		cin >> inputValue;
		for(int j = 0; j < 3; j++)
		{
			factor[i][j] = 0;
			int temp = inputValue;
			while(temp % compute[j] == 0)
			{
				factor[i][j]++;
				temp /= compute[j];
			}
		}
	}
	int factorSum[N][3];
	for(int i = 0; i < 3; i++)
	{
		factorSum[0][i] = factor[0][i];
		for(int j = 1; j < N; j++)
		{
			factorSum[j][i] = factorSum[j-1][i]+factor[j][i];
		}
	}
	for(int i = 0; i < Q; i++)
	{
		int L, R, S;
		cin >> L >> R >> S;
		int result = 0;
		if(S == 2)
		{
			int c2 = factorSum[R-1][0];
			if(L-1-1 >= 0) c2 -= factorSum[L-1-1][0];
			result = c2;
		}
		else if(S == 3)
		{
			int c3 = factorSum[R-1][1];
			if(L-1-1 >= 0) c3 -= factorSum[L-1-1][1];
			result = c3;
		}
		else if(S == 4)
		{
			int c2 = factorSum[R-1][0];
			if(L-1-1 >= 0) c2 -= factorSum[L-1-1][0];
			result = c2/2;
		}
		else if(S == 5)
		{
			int c5 = factorSum[R-1][2];
			if(L-1-1 >= 0) c5 -= factorSum[L-1-1][2];
			result = c5;
		}
		else if(S == 6)
		{
			int c2 = factorSum[R-1][0];
			if(L-1-1 >= 0) c2 -= factorSum[L-1-1][0];	
			int c3 = factorSum[R-1][1];
			if(L-1-1 >= 0) c3 -= factorSum[L-1-1][1];
			result = min(c2, c3);
		}
		cout << result << "\n";
	}
	return 0;
}
