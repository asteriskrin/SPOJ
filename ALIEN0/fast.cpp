#include <bits/stdc++.h>
#define gc getchar_unlocked
using namespace std;
int compute[3] = {2, 3, 5};
char fs;
int main()
{
	int N = 0, Q = 0;
	fs = gc();
	while(!('0' <= fs && fs <= '9')) fs = gc();
	while('0' <= fs && fs <= '9')
	{
		N = N * 10 + fs - '0';
		fs = gc();
	}
	fs = gc();
	while(!('0' <= fs && fs <= '9')) fs = gc();
	while('0' <= fs && fs <= '9')
	{
		Q = Q * 10 + fs - '0';
		fs = gc();
	}
	int factor[N][3];
	for(int i = 0; i < N; i++)
	{
		int inputValue = 0;
		fs = gc();
		while(!('0' <= fs && fs <= '9')) fs = gc();
		while('0' <= fs && fs <= '9')
		{
			inputValue = inputValue * 10 + fs - '0';
			fs = gc();
		}
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
		int L = 0, R = 0, S = 0;
		fs = gc();
		while(!('0' <= fs && fs <= '9')) fs = gc();
		while('0' <= fs && fs <= '9')
		{
			L = L * 10 + fs - '0';
			fs = gc();
		}
		while(!('0' <= fs && fs <= '9')) fs = gc();
		while('0' <= fs && fs <= '9')
		{
			R = R * 10 + fs - '0';
			fs = gc();
		}
		while(!('0' <= fs && fs <= '9')) fs = gc();
		while('0' <= fs && fs <= '9')
		{
			S = S * 10 + fs - '0';
			fs = gc();
		}
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
		printf("%d\n", result);
	}
	return 0;
}
