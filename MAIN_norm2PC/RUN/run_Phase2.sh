#!/bin/sh

for ((I1=0;I1<2;I1+=1)) # 2
do
for ((I2=0;I2<=10;I2+=1)) # 10
do
root -b -l <<EOF
.L ../CumuRbn.cxx+
.L ../Phase2Rbn.cxx+
Phase2Rbn($I1,$I2)
.q
EOF
done
done

rm -rf ../*.d
rm -rf ../*.so
