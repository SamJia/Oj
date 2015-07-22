#include <iostream>
#define SIZE 10
main(int argc, char const *argv[])
{
	for(char i = 0; i / 10 < 9; i += 10){
		for(i -= i % 10; i % 10 < 9; ++i){
			if(i /10 % 3 - i % 10 % 3){
				std::cout << "A: " << (char) ('d' + i / 10 % 3) << 10 - i /10 / 3 << "    ";
				std::cout << "B: " << (char) ('d' + i % 10 % 3) << i % 10 / 3 << '\n';
			}
		}
	}
}