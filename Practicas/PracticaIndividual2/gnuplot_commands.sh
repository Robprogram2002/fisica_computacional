plot "duffing_1_transient.txt" using 2:3 with lines lw 0.8 linecolor rgb "black" ,"duffing_1_persistent.txt" using 2:3 with lines lw 0.8 linecolor rgb
"red"

plot "duffing_1_complete.txt" using 2:3 with lines lw 0.6

plot "duffing_1_poincare.txt" using 2:3 pointsize 2 pointtype 3

plot "duffing_1_complete.txt" using 2:3 with lines lw 0.6, "initial_conditions.txt" u 1:2 ps 2 pt 7 lc rgb "red"



plot "duffing_3_complete.txt" using 2:3 with lines lw 0.6, "initial_conditions.txt" u 1:2 ps 2 pt 3 lc rgb "red"

plot "duffing_3_poincare.txt" u 2:3  lt 1 lw 0.6


set xrange[0.30:0.40]

plot "bifurca.txt" u 1:2 lt 1 lw 0.5

