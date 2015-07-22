#include "iostream"
#define SIZE 10010
using namespace std;

int main(int argc, char const *argv[])
{
	int total_number, result = 0, numbers[SIZE];
	cin >> total_number;
	for(int i = 0; i < total_number - 1; ++i)
		cin >> numbers[i];
	for(int i = total_number - 2; i >= 0; --i)
		result = (result + numbers[i]) % (total_number - i);
	cout << result + 1;
	return 0;
}