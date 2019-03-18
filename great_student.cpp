#include <cstdio>
#include <algorithm>
#define INF 1e7
#define MAX 500001
typedef struct Data{int a;int b; int c;};
int tree[MAX],n,k,q;
Data d[MAX];
bool cmp(Data x, Data y){
    return x.a<y.a;
}
void update(int pos, int val){
while(pos<n+1) tree[pos]=std::min(tree[pos],val),pos+=pos&-pos;
}
int query(int pos){
    int ans=INF;
    while(pos>0) ans=std::min(tree[pos],ans),pos-=pos&-pos;
    return ans;
}
int main(){
    scanf("%d",&n);
    for(int i =1;i<=n; i++) tree[i]=INF;
    for(int i=1; i<=n ;i++)scanf("%d",&k),d[k].a=i;
    for(int i=1; i<=n ;i++)scanf("%d",&k),d[k].b=i;
    for(int i=1; i<=n ;i++)scanf("%d",&k),d[k].c=i;
    std::sort(d+1,d+n+1,cmp);
    for(int i =1; i <=n;i++) q+=query(d[i].b)>d[i].c,update(d[i].b,d[i].c);
    printf("%d",q);
}