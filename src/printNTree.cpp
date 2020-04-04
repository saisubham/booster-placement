#include "../include/tvs.h"

void printNTree(tnode* x,vector<bool> flag,int depth=0,bool isLast=false){
	if(x==NULL)
		return;
	for(int i=1;i<depth;++i){
		if(flag[i])
			cout<<"│   ";
		else
			cout<<"    ";
	}
	if(depth==0)
		cout<<"["<<x->w<<"] "<<(char)(x->n+'A')<<'\n';
	else if(isLast){
		cout<<"└── "<<"["<<x->w<<"] "<<(char)(x->n+'A')<<'\n';
		flag[depth]=false;
	}
	else
		cout<<"├── "<<"["<<x->w<<"] "<<(char)(x->n+'A')<<'\n';
	int it=0;
	for(auto i=x->tnc.begin();i!=x->tnc.end();++i,++it)
		printNTree(*i,flag,depth+1,it == (x->tnc.size()) - 1);
	flag[depth]=true;
}
