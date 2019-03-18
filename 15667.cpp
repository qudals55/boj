#include <bits/stdc++.h>
#define ll long long
#define MAX 50001

struct Rec
{
	int pos, s, e, id;
	bool operator <(const Rec& a) const{
		if(pos != a.pos) return pos < a.pos;
		return s < a.s; 
	}
};

Rec arr[2][MAX*2];

int N, x,y,w,h, par[MAX];
ll sze[MAX],ret;

int find(int p){
	return p==par[p] ? p:par[p] = find(par[p]);
}

void merge(int p, int q){
	p =find(p);
	q =find(q);
	if(p!=q){
		sze[p]+=sze[q];
		ret = std::max(ret,sze[p]);
		par[q] = p;
	}
}

bool safe(int s1, int e1, int s2, int e2){
	return (s1<=e2 && s2<=e1);
}

int main(){
	scanf("%d",&N);
	for(int i =0; i <N;i ++){
		scanf("%d %d %d %d",&x,&y,&w,&h);
		arr[0][i] = {y,x,x+w, i};
		arr[0][i+N] ={y+h, x,x+w,i};
		arr[1][i] = {x,y,y+h,i};
		arr[1][i+N] ={x+w, y, y+h,i};
		sze[i] = (ll)w*h;
		ret = std::max(ret, sze[i]);
		par[i]=i;
	}

	for(int j=0;j <2 ;j++){
		std::sort(arr[j],arr[j]+N*2);
		for(int i=0;i <N*2;i++){
			int p =i+1;
			while(arr[j][i].pos == arr[j][p].pos && safe(arr[j][i].s,arr[j][i].e,arr[j][p].s,arr[j][p].e)) p++;
			for(int k=i+1; k<p;k++) merge(arr[j][i].id, arr[j][k].id);
		}
	}
	printf("%lld",ret);
}
