#include <iostream>
#include <vector>
#include <list>
#include <math.h>
#include <stdio.h>
using namespace std;

struct tnode{
		int n,w;
		list<tnode*> tnc;
		tnode(int _n,int _w):n(_n),w(_w){}
};

class graph{
	int nv;
	list<pair<int,int>>* adj;
public:
	graph(int _nv);
	void addEdge(int s,int d,int w);
	tnode* g2t(vector<bool> vis,int i,int wt);
};

int max(int a,int b);
int tvs(tnode* x,int m,vector<bool>& res);
void printNTree(tnode* root,vector<bool> flag,int d,bool isLast);
int tvsMain(const char* fileName);
