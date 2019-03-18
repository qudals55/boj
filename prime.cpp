#include <cstdio>
#include <vector>
#include <algorithm>
int c[26],v[26],n,k,t,x;
std::vector<int> adj[26],a,b,d;
bool p(int x){
	for(int i =2; i*i<=x;i++) if(!(x%i)) return false;
	return true;
}
int dfs(int i){
	v[i]=1;
	for(int to:adj[i])if(c[to]==-1 || !v[c[to]] && dfs(c[to])){c[to]=i;return 1;}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i =0; i < n ;i++) {
		scanf("%d",&t);
		if(i==0 && t%2) x=1;
		t%2 ? a.push_back(t):b.push_back(t);
	}
	if(a.size()!=b.size()) {printf("-1");return 0;}
	if(!x) std::swap(a,b);
	for(int i =0; i <a.size();i++) for(int j =0; j <b.size();j++) if(p(a[i]+b[j])) adj[i].push_back(j);
	for(int i:adj[0]){
		k=1;
		std::fill(c,c+26,-1);
		c[i]=0;
		for(int j=1;j<a.size();j++) std::fill(v,v+26,0), v[0]=1, k+=dfs(j);
		if(k==a.size()) d.push_back(b[i]);
	}
	std::sort(d.begin(),d.end());
	if(d.size()) for(int i: d) printf("%d ",i);
	else printf("-1");
}
