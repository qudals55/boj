#include <cstdio>
#include <vector>
#define ll long long
ll n,k,x,m,t;
int main(){
	scanf("%lld %lld",&n,&m);
	std::vector<ll> s(n,0);
	for(ll i =0; i <n ;i++) scanf("%lld",&x),k+=x,s[i]=k;
	 while(m--) scanf("%lld",&t), printf("%lld\n",std::upper_bound(s.begin(),s.end(),t)-s.begin());
}