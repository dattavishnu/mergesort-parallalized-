set datafile separator ","
set key autotitle columnheader
set xlabel "size"
set ylabel "time(ms)"
set grid

plot "mergesort.csv" using 1:2 with linespoints title 'mergesort(parallel)', \
     "stdlibqsort.csv" using 1:2 with linespoints title 'std::qsort', \
     "stdsort.csv" using 1:2 with linespoints title 'std::sort(parallel)'
