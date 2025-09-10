# a simple gnuplot macro

set xlabel "x"
set ylabel "bessel_n(x)"

set multiplot layout 2,1 columnsfirst

set label 1 "down calc" at graph 0.5,0.9
plot "bessel0.dat" using 1:2 pt 19 title "(n=0)", "bessel3.dat" using 1:2 pt 19 title "(n=3)", "bessel5.dat" using 1:2 pt 19 title "(n=5)", "bessel8.dat" using 1:2 pt 19 title "(n=8)"

set label 1 "up calc" at graph 0.5,0.9
plot "bessel0.dat" using 1:3 pt 15 title "(n=0)", "bessel3.dat" using 1:3 pt 15 title "(n=3)", "bessel5.dat" using 1:3 pt 15 title "(n=5)", "bessel8.dat" using 1:3 pt 15 title "(n=8)"

unset multiplot
