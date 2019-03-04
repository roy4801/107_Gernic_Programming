reset
set ylabel 'time(sec)'
set xlabel 'len,line'
set title 'Alternative time'
set term png enhanced font 'Verdana,15'
set output 'len.png'

plot [:][:60]'data_len.txt' using 2:xtic(1) with linespoints title 'input', \
'' using 3:xtic(1) with linespoints title 'Character Table Creation'  , \
'' using 4:xtic(1) with linespoints title 'Sorting time'  , \
'' using 5:xtic(1) with linespoints title 'Output'  , \
# '' using ($0):($1+100000):($2+100000) with labels title '', \
'' using ($0-0.200):(0.333):2 with labels title ' ' textcolor lt 1, \
'' using ($0-0.200):(0.333):3 with labels title ' ' textcolor lt 2, \
'' using ($0-0.200):(0.333):4 with labels title ' ' textcolor lt 3, \
'' using ($0-0.200):(0.333):5 with labels title ' ' textcolor lt 4, \