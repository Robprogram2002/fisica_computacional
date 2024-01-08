reset 

set terminal gif size 800,400 animate delay 10
set output "mov2_potencial.gif"

do for [i=1:199] {
    set multiplot layout 1,2

    set size 0.5,1
    set origin 0,0

    set xrange [-4:4]
    set yrange [-4:4]
    set title "Dinámica molecular t=".i
    set xlabel "x [amstrong]"
    set ylabel "y [amstrong]"

    unset key

    plot "paso2.txt" u 1:2 every ::i::i w p, "paso2.txt" u 5:6 every ::i::i w p, "paso2.txt" u 9:10 every ::i::i w p, "paso2.txt" u 13:14 every ::i::i w p, "paso2.txt" u 17:18 every ::i::i w p, "paso2.txt" u 21:22 every ::i::i w p, "paso2.txt" u 25:26 every ::i::i w p, "paso2.txt" u 29:30 every ::i::i w p, "paso2.txt" u 33:34 every ::i::i w p, "paso2.txt" u 37:38 every ::i::i w p

    set size 0.5,0.5
    set origin 0.5,0.5

    set xrange [0:200]
    set yrange [-100:1]
    set title "Energía Potencial vs tiempo"
    set xlabel "t [s]"
    set ylabel "Ep [J]"

    plot "paso2.txt" u 199:200 every ::1::i w l

    set size 0.5,0.5
    set origin 0.5,0

    set xrange [0:200]
    set yrange [-1:50]
    set title "Temperatura vs tiempo"
    set xlabel "t [s]"
    set ylabel "T [Celsius]"

    plot "paso2.txt" u 199:197 every ::1::i w l

    unset multiplot
}
unset output
set term qt