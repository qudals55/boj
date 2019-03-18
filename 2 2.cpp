#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Point{
	int x;
	int y;
};

Point walk(int w, int num_of_lines, int num_of_space, int point, int start_x, int start_y)
{ //분할정복법

	Point res;

	int area, next_point;

	//base case
	if(num_of_lines == 2){ //w=1
		if(next_point == 0) {
			res.x = start_x + 1;
			res.y = start_y + 1;
		}
		else if(next_point == 1) {
			res.x = start_x + 1;
			res.y = start_y + 2;
		}
		else if(next_point == 2) {
			res.x = start_x + 2;
			res.y = start_y + 2;
		}
		else if(next_point == 3) {
			res.x = start_x + 2;
			res.y = start_y + 1;
		}
		return res;
	}

	//recursive
	else {
		//영역에 따라 시작점과 순회 방향이 달라짐
		int tmp = pow(4,w-1);
		area = point / tmp + 1; //w3에서 39번이면, 39 나누기 16 = 2 ... 7 -> 몫+1 = area
		next_point =  point % tmp; //다음 제귀 레벨(w-1)에서 point의 번호
		if(area == 1) { //영역1이면 시작점 그대로 x+=0 y+=0
			return walk(w-1, num_of_lines/2, num_of_space%4, next_point, start_x, start_y);
		}
		else if(area ==2){ //영역2면, 다음 재귀레벨에서 시작점은 x+=0, y+=num_of_lines/2
			return walk(w-1, num_of_lines/2, num_of_space%4, next_point, start_x, start_y + num_of_lines/2);
		}
		else if(area ==3){ //영역3면, 다음 재귀레벨에서 시작점은 x+=num_of_lines/2, y+=num_of_lines/2
			return walk(w-1, num_of_lines/2, num_of_space%4, next_point, start_x + num_of_lines/2, start_y + num_of_lines/2);
		}
		else { //영역4면, 다음 재귀레벨에서 시작점은 x+=num_of_lines/2, y+=0
			return walk(w-1, num_of_lines/2, num_of_space%4, next_point, start_x + num_of_lines/2, start_y);
		}
	}
}



int main(){

	Point p;

	int w, pnt; //몇번째 철학자의 길인지, 그 중 몇번째 점인지
	scanf("%d %d", &w, &pnt);

	int numLines = pow(2, w);
	int numSpace = pow(numLines, 2);

	p = walk(w, numLines, numSpace, pnt, 0, 0); //몇번째 walk인지, 줄의수 , 총칸의 수, 
	cout<<p.x<<" "<<p.y<<endl;

	return 0;
}