// Write a program that uses dynamic programming algorithm to solve the optimal binary search tree problem.

#include <bits/stdc++.h>
using namespace std;

int *input(int);
int sum(int [], int, int);
int optimalSearchTree(int [], int[], int);

int main()
{
    int n;
    cout << "Enter size: ";
    cin>>n;
    cout << "Enter keys: ";
    int *keys=input(n);
    cout << "Enter freq: ";
    int *freq=input(n);
	cout << "Cost of optimal BST: " << optimalSearchTree(keys, freq, n);
	return 0;
}


int optimalSearchTree(int keys[], int freq[], int n)
{
	int cost[n][n];
    for (int i = 0; i < n; i++) cost[i][i] = freq[i];
    for (int L = 2; L <= n; L++)
	{
		for (int i = 0; i <= n-L+1; i++)
		{
			int j = i+L-1;
			cost[i][j] = INT_MAX;
			int off_set_sum = sum(freq, i, j);
			for (int r = i; r <= j; r++)
			{
                int c = ((r > i)? cost[i][r-1]:0) +
                        ((r < j)? cost[r+1][j]:0) +
                        off_set_sum;
                if (c < cost[i][j]) cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}

int *input(int s)
{
    int *a=new int[s];
    for(int i=0; i<s; i++) cin>>a[i];
    return a;
}

int sum(int freq[], int i, int j)
{
	int s = 0;
	for (int k = i; k <= j; k++)
	s += freq[k];
	return s;
}

/*
Enter size: 3
Enter keys: 10 12 20
Enter freq: 34 8 50
Cost of optimal BST: 142
*/
