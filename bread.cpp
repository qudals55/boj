#include <bits/stdc++.h>
using namespace std;
int N, A[100010], tree[100010], from[100010], cnt;
void upt(int x){
	for( ; x<=N; x+=x&(-x))	tree[x]++;
}
int sum(int x){
	int res=0;
	for(; x>=1; x-=x&(-x))	res+=tree[x];
	return res;
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>N;
	for(int i=1; i<=N; i++){
		cin>>A[i];
		from[A[i]]=i;
	}
	for(int i=1, x; i<=N; i++){
		cin>>x;
		int f=from[x];
		cnt = cnt + (sum(N) - sum(f));
		upt(f);
	}
	cout<<(cnt%2==0?"Possible":"Impossible")<<endl;;
	cout<<cnt;
	return 0;
}