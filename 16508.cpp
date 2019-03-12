#include <bits/stdc++.h>
using namespace std;
string s[17],k;
int ans[26], str[17][26], n,x=1e9,v[17],w[17];
void f(int a){
	int y[26]={},s=0;
	if(a==n){
		for(int i =0; i <n ;i++) {
			if(v[i]) {
				s+=w[i];
				for(int j=0; j <26;j++)y[j] +=str[i][j];
			}
	}
	for(int i =0; i <26;i++) if(ans[i]>y[i]) return;
	x=min(x,s);
	return;
}
v[a] = true;
f(a+1);
v[a]=false;
f(a+1);
}
int main(){
	cin>>k>>n;
	for(int i =0; i <k.size();i++) ans[k[i]-'A']++;
		for(int i =0; i <n ; i++) {
			cin>>w[i]>>s[i];
			for(int j =0; j<s[i].size();j++) str[i][s[i][j]-'A']++;
		}
	f(0);
	x==1e9?cout<<-1:cout<<x;
}