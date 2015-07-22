#include "iostream"
#include "cstring"
using namespace std;

char months[12][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November" , "December"};

int Transform(char month[]);
int GetDayNumber(int year, int month, int day);

int main(){
	int total_number;
	char month1_char[10], month2_char[10], tmp_char;
	int month1, month2, day1, day2, year1, year2, result1, result2;
	cin >> total_number;
	for (int i = 0; i < total_number; ++i){
		cin >> month1_char >> day1 >> tmp_char >> year1;
		cin >> month2_char >> day2 >> tmp_char >> year2;
		month1 = Transform(month1_char);
		month2 = Transform(month2_char);
		result1 = GetDayNumber(year1, month1, day1 - 1);
		result2 = GetDayNumber(year2, month2, day2);
		cout << "Case #" << i + 1 << ": " << result2 - result1 << '\n';
	}
	return 0;
}

int Transform(char month[]){
	for (int i = 0; i < 12; ++i)
		if (!strcmp(months[i], month))
			return i+1;
	return -1;
}

int GetDayNumber(int year, int month, int day){
	// Contain thsi day.
	int last_year = year - 1;
	int result = last_year / 4 - last_year / 100 + last_year / 400;
	if (!(year%4) && (year%100) || !(year%400))
		if((month>2) || (month==2) && (day>=29))
			result++;
	return result;
}