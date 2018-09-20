#include<iostream>
using namespace std;
int stolenHouse(int a[],int look_up[],int i,int n)
{
	if(look_up[i]!=-1)
		return look_up[i];
	if(i==n-1){
		look_up[i]=a[i];
		//cout<<"Max for "<<i<<" is"<<a[i]<<"\n";
		return a[i];
	}
	if(i==n-2){
		look_up[i]=a[i];
		//cout<<"Max for "<<i<<" is"<<a[i]<<"\n";
		return a[n-2];
	}
	int k,p,max=0,t,s;
	k=n-(i+2);
	p=i+2;
	s=1;
	while(s<=k)
	{
		t=stolenHouse(a,look_up,p,n);
		p=p+1;
		s++;
		if(t+a[i]>max)
			max=t+a[i];
	}
	look_up[i]=max;
	//cout<<"Max for "<<i<<" is "<<max<<"\n";
	return max;
}
int main()
{
	int a[1000],i,n,max,look_up[1000];
	cout<<"Enter the number of houses: ";
	cin>>n;
	cout<<"Enter the value of each of the house: ";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	for(i=0;i<n;i++)
	{
		look_up[i]=-1;
	}
	max=stolenHouse(a,look_up,0,n);
	cout<<"The maximum value stolen from the house is: "<<max<<"\n";
	return 0;
}
