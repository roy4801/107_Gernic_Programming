reset
set ylabel 'time(sec)'
set xlabel 'len,line'
set style fill solid
set title 'Alternative time'
set term png enhanced font 'Verdana,15'
set output 'runtime.png'

plot [:][:60]'gnu.txt' using 2:xtic(1) with histogram title 'input', \
'' using 3:xtic(1) with histogram title 'Character Table Creation'  , \
'' using 4:xtic(1) with histogram title 'Sorting time'  , \
'' using 5:xtic(1) with histogram title 'Output'  , \
# '' using ($0):($1+100000):($2+100000) with labels title '', \
'' using ($0-0.200):(0.333):2 with labels title ' ' textcolor lt 1, \
'' using ($0-0.200):(0.333):3 with labels title ' ' textcolor lt 2, \
'' using ($0-0.200):(0.333):4 with labels title ' ' textcolor lt 3, \
'' using ($0-0.200):(0.333):5 with labels title ' ' textcolor lt 4, \