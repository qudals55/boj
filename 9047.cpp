#include <bits/stdc++.h>
bool visit[10001];
int T,n,d[4],s[4];
int get(int a[4]){
    return a[0]*1000+a[1]*100+a[2]*10+a[3];
}
bool cmp(int a, int b){
    return a>b;
}
int main(){
    scanf("%d",&T);
    while(T--){
        int ret =1;
        for(int i =0; i <4; i++) scanf("%1d",d+i),s[i]=d[i];
        while(ret){
            if(get(d)==6174) {
                printf("%d\n",ret-1);
                break;
            }
            std::sort(s,s+4);
            std::sort(d,d+4,cmp);
            int t= get(d) - get(s);
            d[0] = t/1000; d[1] = (t%1000)/100, d[2] = (t%100)/10, d[3]=t%10;
            memcpy(s,d,sizeof(s));
            ret++;
        }
    }
}