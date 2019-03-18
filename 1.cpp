#include <bits/stdc++.h>
using namespace std;
#define MAX 10000
struct Edge{
	int to, c, f;
	Edge *dual;
	Edge(): Edge(-1, 0){}
	Edge(int to1, int c1): to(to1), c(c1), f(0), dual(NULL){}
	void addFlow(int f1){
		f += f1;
		dual->f -= f1;
	}
	int sparce(){
		return c-f;
	}
};
int S=1,E=2;
int t,n,m,K,x;
int main(){
	for(int p =1;;p++){
		scanf("%d %d", &K, &n);
		if(!K) break;
		vector<Edge*> adj[MAX];
		for(int i =0; i < n ;i++){
			Edge* e1, *e2;
			if(i>=2){
				e1 = new Edge(i*2+1,1);
				e2 = new Edge(i*2, 0);
				e1->dual = e2;
				e2->dual =e1;
				adj[i*2+1].push_back(e2);
				adj[i*2].push_back(e1);
			}
			while(1){
				char ch;
				scanf("%d%c",&x,&ch);
				x--;
				e1 = new Edge(x*2,1);
				e2 = new Edge(i*2+1,0);
				e1->dual = e2;
				e2->dual = e1;
				adj[x*2].push_back(e2);
				adj[i*2+1].push_back(e1);
				if(ch=='\n') break;
			}
		}
		int fl=0;
		for(int i =0; i <K;i++){
			vector <int> prev(MAX,-1);
			Edge* path[MAX]={NULL};
			queue <int> q;
			q.push(S);
			while(!q.empty() && prev[E]==-1){
				int cur =q.front(); q.pop();
				for(Edge *e: adj[cur]) {
					int next =e->to;
					if(prev[next]==-1 && e->sparce()) q.push(next), prev[next]= cur,path[next] =e;
				}
			}
			if(prev[E]==-1){
				fl=1; break;
			}
			for(int  i =E; i!=S; i=prev[i]) path[i]->addFlow(1);
		}
	printf("Case %d:\n", p);
		if(fl) puts("Impossible");
		else{
			for(int k=0; k<K; k++){
				int prev = -1e9, curr = S;
				while(curr != E){
					if(prev/2 != curr/2) printf("%d ", curr/2+1);
					prev = curr;
					for(Edge *e: adj[curr]){
						int next = e->to;
						if(e->f == 1){
							e->f = 0;
							curr = next;
							break;
						}
					}
				}
				printf("%d\n", E/2+1);
			}
	}
	printf("\n");
}
}