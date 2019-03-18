#include <bits/stdc++.h>
std::string s;
int t,a,b;
int main(){
    std::cin>>s>>t;
    while(t--){
        std::cin>>a>>b;
        std::swap(s[a],s[b]);
    }
    std::cout<<s;
}