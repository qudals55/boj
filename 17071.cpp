#include <bits/stdc++.h>
int n,k,d;
bool visit[500001];
std::queue<int> Q;
void go(int x){
    if(x>=0 && x<=500000 && !visit[x]) Q.push(x), visit[x]=true;
}
int main(){
    scanf("%d %d",&n,&k);
    Q.push(n);

    while(!Q.empty()){
        int sz= Q.size();
        while(sz--){
            int x = Q.front(); Q.pop();
            visit[x]=false;
            int chk =k+(d*(d+1)/2);
            if(chk>500000) break;
            if(x==chk){
                printf("%d",d);
                return 0;
            }
            go(x-1);
            go(x+1);
            go(x*2);
        }
        d++;
    }
puts("-1");
}