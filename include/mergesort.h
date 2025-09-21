#ifndef MERGESORT_H
#define MERGESORT_H

#include <thread>
#include <vector>
#include <functional>
#include <iterator>
#include <atomic>
std::atomic<size_t> active_threads{0};

template <typename Iterator, typename Compare = std::less<typename std::iterator_traits<Iterator>::value_type>>
void merge_(Iterator left, Iterator mid, Iterator right, Compare&& comp = Compare()) {
    using T = typename std::iterator_traits<Iterator>::value_type;

    std::vector<T> temp1(std::make_move_iterator(left), std::make_move_iterator(mid));
    std::vector<T> temp2(std::make_move_iterator(mid), std::make_move_iterator(right));

    auto i = temp1.begin(), j = temp2.begin();
    auto k = left;

    while (i != temp1.end() && j != temp2.end()) {
        if (comp(*i, *j)) {
            *k = std::move(*i);
            ++i;
        } else {
            *k = std::move(*j);
            ++j;
        }
        ++k;
    }

    while (i != temp1.end()) {
        *k = std::move(*i);
        ++i;
        ++k;
    }

    while (j != temp2.end()) {
        *k = std::move(*j);
        ++j;
        ++k;
    }
}


template <typename Iterator, typename Compare = std::less< typename std::iterator_traits<Iterator>::value_type>>
	void merge_sort_ (Iterator left,
		 	 Iterator right, 
			Compare comp = Compare()){
	auto len = std::distance( left, right );
    	if ( len <= 1 ) return;
	auto mid = left + len / 2;
	merge_sort_(left, mid, comp);
	merge_sort_(mid, right, comp);
	merge_(left,mid, right, comp);
}

template <typename Iterator, typename Compare = std::less< typename std::iterator_traits<Iterator>::value_type>>
	 void merge_sort_par_ (	Iterator left,
                      	Iterator right,
                	Compare comp=Compare(),size_t max_thread_= std::thread::hardware_concurrency(),size_t depth=0){
        auto len = std::distance(left, right);
    	if (len <= 1) return;
         auto mid = left + len/2;

	if(active_threads < max_thread_ ){ //depth in case if you want to limit threads
		active_threads+=2;
	std::thread t1([left, mid, comp, max_thread_, depth]() {
           merge_sort_par_<Iterator, Compare>(left, mid, comp, max_thread_, depth + 1);
           active_threads--;
       	});
        
        std::thread t2([mid, right, comp, max_thread_, depth]() {
            merge_sort_par_<Iterator, Compare>(mid, right, comp, max_thread_, depth + 1);
            active_threads--;
        });
		t1.join();
		t2.join();
	}else{
		merge_sort_par_(left, mid, comp, depth+1);
        merge_sort_par_(mid, right, comp, depth+1);
	}
        merge_(left, mid, right, comp);
}

template <typename Iterator, typename Compare = std::less< typename std::iterator_traits<Iterator>::value_type>>
void merge_sort( Iterator left,
                 Iterator right,
                Compare comp = Compare(), bool par = false, size_t max_thread_= std::thread::hardware_concurrency()){
	if(!par){ 
		merge_sort_(left, right, comp);
	}	
	else{     
		merge_sort_par_(left, right, comp, max_thread_);
	}
}


#endif //MERGESORT_H
