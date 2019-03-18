#include <cstdio>
#define ll long long
#define MAX 1000001
ll tree[MAX];
int a,b,c,n,k;
void update(int i,int val){
	while(i<n+1) tree[i]+=val,i+=i&-i;
}
ll query(int i){
	ll q=0;
	while(i>0) q+=tree[i],i-=i&-i;
	return q;
}
int main(){
	scanf("%d %d",&n,&k);
	while(k--){
		scanf("%d %d %d",&a,&b,&c);
		if(a==1) update(b,c);
		else printf("%lld\n",query(c)-query(b-1));
	}
}