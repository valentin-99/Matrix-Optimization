#!/bin/bash

make clean
make all
echo "---------------------------------------"
echo "-------------------BLAS----------------"
echo "---------------------------------------"
./tema2_blas input
# ./tema2_blas /export/asc/tema2/input
./compare out2 /export/asc/tema2/out1 0.00001
./compare out4 /export/asc/tema2/out2 0.00001
./compare out6 /export/asc/tema2/out3 0.00001
./tema2_blas /export/asc/tema2/input_valgrind
valgrind --tool=memcheck --leak-check=full --log-file="blas.memory" ./tema2_blas /export/asc/tema2/input_valgrind
valgrind --tool=cachegrind --branch-sim=yes --log-file="blas.cache" ./tema2_blas /export/asc/tema2/input_valgrind
echo "---------------------------------------"
echo "-----------------NEOPT-----------------"
echo "---------------------------------------"
./tema2_neopt input
# ./tema2_neopt /export/asc/tema2/input
./compare out2 /export/asc/tema2/out1 0.00001
./compare out4 /export/asc/tema2/out2 0.00001
./compare out6 /export/asc/tema2/out3 0.00001
./tema2_neopt /export/asc/tema2/input_valgrind
valgrind --tool=memcheck --leak-check=full --log-file="neopt.memory" ./tema2_neopt /export/asc/tema2/input_valgrind
valgrind --tool=cachegrind --branch-sim=yes --log-file="neopt.cache" ./tema2_neopt /export/asc/tema2/input_valgrind
echo "---------------------------------------"
echo "-------------------OPT-----------------"
echo "---------------------------------------"
./tema2_opt_m input
# ./tema2_opt_m /export/asc/tema2/input
./compare out2 /export/asc/tema2/out1 0.00001
./compare out4 /export/asc/tema2/out2 0.00001
./compare out6 /export/asc/tema2/out3 0.00001
./tema2_opt_m /export/asc/tema2/input_valgrind
valgrind --tool=memcheck --leak-check=full --log-file="opt_m.memory" ./tema2_opt_m /export/asc/tema2/input_valgrind
valgrind --tool=cachegrind --branch-sim=yes --log-file="opt_m.cache" ./tema2_opt_m /export/asc/tema2/input_valgrind
echo "---------------------------------------"
