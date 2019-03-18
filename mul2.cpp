#include <cstdio>
#define MAX 100001
int tree[MAX*4],n,m,a,b,k;
char c;
int update(int node, int s, int e, int val, int pos){
	if(!(s<=pos&&pos<=e)) return tree[node];
	if(s==e) return tree[node]=val;
	int mid=(s+e)>>1;
	return tree[node] =  update(node*2,s,mid,val,pos)*update(node*2+1,mid+1,e,val,pos);
}
int query(int node, int s, int e, int l, int r){
	if(s>r || e<l) return 1;
	if(l<=s&&e<=r) return tree[node];
	int mid=(s+e)>>1;
	return query(node*2,s,mid,l,r)*query(node*2+1,mid+1,e,l,r);
}
int main(){
	while(~scanf("%d %d",&n,&m)){
		for(int i =0; i <n ;i++) scanf("%d",&a), a=a>0?1:a==0?0:-1,update(1,0,n-1,a,i);
		while(m--){
			scanf("%s %d %d",&c,&a,&b);
			if(c=='C') b=b>0?1:b==0?0:-1,update(1,0,n-1,b,a-1);
			else k=query(1,0,n-1,a-1,b-1),printf("%c",k>0?'+':k==0?'0':'-');
		}
		printf("\n");
	}
}