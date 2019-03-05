reset
set ylabel 'time(sec)'
set xlabel 'len,line'
set style fill solid
set title 'Simple time'
set term png enhanced font 'Verdana,15'
set output 'len.png'

set style line 1 \
    linecolor rgb '#f44242' \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.0

set style line 2 \
    linecolor rgb '#41f459' \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.0

set style line 3 \
    linecolor rgb '#414ff4' \
    linetype 1 linewidth 2 \
    pointtype 7 pointsize 1.0

plot [:][:30]'data_len.txt' using 2:xtic(1) with linespoints title 'input' linestyle 1, \
'' using 3:xtic(1) with linespoints title 'Sorting time'  linestyle 2, \
'' using 4:xtic(1) with linespoints title 'output'  linestyle 3, \
# '' using ($0):($1+100000):($2+100000) with labels title '', \
'' using ($0-0.200):(0.333):2 with labels title ' ' textcolor lt 1, \
'' using ($0-0.200):(0.333):3 with labels title ' ' textcolor lt 2, \
'' using ($0-0.200):(0.333):4 with labels title ' ' textcolor lt 3, \

