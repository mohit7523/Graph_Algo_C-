#include<bits/stdc++.h>
using namespace std;
#define V 4
bool isBipartite(int G[][V],int src)
{
	int color[V]={-1};
	color[src]=1;
	queue<int>q;
	q.push(src);
	while(!q.empty())
    {
    	int u=q.front();
    	q.pop();
    	if(G[u][u]==1)
    	return false;
    	for(int i=1; i<=V; i++)
    	{
    		if(G[u][i] && color[i]==-1)
    		{
			color[i]=1-color[u];
			q.push(i);
		   }
		   else if(G[u][i] && color[u]==color[i])
		   return false;
		}
	}
	return true;	
}
int main()
{
	
	int G[V][V]={{0,1,0,1},
	             {1,0,1,0},
				 {0,1,0,1},
				 {1,0,1,0}};
     if(isBipartite(G,0))
     cout<<"The Graph is Bipartite!!!"<<endl;
     else
      cout<<"The Graph is not Bipartite!!!"<<endl;
      return 0;
     
}
