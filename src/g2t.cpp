#include "../include/tvs.h"

graph::graph(int _nv):nv(_nv){
        adj=new list<pair<int,int>>[nv];
}
void graph::addEdge(int s,int d,int w){
	adj[s].push_back(make_pair(d,w));
}
tnode* graph::g2t(vector<bool> vis,int i=0,int wt=0){
	vis[i]=true;
	tnode* tn=new tnode(i,wt);
	for(auto j=adj[i].begin();j!=adj[i].end();++j)
		if(!vis[j->first])
			tn->tnc.push_back(g2t(vis,j->first,j->second));
	vis[i]=false;
	return tn;
}
