/*
 * Parallel Mergesort
 * Copyright (C) 2025 Your H A Vishnu Datha
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */


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
