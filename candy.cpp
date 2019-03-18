#include <cstdio>
int tree[4000004],n,a,b,c;
void update(int node,int s, int e, int pos, int val){
    if(pos<s || pos>e) return;
    tree[node]+=val;
    if(s!=e){
        int mid=(s+e)>>1;
        update(node*2,s,mid,pos,val); update(node*2+1,mid+1,e,pos,val);
    }
}
void query(int node, int s, int e,int com){
    tree[node]-=1;
    if(s==e) {printf("%d\n",s);return;}
    int mid=(s+e)>>1;
    if(com<=tree[node*2]) query(node*2,s,mid,com);
    else query(node*2+1,mid+1,e,com-tree[node*2]);
}
int main(){
    scanf("%d",&n);
    for(int i =0; i <n;i++){
        scanf("%d",&a);
        if(a==2) scanf("%d %d",&b,&c),update(1,1,1000000,b,c);
        else scanf("%d",&b),query(1,1,1000000,b);
    }
}
