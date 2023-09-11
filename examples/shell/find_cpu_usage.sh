top -bn3 | \
      grep "Cpu(s)" | \
      sed "s/.*, *\([0-9.]*\)%* id.*/\1/" | \
      awk '{print 100 - $1}' | \
      awk '{ for(i=1;i<=NF;i++) total[i]+=$i ; } \
      END { for(i=1;i<=NF;i++) printf "%.2f%%",total[i]/NR ;}'
