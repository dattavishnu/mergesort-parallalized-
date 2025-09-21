#include "../include/mergesort.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
int main(){
	
	vector<int> vec1={5,3,1,4},vec2={1,3,4,5};
	int arr1[10]={9,8,7,6,5,4,3,2,1,0},arr2[10]={0,1,2,3,4,5,6,7,8,9};
	merge_sort(vec1.begin(),vec1.end());
	merge_sort(arr1,arr1+10);
	assert(vec1==vec2);
	for(int i=0;i<10;++i){
		assert(arr1[i]==arr2[i]);
	}
	
	

return 0;
}
