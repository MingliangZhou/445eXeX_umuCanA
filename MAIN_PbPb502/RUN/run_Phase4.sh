#!/bin/sh

for ((I1=0;I1<2;I1+=1))
do
root -b -l <<EOF
.L ../Phase4.cxx++g
Phase4($I1)
.q
EOF
done

rm -rf ../*.d
rm -rf ../*.so
