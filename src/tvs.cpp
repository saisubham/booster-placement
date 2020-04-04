#include "../include/tvs.h"

int max(int a,int b){
	//return maximum of the two arguments
	return a>b?a:b;
}

int tvs(tnode* root,int max_cost,vector<bool>& result_set){
	int cost=0;
	if(root==NULL) return 0;
	else if(root->tnc.empty())
		return root->w;
	else{
		for(auto i=root->tnc.begin();i!=root->tnc.end();++i)
			cost+=max(cost,tvs(*i,max_cost,result_set));
	}
	if(cost>max_cost){
		result_set[root->n]=true;
		vector<bool> flag(result_set.size(),true);
		printNTree(root,flag,0,false);
		cout<<'\n';
		for(auto i=root->tnc.begin();i!=root->tnc.end();++i)
			*i=NULL;
		return root->w;
	}
	else return cost;
}

int tvsMain(const char* fileName){
	FILE* f=fopen(fileName,"r");
	if(!f){
		perror("error");
		return 1;
	}

	int nv,max_cost,s,d,w;
	fscanf(f,"%d %d\n",&nv,&max_cost);
		graph g(nv);
		vector<bool> vis(nv,false);
	vector<bool> result_set(nv,false);
	vector<bool> flag(nv,true);
	while(fscanf(f,"%d %d %d\n",&s,&d,&w)!=EOF)
		g.addEdge(s,d,w);

	tnode* root=g.g2t(vis,0,0);

	cout<<"Input: (limit = "<<max_cost<<")\n\n";
	printNTree(root,flag,0,false);

	cout<<"\nWorking\n\n";
	tvs(root,max_cost,result_set);
	fill(flag.begin(),flag.end(),true);
		printNTree(root,flag,0,false);

	cout<<"\nBooster placement at: ";
	for(int i=0;i<nv;++i)
		if(result_set[i]==true)
			cout<<(char)(i+'A')<<' ';
	cout<<'\n';
		return 0;
}
