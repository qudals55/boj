#include <bits/stdc++.h>
int n,m,k,d[1001],l,r;

int main(){

	scanf("%d %d %d",&n,&m,&k);

	for(int i =0 ; i <m;i++) scanf("%d",d+i);

	l=1, r=n+1;
	while(l+1<r){

		int mid = (l+r)/2,f=0;

		for(int i =0; i < m && f ;i++){
			int pre = i, cur=i+1,c=0;
			while(cur < m){
				if(d[cur] - d[pre] >= mid){
					c++;
					pre=cur;
					if(c == k) {
						f=1;
						break;
					}
				}
				cur++;
			}

			if(n-d[pre]+d[i] >=mid) c++;

			if(c>=k){
				f=1;
				break;
			}
			
		}
		if(f) l = mid;
		else r= mid;
	}
	printf("%d",l);
}