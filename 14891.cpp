#include <bits/stdc++.h>
using namespace std;
string s[4];
int t,n,m,ret,check[4];
string rotate(string a, int k){
    string b;
    if(k==-1){
    for(int i=1; i<8;i++) b+=a[i];
    b+=a[0];
    }
    else{
    b= a[7];
    for(int i =0; i<7;i++) b+=a[i];  
    }
    return b;
}

int main(){
    for(int i =0; i <4; i++) cin>>s[i];
    cin>>t;
    while(t--){
        memset(check,false,sizeof(check));
        cin>>n>>m;
        check[n-1] = m;
        int p=n-2, q= n;
        while(p>=0 || q<4){
            if(p>=0 && check[p+1] && s[p][2]!= s[p+1][6])check[p]= check[p+1] > 0? -1:1;
            if(q<4 && check[q-1] && s[q-1][2]!= s[q][6]) check[q]= check[q-1] >0 ? -1:1;
            p--;q++;
        }
        for(int i =0; i <4; i++) if(check[i]) s[i] = rotate(s[i], check[i]);
    }
    for(int i =0; i <4; i++) if(s[i][0]=='1') ret+=pow(2,i);
    printf("%d",ret);
}