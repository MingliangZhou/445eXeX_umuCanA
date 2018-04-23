#!/bin/sh

for ((I1=0;I1<2;I1+=1))
do
root -b -l <<EOF
.L ../Phase5.cxx+
Phase5($I1)
.q
EOF
done

rm -rf ../*.d
rm -rf ../*.so

cp -r ../OUTPUT/Phase5/hist_*.root ../OUTPUT/Phase4/.
