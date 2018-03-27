#!/bin/sh

root -b -l <<EOF
.L Event.cxx+
.L Phase1.cxx+
Phase1(1)
.q
EOF
