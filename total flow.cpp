#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct Edge{
	int to, c, f;
	Edge *dual;
	Edge() : Edge(-1, 0){}
	Edge(int _to, int _c): to(_to),c(_c),f(0),dual(NULL){}
	int sparce (){
		return c-f;
	}
	void addFlow(int _f){
		f+=_f;
		dual->f-=_f;
	}
};
int Ctoi(char c){
	if(c<='Z') return c-'A';
	return c-'a'+26;
}
int n,w;
char u,v;
vector<Edge*> adj[52];
int main(){
	cin>>n;
	while(n--){
		cin>>u>>v>>w;
		u=Ctoi(u);v=Ctoi(v);
		Edge *e1 = new Edge(v,w), *e2 = new Edge(u,w);
		e1->dual=e2;
		e2->dual=e1;
		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}
	int total = 0, S =Ctoi('A'),E=Ctoi('Z');
	while(1){
		Edge *path[52];
		int prev[52]={};
		fill(prev, prev+52,-1);
		queue <int >q;
		q.push(S);
		while(!q.empty() && prev[E]==-1){
			int cur=q.front(); q.pop();
			for(Edge *e: adj[cur]){
				int next =e->to;
				if(e->sparce()>0 && prev[next]==-1){
					q.push(next);
					prev[next]=cur;
					path[next]=e;
					if(next==E) break;
				}
			}
		}
		if(prev[E]==-1) break;			
		int flow = 1e9;
		for(int i=E ; i!=S ;i=prev[i]) flow = min(flow, path[i]->sparce());
		for(int i =E; i!=S; i=prev[i]) path[i]->addFlow(flow);
		total +=flow;
		}
		cout<<total;
	}