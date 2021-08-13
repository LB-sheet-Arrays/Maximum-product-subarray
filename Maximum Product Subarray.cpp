/*
Naive Solution:

The idea is to traverse over every contiguous subarrays, 
find the product of each of these subarrays and return the maximum product from these results.

TC O(n^2)

Better approach: FROM code library utube

TC O(n)
*/

#include <bits/stdc++.h>
using namespace std;

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

long long int maxSubarrayProduct(int arr[], int n)
{
    long long int ma=arr[0];  //max
    long long int mi=arr[0];  //min
    long long int prod=arr[0];//answer
    
    for(int i=1;i<n;i++)
    {
    	if(arr[i]<0)
    	{
    		swap(mi,ma);
		}
		
		ma=max((long long)arr[i],ma*arr[i]);
		mi=max((long long) arr[i],mi*arr[i]);
		
		if(ma>prod)
		{
			prod=ma;
		}
	}
	return prod;
}

// Driver code
int main()
{
    int arr[] = { 1, -2, -3, 0, 7, -8, -2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum Sub array product is "
         << maxSubarrayProduct(arr, n);
    return 0;
}
