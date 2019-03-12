#include <cstdio>
#include <queue>
struct K{int a,b,c;};
int x,y,w,z,dx[4]={1,-1,0,0},dy[4]={0,0,-1,1},ddx[8]={2,2,-2,-2,2,-2,2,-2},ddy[8]={2,-2,2,-2,-2,-2,2,2};
bool safe(int c, int r,int f){
	if(c <10 && c>=0 && r<9 && r>=0) {
		if(f==0) return true;
		if(c==w&&r==z) return false;
		return true;
	}
	return false;
}
int main(){
	scanf("%d %d %d %d",&x,&y,&w,&z);
	std::queue<K> q;
	q.push({x,y,0});
	while(!q.empty()){
		int c = q.front().a,r =q.front().b, cur=q.front().c;q.pop();
		if(c==w && r ==z) {
			printf("%d",cur);return 0;
		}
		for(int i =0; i <4 ; i++){
			if(safe(c+dx[i],r+dy[i],1)){
				for(int j =i*2; j <i*2+2; j++){
					int curc=c+dx[i]+ddx[j]/2,curr=r+dy[i]+ddy[j]/2;
					if(safe(curc,curr,1)){
						curc+=ddx[j]/2; curr+=ddy[j]/2;
						if(safe(curc,curr,0)) q.push({curc,curr,cur+1});
					}
				}
			}
		}
	}
	puts("-1");
}
