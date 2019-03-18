#include <cstdio>
#include <algorithm>
#define ll long long
std::pair<ll,int> p[100001];
int n,m,a,b;
int main(){
	scanf("%d%d",&n,&m);
	for(int i =0; i<n ;i++) scanf("%lld",&p[i].first),p[i].second = i+1;
	std::sort(p,p+n);
	while(m--){
		scanf("%d %d",&a,&b);
		for(int i =0; i <n ;i++){
			if(p[i].second>=a && p[i].second<=b){printf("%lld\n",p[i].first);break;}
		}
	}	
}