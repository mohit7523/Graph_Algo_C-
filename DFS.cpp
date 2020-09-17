#include<bits/stdc++.h>
using namespace std;
class Graph{
	int V;
	list<int>*adj;
		void DFSUtil(bool visited[], int v);
	public:
		Graph(int v);
		void DFS(int V);
		void addedge(int u, int w);
};
 Graph::Graph(int V)
 {
 	this->V=V;
 	adj=new list<int>[V];
 }
 void Graph::addedge(int u,int w)
 {
 	adj[u].push_back(w);
 }
 void Graph::DFSUtil(bool visited[],int v)
 {
   visited[v]=true;
   cout<<v<<" ";
   list<int>::iterator i;
   for(i=adj[v].begin(); i!=adj[v].end(); ++i)
   if(!visited[*i])
   DFSUtil(visited,*i);
 }
 void Graph::DFS(int v)
 {
 	bool*visited=new bool[v];
 	for(int i=0; i<v; i++)
 	{
	visited[i]=false;
    }
 	DFSUtil(visited,v);
 }
 int main()
 {

 	
 	Graph g(4);
 	g.addedge(0,1);
 	g.addedge(0,2);
 	g.addedge(0,3);
 	g.addedge(1,2);
 	g.addedge(2,3);
 		g.addedge(3,3);
 	cout<<"DFS traversal started from vertex 1:"<<endl;
    g.DFS(3);
 }
