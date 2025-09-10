
set multiplot layout 3,1 columnsfirst

set xlabel "log10|h|"
set ylabel "log10|RelErr|"

# exp data plotting

set label 1 "Error of numerical derivative of exp(x=0.1)" at graph 0.02,0.13
plot "exp01.dat" using 1:2 with lines title "Forward Err", "exp01.dat" using 1:3 with lines title "Central Err", "exp01.dat" using 1:4 with lines title "Extrapolated Err"

set label 1 "Error of numerical derivative of exp(x=1.0)" at graph 0.02,0.13
plot "exp1.dat" using 1:2 with lines title "Forward Err", "exp1.dat" using 1:3 with lines title "Central Err", "exp1.dat" using 1:4 with lines title "Extrapolated Err"

set label 1 "Error of numerical derivative of exp(x=100)" at graph 0.02,0.13
plot "exp100.dat" using 1:2 with lines title "Forward Err", "exp100.dat" using 1:3 with lines title "Central Err", "exp100.dat" using 1:4 with lines title "Extrapolated Err"

unset multiplot



