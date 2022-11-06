// Write a program to solve 0/1 knapsack problem using dynamic programming algorithm.

#include <iostream>
#include <algorithm>
using namespace std;

int *input(int);
int knapSack(int, int [], int [], int );

int main()
{
    int n, maxWt;
    cout << "Enter total weights and max capacity: ";
    cin>>n>>maxWt;
    cout << "Enter weights: ";
    int *weight=input(n);
    cout << "Enter values: ";
    int *value=input(n);
    cout << "Max possible total value: "<<knapSack(maxWt, weight, value, n);
    return 0;
}

int *input(int s)
{
    int *a=new int[s];
    for(int i=0; i<s; i++) cin>>a[i];
    return a;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w, K[n+1][W+1];
    for(i = 0; i <= n; i++)
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0) K[i][w] = 0;
            else if (wt[i - 1] <= w) K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else K[i][w] = K[i - 1][w];
        }
    return K[n][W];
}

/*
Enter total weights and max capacity: 5 10
Enter weights: 1 2 3 4 5
Enter values: 4 1 2 3 7
Max possible total value: 14
*/
