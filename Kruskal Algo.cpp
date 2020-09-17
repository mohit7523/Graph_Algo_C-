#include<bits/stdc++.h>
using namespace std;

struct E{
	int a;
	int b;
	int w;

};
E ar[100];
int par[1000];
bool comp(E a, E b)
{
	if(a.w<b.w)
	return true;
	return false;
}
void merge(int a,int b)
{
	par[a]=b;
}
int find(int a)
{
	if(par[a]==-1)
	return a;
	return par[a]=find(par[a]);
}
int main(){
	int a,b,w,m,n;
	cin>>n>>m;
	for(int i=0; i<n; i++)
	par[i]=-1;
	for(int i=0; i<m; i++)
	cin>>ar[i].a>>ar[i].b>>ar[i].w;
	sort(ar,ar+m,comp);
	int sum=0;
	for(int i=0; i<m; i++)
	{
		int p=find(ar[i].a);
		int q=find(ar[i].b);
		if(p!=q)
		{
			sum+=ar[i].w;
			merge(p,q);
		}
	}
	cout<<sum;
	return 0;
}
