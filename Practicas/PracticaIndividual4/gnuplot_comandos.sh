set view map
unset surface
set contour base

set cntrparam levels auto 16
set isosam 31,31
set table 'equipotential_lines.txt'
splot "datos_1.txt" w l ls 1
unset table

set title font "Times New Roman, 22"
set xlabel "Posición X"
set ylabel "Posición y"
set title "Potencial y lineas equipotenciales, Placas paralelas"

set xrange[0:1]
set yrange[0:1]
plot 'equipotential_lines.txt' u 1:2 w l lw 2

set pm3d
set view map
splot "datos_1.txt"