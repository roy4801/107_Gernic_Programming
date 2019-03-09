reset
set ylabel 'time(sec)'
set xlabel '(len, line)'
set title 'input Comparison line fixed'
set term png enhanced font 'Verdana,15' size 1280,720
set output 'input_line.png'

# Key adjustment
set key reverse Left width 1
set key top left

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

# rotate x label
set xtics rotate by 45 offset 0.0,0.0 right font 'Verdana,13' enhanced
set bmargin 8
# Lighter grid lines
set grid ytics lc rgb "#C0C0C0"

plot [:][:30] \
'./Alternative/data_line.txt' using 2:xtic(1) with linespoints title 'Alternative' linestyle 1, \
'./Iterator/data_line.txt' using 2:xtic(1) with linespoints title 'Iterator' linestyle 2,\
'./Simple/data_line.txt' using 2:xtic(1) with linespoints title 'Simple' linestyle 3,\

