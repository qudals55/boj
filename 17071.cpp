#include <bits/stdc++.h>
int n,k,d;
bool visit[500001];
std::queue<int> Q;
void safe(int x){
    if(x>=0 && x<=500001 && !visit[x]) Q.push(x), visit[x]=true;
}
int main(){
    scanf("%d %d",&n,&k);
    Q.push(n);

    while(!Q.empty()){
        int sz= Q.size();
        while(sz--){
            int x = Q.front(); Q.pop();
            int chk =k+(d*(d+1)/2);
            if(chk>500000){
                puts("-1"); return 0;
            }
            if(x==chk){
                printf("%d",d); return 0;
            }
            safe(x-1);
            safe(x+1);
            safe(x*2);
        }
        d++;
        memset(visit,false,sizeof(visit));
    }
puts("-1");
}