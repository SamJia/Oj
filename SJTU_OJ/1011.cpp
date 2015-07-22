#include <iostream>
#include <cstdio>
using namespace std;

class Complex{
public:
	Complex(int x_pos, int y_pos):x(x_pos), y(y_pos){};
	void plus(Complex num, int flag = 0){
		double tmp_x = x + num.x, tmp_y = y + num.y;
		printf("%.2f %.2f\n", tmp_x, tmp_y);
		if(flag){
			x = tmp_x;
			y = tmp_y;
		}
	}

	void minus(Complex num, int flag = 0){
		double tmp_x = x - num.x, tmp_y = y - num.y;
		printf("%.2f %.2f\n", tmp_x, tmp_y);
		if(flag){
			x = tmp_x;
			y = tmp_y;
		}
	}

	void prod(Complex num, int flag = 0){
		double tmp_x = x * num.x - y * num.y, tmp_y = x * num.y + y * num.x;
		printf("%.2f %.2f\n", tmp_x, tmp_y);
		if(flag){
			x = tmp_x;
			y = tmp_y;
		}
	}

	void divide(Complex num, int flag = 0){
		int tmp_num = num.x * num.x + num.y * num.y;
		double tmp_x = (x * num.x + y * num.y) / tmp_num, tmp_y = (y * num.x - x * num.y) / tmp_num;
		printf("%.2f %.2f\n", tmp_x, tmp_y);
		if(flag){
			x = tmp_x;
			y = tmp_y;
		}
	}
private:
	double x, y;
};

main(){
	int x, y;
	cin >> x >> y;
	Complex num1(x, y);
	cin >> x >> y;
	Complex num2(x, y);
	num1.plus(num2);
	num1.minus(num2);
	num1.prod(num2);
	num1.divide(num2);
	num1.plus(num2, 1);
	num1.minus(num2, 1);
	num1.prod(num2, 1);
	num1.divide(num2, 1);
}