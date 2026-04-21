set datafile separator ","
set terminal pngcairo
set xlabel "Tamanho da entrada (n)"
set ylabel "Tempo (microssegundos)"

# bubble sort com O(n²)
set output "grafico_bubble_sort.png"
set title "Bubble Sort — O(n²)"
plot "tempos.csv" using 1:2 with linespoints title "Bubble Sort", \
     "tempos.csv" using 1:($1*$1*0.002) with lines title "O(n²) teorico"

# merge sort com O(n log n)
set output "grafico_merge_sort.png"
set title "Merge Sort — O(n log n)"
plot "tempos.csv" using 1:3 with linespoints title "Merge Sort", \
     "tempos.csv" using 1:($1*log($1)*0.009) with lines title "O(n log n) teorico"

# linear search com O(n)
set output "grafico_linear_search.png"
set title "Linear Search — O(n)"
plot "tempos.csv" using 1:4 with linespoints title "Linear Search", \
     "tempos.csv" using 1:($1*0.0006) with lines title "O(n) teorico"

# binary search com O(log n)
set output "grafico_binary_search.png"
set title "Binary Search — O(log n)"
plot "tempos.csv" using 1:5 with linespoints title "Binary Search", \
     "tempos.csv" using 1:(log($1)*0.1) with lines title "O(log n) teorico"