#include "../include/mergesort.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <execution>
int main(){
	 using namespace std::chrono;
	 std::ofstream f1("mergesort.csv");
	std::ofstream f2("stdsort.csv");	
	std::ofstream f3("stdlibqsort.csv");
	 std::srand(time(nullptr));

for(int i = 1; i <= 8; ++i){
    long size = static_cast<long>(std::pow(10, i));

    int* vec = new int[size];
    int* vec2 = new int[size];
    int* arr = new int[size];

    for(long j = 0; j < size; ++j){
        int val = std::rand() % size;
        arr[j] = vec2[j] = vec[j] = val;
    }

    auto start = high_resolution_clock::now();
    std::sort(std::execution::par_unseq, vec2, vec2 + size);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    f2 << size << "," << duration.count() << std::endl;
    std::cout << "std::sort->Size: " << size << ", Time: " << duration.count() << " ms" << std::endl;

    start = high_resolution_clock::now();
    merge_sort(vec, vec + size, std::less<int>(), true);
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    f1 << size << "," << duration.count() << std::endl;
    std::cout << "mergesort->Size: " << size << ", Time: " << duration.count() << " ms" << std::endl;

    start = high_resolution_clock::now();
    std::qsort(arr, size, sizeof(int), [](const void* a, const void* b) {
        int int_a = *static_cast<const int*>(a);
        int int_b = *static_cast<const int*>(b);
        return (int_a > int_b) - (int_a < int_b);
    });
    end = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(end - start);
    f3 << size << "," << duration.count() << std::endl;
    std::cout << "stdlib_qsort->Size: " << size << ", Time: " << duration.count() << " ms" << std::endl;

    delete[] arr;
    delete[] vec;
    delete[] vec2;
}

	



		

return 0;
}
