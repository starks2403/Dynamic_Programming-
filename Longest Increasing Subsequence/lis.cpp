#include<bits/stdc++.h>
using namespace std;
int lis(int *arr,int n)
{
    int i,j,maxi=0;
    int *lis=new int[n];
    for(i=0;i<n;i++)
        lis[i]=1;
    for(i=1;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if((arr[i]>arr[j]) && (lis[i]<lis[j]+1))
               lis[i]=lis[j]+1;
        }
    }

    for(i=0;i<n;i++)
    {
        if(maxi<lis[i])
            maxi=lis[i];
    }
    free(lis);
    return maxi;
}

int main()
{
    int n,i,maxi;
    cout<<"Enter the number of elements of the array: ";
    cin>>n;
    int *arr=new int[n];
    cout<<"Enter the elements of the array: ";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    maxi=lis(arr,n);
    cout<<"The maximum length of increasing subsequence is "<<maxi;
    return 0;
}
