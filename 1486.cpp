#include <bits/stdc++.h>

int N,M,D,T,rvdist[630], dist[630], arr[26][26], ret, dc[4]={1,-1,0,0}, dr[4]={0,0,1,-1};
char ch;

bool safe(int x, int y){
	return (x>=0 && x<N && y>=0 && y<M);
}

void solve(std::vector<std::pair<int, int>> v[630], int d[630]){
	std::fill(d, d+630, 1e9);
	std::priority_queue<std::pair<int, int > > Q;
	Q.push({0,0});
	d[0] = 0;
	while(!Q.empty()){
		auto cur =Q.top();
		Q.pop();
		cur.first = -cur.first;
		if(cur.first > d[cur.second]) continue;

		for(auto next: v[cur.second])
			if(d[next.first] > cur.first + next.second) d[next.first] = cur.first + next.second, Q.push({-d[next.first],next.first});
	}
}

int main(){
	scanf("%d %d %d %d",&N,&M,&T,&D);
	for(int i =0; i <N; i++ ) {
		getchar();
		for(int j =0; j <M ;j++) {
			ch=getchar();
			 arr[i][j] = ch-'A'<26 ? ch-'A' : ch-'a'+26;
		}
}

std::vector<std::pair<int, int> > p[630], q[630];

for(int i =0; i <N ;i++){
	for(int j =0;j <M;j++){
		for(int k =0;  k<4;k++){
			int nc = i+dc[k], nr = j+dr[k];
			if(safe(nc, nr)){
				if(abs(arr[i][j]-arr[nc][nr]) >T) continue;
				if(arr[i][j]- arr[nc][nr]>=0) p[i*M+j].push_back({nc*M+nr, 1});
				else p[i*M+j].push_back({nc*M+nr, pow(arr[nc][nr] - arr[i][j],2)});
				if(arr[nc][nr]-arr[i][j]>=0) q[i*M+j].push_back({nc*M+nr, 1});
				else q[i*M+j].push_back({nc*M+nr, pow(arr[nc][nr] - arr[i][j],2)});
			}
		}
	}
}

ret = arr[0][0];
solve(p,dist);
solve(q,rvdist);
for(int i =0; i <N ;i++)
	for(int j =0;j <M;j++)
		if(dist[i*M+j] + rvdist[i*M+j] <=D) ret= std::max(ret, arr[i][j]);

printf("%d",ret);
}
