#include <iostream>
#include <algorithm>
using namespace std;
#define SIZE 50010
#define UP first
#define DOWN second
#define X first
#define Y second
#define UPPERLIMIT 100007
pair<int, int> points[SIZE], line_number[SIZE][12];
int points_number, section_number;
 
void InputAndInit();
int FindRootNumber();
int UpToEnd(int start_point, int remain_section);
int DownToEnd(int start_point, int remain_section);
void Output(int result);
 
main(){
	InputAndInit();
	int result = FindRootNumber();
	Output(result);
}
 
void InputAndInit(){
	pair<int, int> init_pair0, init_pair1;
	init_pair0.first = init_pair0.second = 0;
	init_pair1.first = init_pair1.second = 1;
	cin >> points_number >> section_number;
	for(int i = 0; i < points_number; ++i){
		cin >> points[i].X >> points[i].Y;
		line_number[i][0] = init_pair1;
		for(int j = 1; j < 11; ++j)
			line_number[i][j] = init_pair0;
	}
	sort(points, points + points_number);
}
 
int FindRootNumber(){
	int result = 0;
	for(int i = points_number - 1; i >= 0; --i){
		result = (result + UpToEnd(i, section_number)) % UPPERLIMIT;
		result = (result + DownToEnd(i, section_number)) % UPPERLIMIT;
		cout << result << '\n';
	}
	return(result);
}
 
int UpToEnd(int start_point, int remain_section){
	if(!line_number[start_point][remain_section].UP){
		int result = 0;
		for(int i = start_point + 1; i < points_number; ++i)
			if(points[i].Y > points[start_point].Y){
				result = (result + UpToEnd(i, remain_section)) % UPPERLIMIT;
				result = (result + DownToEnd(i, remain_section - 1)) % UPPERLIMIT;
			}
		line_number[start_point][remain_section].UP = result;
	}
	return line_number[start_point][remain_section].UP;
}
 
int DownToEnd(int start_point, int remain_section){
	if(!line_number[start_point][remain_section].DOWN){
		int result = 0;
		for(int i = start_point + 1; i < points_number; ++i)
			if(points[i].Y < points[start_point].Y){
				result = (result + UpToEnd(i, remain_section - 1)) % UPPERLIMIT;
				result = (result + DownToEnd(i, remain_section)) % UPPERLIMIT;
			}
		line_number[start_point][remain_section].DOWN = result;
	}
	return line_number[start_point][remain_section].DOWN;
}
 
void Output(int result){
	cout << result;
}