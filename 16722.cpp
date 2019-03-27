#include <bits/stdc++.h>
using namespace std;
struct Shape{
    string s[3];
};
struct Case{
    int x,y,z;
};
int t,ret,pos[3],fl;
string A,B,C;
char ch;
Shape arr[11];
vector<Case> v;
bool visit[101];
int main(){
    for(int i =1; i <=9 ;i++) cin>>A>>B>>C, arr[i] ={A,B,C};
    for(int i =1; i <=9;i++){
        for(int j =i+1;j<=9;j++){
            for(int k =j+1;k<=9;k++){
                int f=0;
                for(int l =0; l<3;l++){
                    string aa=arr[i].s[l], bb=arr[j].s[l], cc=arr[k].s[l];
                    if(aa==bb && bb==cc) continue;
                    if(aa!=bb && bb!=cc && cc!=aa) continue;
                    f=1;
                }
                if(!f) v.push_back({i,j,k});
            }
        }
    }
    cin>>t;
    while(t--){
    
        cin>>ch;
        if(ch=='H'){
            int f=-1;
            for(int i =0; i <3; i++) cin>>pos[i];
            sort(pos,pos+3);
            for(int i =0; i<v.size();i++)
                if(v[i].x==pos[0] && v[i].y==pos[1] && v[i].z==pos[2]) f=i;
            if(f!=-1){
                if(visit[f]) ret--;
                else visit[f]=true,ret++;
            }
            else ret--;
        }
        if(ch=='G'){
            if(fl) ret--;
            else{
                int fll=0;
                for(int i =0; i <v.size();i++) if(!visit[i]) fll=1;
                if(fll) ret--;
                else fl=1, ret+=3;
            }
        }
    }
    cout<<ret;
}