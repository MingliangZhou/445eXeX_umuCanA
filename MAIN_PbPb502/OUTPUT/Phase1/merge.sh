rm -rf Phase1_Sample0.root
hadd Phase1_Sample0.root Phase1_Sample0_*
rm -rf Phase1_Sample1.root
hadd Phase1_Sample1.root Phase1_Sample1_*
rm -rf Phase1_Sample2.root
hadd Phase1_Sample2.root Phase1_Sample2_*
rm -rf Phase1_Sample3.root
hadd Phase1_Sample3.root Phase1_Sample3_*
rm -rf Phase1_Sample4.root
hadd Phase1_Sample4.root Phase1_Sample4_*
rm -rf Phase1_Sample5.root
hadd Phase1_Sample5.root Phase1_Sample5_*
rm -rf Phase1_Sample6.root
hadd Phase1_Sample6.root Phase1_Sample6_*
rm -rf Phase1_Sample7.root
hadd Phase1_Sample7.root Phase1_Sample7_*
rm -rf Phase1_Sample8.root
hadd Phase1_Sample8.root Phase1_Sample8_*
rm -rf Phase1_Sample9.root
hadd Phase1_Sample9.root Phase1_Sample9_*

rm -rf Phase1_Sample*File*.root

rm -rf Phase1_All.root
hadd Phase1_All.root Phase1_Sample*
