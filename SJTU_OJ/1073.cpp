/****************************************
*                                       *
*     Coperight:Sam Jia                 *
*     email:sammailbox@126.com          *
*										*
*										*
****************************************/

#include <iostream>
#include <fstream>
using namespace std;
//--------------------------
struct Region{
	int begin, end;
};
int energy_necklace[1010] = {0}, max_energy_found[1010][1010] = {0}, change_to_next[1010] = {0};
int number_of_bead = 0;
ifstream fin(".txt");
//--------------------------
void Input();
int FindMaxEnergy();
void FindBeginAndEnd(Region &total_region, int i);
int FindMaxEnergyWithRegion(Region now_region);
void RegionInit(Region now_region, Region &first_region, Region &second_region);
void RegionChange(Region &first_region, Region &second_region);
int CalculateTmpMax(Region first_region, Region second_region);
void Output(int max_energy);
//--------------------------

main(){
	Input();
	int max_energy = FindMaxEnergy();
	Output(max_energy);
}

void Input(){
	cin >> number_of_bead;
	for(int i = 0; i < number_of_bead; ++i){
		cin >> energy_necklace[i];
		change_to_next[i] = i + 1;
	}
	energy_necklace[number_of_bead] = energy_necklace[0];
	change_to_next[number_of_bead - 1] = 0;
}

int FindMaxEnergy(){
	int max_energy = 0, tmp_max_energy = 0;
	Region total_region;
	for(int i = 0; i < number_of_bead; ++i){
		FindBeginAndEnd(total_region, i);
		tmp_max_energy = FindMaxEnergyWithRegion(total_region);
		max_energy = max(max_energy, tmp_max_energy);
	}
	return(max_energy);
}

void FindBeginAndEnd(Region &total_region, int i){
	total_region.begin = i;
	total_region.end = i > 0 ? i - 1 : number_of_bead - 1;
}

int FindMaxEnergyWithRegion(Region now_region){
	if(now_region.begin == now_region.end)
		return(0);
	if(!max_energy_found[now_region.begin][now_region.end]){
		int max_energy = 0, tmp_max_energy = 0;
		Region first_region, second_region;
		for(RegionInit(now_region, first_region, second_region); second_region.begin != change_to_next[second_region.end]; RegionChange(first_region, second_region)){
			tmp_max_energy = CalculateTmpMax(first_region, second_region);
			max_energy = max(max_energy, tmp_max_energy);
		}
		max_energy_found[now_region.begin][now_region.end] = max_energy;
	}
	return(max_energy_found[now_region.begin][now_region.end]);
}

void RegionInit(Region now_region, Region &first_region, Region &second_region){
	first_region.end = first_region.begin = now_region.begin;
	second_region.begin = change_to_next[first_region.end];
	second_region.end = now_region.end;
}

void RegionChange(Region &first_region, Region &second_region){
	first_region.end = change_to_next[first_region.end];
	second_region.begin = change_to_next[second_region.begin];
}

int CalculateTmpMax(Region first_region, Region second_region){
	int tmp_max_energy = 0;
	tmp_max_energy = energy_necklace[first_region.begin] * energy_necklace[second_region.begin] * energy_necklace[second_region.end + 1];
	tmp_max_energy += FindMaxEnergyWithRegion(first_region);
	tmp_max_energy += FindMaxEnergyWithRegion(second_region);
	return(tmp_max_energy);
}

void Output(int max_energy){
	cout << max_energy;
}