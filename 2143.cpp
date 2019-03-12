#include <bits/stdc++.h>
int A[1001], B[1001], T, n,m;
long long ret;
std::vector<int> b;
int main(){
	scanf("%d %d",&T,&n);
	for(int i =0; i <n; i++) scanf("%d",A+i);
	scanf("%d",&m);
	for(int i =0; i <m ;i++) scanf("%d",B+i);

	for(int i =0; i <m ;i++){
		int sum=0;
		for(int j =i; j<m;j++)
			sum+=B[j], b.push_back(sum);
	}

	std::sort(b.begin(), b.end());

	for(int i =0; i <n ;i++){
		int sum=0;
		for(int j =i; j <n ;j++){
			sum+=A[j];
			ret += (std::upper_bound(b.begin(), b.end(), T-sum)-b.begin()) - (std::lower_bound(b.begin(), b.end(), T-sum)-b.begin());
		}
	}
	printf("%lld",ret);
}