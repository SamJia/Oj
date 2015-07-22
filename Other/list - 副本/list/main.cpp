/*
 * test.cpp
 *
 *  Created on: Aug 15, 2013
 *      Author: ywu
 */

#include <cstdio>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <list>
#include "list.h"

using namespace test;


bool check(list<int> myList, std::list<int>  stdList) {
    if (myList.size() != stdList.size()) {
        printf("Failed: different size %d %d", (int)myList.size(), (int)stdList.size());
        return false;
    }
    list<int>::iterator it1 = myList.begin();
    std::list<int>::iterator it2 = stdList.begin();
    int pos = 0;
    for (;it1 != myList.end() && it2 != stdList.end(); ++it1, ++it2, ++pos) {
        if (*it1 != *it2) {
            printf("Failed: different value at %d: %d %d\n", pos, *it1, *it2);
            return false;
        }
        printf("%d ", *it1);
    }
    printf("\n");
    
    if (it1 != myList.end() || it2 != stdList.end()) {
        printf("Failed: wrong end() position");
        return false;
    }
    printf("OK!\n");
    return true;
}


bool cmp(const int& a, const int& b) {
    return a > b;
}

int main() {
    // this is only a example test, if you pass it, your program are likely to be correct
    list<int> myList;
    std::list<int>  stdList;
    srand(time(0));
    for (int i = 0; i < 100; ++i) {
        int data = rand();
        if (rand() % 2 == 0) {
            myList.push_front(data);
            stdList.push_front(data);
        } else {
            myList.push_back(data);
            stdList.push_back(data);
        }
    }
    check(myList, stdList);
    printf("section1 done\n");
    myList.sort();
    stdList.sort();
    check(myList, stdList);
    printf("section2 done\n");
    for (int i = 0; i < 50; ++i) {
        int data = rand();
        if (rand() % 2 == 0) {
            myList.pop_front();
            stdList.pop_front();
        } else {
            myList.pop_back();
            stdList.pop_back();
        }
    }
    check(myList, stdList);
    printf("section3 done\n");
    myList.sort(cmp);
    stdList.sort(cmp);
    check(myList, stdList);
    printf("section4 done\n");
}
