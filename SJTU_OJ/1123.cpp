#include <algorithm>
#include <cstdio>
using namespace std;
#define SIZE 50100
#define UP first
#define DOWN second
#define X first
#define Y second
#define UPPERLIMIT 100007

struct Unit{
	Unit(int low = 0, int high = 0) : low_(low), high_(high), left_(NULL), right_(NULL){}
	int low_, high_;
	pair<int, int> data_[11];
	Unit *left_, *right_;
};

pair<int, int> points[SIZE], tmp[11];
int points_number, section_number, result = 0, up = 0, down = 1;
Unit *head;

void InputAndInit();
void FindRootNumber();
inline bool cmp(const pair<int, int> &num1, const pair<int, int> &num2);
void CreateTree(Unit *p);
void FindRootNumber();
void TmpInit();
void FindData(Unit *p, int coord_y);
void AddToTmp(pair<int, int> data[], int state);
void UpdateData(Unit *p, int coord_y);

void Output();

main(){
	InputAndInit();
	FindRootNumber();
	Output();
}

void InputAndInit(){
	scanf("%d%d", &points_number, &section_number);
	for(int i = 0; i < points_number; ++i)
		scanf("%d%d", &points[i].X, &points[i].Y);
	sort(points, points + points_number, cmp);
	for(int i = 0; i < points_number; ++i)
		points[i].Y = i;
	sort(points, points + points_number);
	head = new Unit(0, points_number - 1);
	CreateTree(head);
	TmpInit();
}

inline bool cmp(const pair<int, int> &num1, const pair<int, int> &num2){
	return num1.Y < num2.Y;
}

void CreateTree(Unit *p){
	if(p->low_ < p->high_){
		p->left_ = new Unit(p->low_, (p->low_ + p->high_) / 2);		
		CreateTree(p->left_);
		p->right_ = new Unit((p->low_ + p->high_) / 2 + 1, p->high_);
		CreateTree(p->right_);
	}
}

void FindRootNumber(){
	for(int i = points_number - 1; i >= 0; --i, TmpInit()){
		FindData(head, points[i].Y);
		UpdateData(head, points[i].Y);
		result = (result + tmp[section_number].UP + tmp[section_number].DOWN) % UPPERLIMIT;
		// printf("%d\n", result);
	}
}

void TmpInit(){
	tmp[0].UP = tmp[0].DOWN = 1;
	for(int i = 1; i <= section_number; ++i)
		tmp[i].X = tmp[i].Y = 0;
}

void FindData(Unit *p, int coord_y){
	if(coord_y < (p->low_ + p->high_) / 2){
		AddToTmp(p->right_->data_, up);
		FindData(p->left_, coord_y);
	}
	else if(coord_y > (p->low_ + p->high_) / 2 + 1){
		AddToTmp(p->left_->data_, down);
		FindData(p->right_, coord_y);
	}
	else{
		AddToTmp(p->left_->data_, down);
		AddToTmp(p->right_->data_, up);
	}
}

void AddToTmp(pair<int, int> data[], int state){
	if(state == up)
		for(int i = 1; i <= section_number; ++i)
			tmp[i].UP = (tmp[i].UP + data[i].UP + data[i - 1].DOWN) % UPPERLIMIT;
	else
		for(int i = 1; i <= section_number; ++i)
			tmp[i].DOWN = (tmp[i].DOWN + data[i].DOWN + data[i - 1].UP) % UPPERLIMIT;
}

void UpdateData(Unit *p, int coord_y){
	if(!p)
		return;
	for(int i = 0; i <= section_number; ++i){
		p->data_[i].UP = (p->data_[i].UP + tmp[i].UP) % UPPERLIMIT;
		p->data_[i].DOWN = (p->data_[i].DOWN + tmp[i].DOWN) % UPPERLIMIT;
	}
	if(coord_y <= (p->low_ + p->high_) / 2)
		UpdateData(p->left_, coord_y);
	else
		UpdateData(p->right_, coord_y);
}

void Output(){
	printf("%d\n", result);
}