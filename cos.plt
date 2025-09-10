
set multiplot layout 3,1 columnsfirst

set xlabel "log10|h|"
set ylabel "log10|RelErr|"

set label 1 "Error of numerical derivative of cos(x=0.1)" at graph 0.02,0.13
plot "cos01.dat" using 1:2 with lines title "Forward Err", "cos01.dat" using 1:3 with lines title "Central Err", "cos01.dat" using 1:4 with lines title "Extrapolated Err"

set label 1 "Error of numerical derivative of cos(x=1.0)" at graph 0.02,0.13
plot "cos1.dat" using 1:2 with lines title "Forward Err", "cos1.dat" using 1:3 with lines title "Central Err", "cos1.dat" using 1:4 with lines title "Extrapolated Err"

set label 1 "Error of numerical derivative of cos(x=100)" at graph 0.02,0.13
plot "cos100.dat" using 1:2 with lines title "Forward Err", "cos100.dat" using 1:3 with lines title "Central Err", "cos100.dat" using 1:4 with lines title "Extrapolated Err"

unset multiplot
