reset
set ylabel 'time(sec)'
set xlabel 'len,line'
set style fill solid
set title 'Simple time'
set term png enhanced font 'Verdana,15'
set output 'line.png'

plot [:][:30]'data_line.txt' using 2:xtic(1) with linespoints title 'input', \
'' using 3:xtic(1) with linespoints title 'Sorting time'  , \
'' using 4:xtic(1) with linespoints title 'output'  , \
# '' using ($0):($1+100000):($2+100000) with labels title '', \
'' using ($0-0.200):(0.333):2 with labels title ' ' textcolor lt 1, \
'' using ($0-0.200):(0.333):3 with labels title ' ' textcolor lt 2, \
'' using ($0-0.200):(0.333):4 with labels title ' ' textcolor lt 3, \

