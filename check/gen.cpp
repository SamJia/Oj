#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
char result[1010] = {};

void insert(int begin, int end){
	if(end - begin < 2)
		return;
	int begin_flag, end_flag, flag;
	end_flag = rand() % (begin - end);
	begin_flag = rand() % end_flag;
	flag = rand()%3+1;
	result[begin+begin_flag] = flag+'0';
	result[begin+end_flag] = 3+flag+'0';
	if(rand()%3 == 2)
		return;
	else{
		if(rand()%3 < 2)
			insert(begin, begin+begin_flag);
		if(rand()%3 < 2)
			insert(begin+begin_flag+1, begin+end_flag);
		if(rand()%3 < 2)
			insert(begin+end_flag+1, end);
	}
}


main(){
	// while(1){
	// 	try{
	// 		srand(time(0));
	// 		char char_list[] = {"qwertyuiopasdfghjklzxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM<>              ,/?'\";:]}[{=+-_"};
	// 		int list_len = strlen(char_list);
	// 		int len = rand()%20+10;
	// 		for(int i = 0; i < len; ++i)
	// 			result[i] = char_list[rand()%list_len];
	// 		insert(0, len);
	// 		for(int i = 0; i < len; ++i){
	// 			if(result[i] == '1')
	// 				cout << "<red>";
	// 			else if(result[i] == '2')
	// 				cout << "<blue>";
	// 			else if(result[i] == '3')
	// 				cout << "<yellow>";
	// 			else if(result[i] == '4')
	// 				cout << "</red>";
	// 			else if(result[i] == '5')
	// 				cout << "</blue>";
	// 			else if(result[i] == '6')
	// 				cout << "</yellow>";
	// 			else
	// 				cout << result[i];
	// 		}
	// 		return 0;
	// 		// cout << result;
	// 	}
	// 	catch(...){}	
	// }
	srand(time(0));
	int n = rand();
	int b = rand() % n;
	int a = rand() % b;
	cout << n << ' ' << a << ' ' << b;
}
