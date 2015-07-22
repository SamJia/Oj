#include <cstdio>
#include <cstring>
#include <algorithm>
#define SIZE 10010
struct Unit{
	char name_[25];
	int food_, wood_, level_;
} units[11];
int unit_number, time_number;
int food[SIZE], wood[SIZE], farmer = 0, resource, food_start = 0, wood_start = 0, food_end = 0, wood_end = 0, total_food = 0, total_wood = 0;
char type[5];

bool cmp(const Unit &unit1, const Unit &unit2){
	return unit1.level_ < unit2.level_;
}

main(){
	scanf("%d", &unit_number);
	for(int i = 0; i < unit_number; ++i)
		scanf("%s%d%d%d", &units[i].name_, &units[i].food_, &units[i].wood_, &units[i].level_);
	std::sort(units, units + unit_number, cmp);
	scanf("%d", &time_number);
	for(int i = 1; i <= time_number; ++i){
		scanf("%s%d", &type, &resource);
		resource += farmer;
		if(type[0] == 'f'){
			total_food += resource;
			food[food_end++] = resource;
		}
		else if(type[0] == 'w'){
			total_wood += resource;
			wood[wood_end++] = resource;
		}
		for(int j = unit_number - 1; j >= 0; --j)
			if(units[j].food_ <= total_food && units[j].wood_ <= total_wood){
				for(int remain_food = units[j].food_; remain_food > 0; remain_food -= food[food_start], total_food -= food[food_start++]);
				for(int remain_wood = units[j].wood_; remain_wood > 0; remain_wood -= wood[wood_start], total_wood -= wood[wood_start++]);
				if(!strcmp(units[j].name_, "farmer"))
					++farmer;
				printf("#%d: a %s was created.\n", i, units[j].name_);
				break;
			}
	}
	printf("food: %d, wood: %d\n", total_food, total_wood);
}