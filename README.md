# Memory access profiling

mkdir build
cd build
cmake ..
make


g++ -std=c++17 -g main.cpp -o main
valgrind --tool=cachegrind ./main



==7014== Cachegrind, a cache and branch-prediction profiler
==7014== Copyright (C) 2002-2017, and GNU GPL'd, by Nicholas Nethercote et al.
==7014== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==7014== Command: ./main
==7014== 
Сумма по строкам time: 334
Сумма по столбцам time: 334

 Общая сумма всех элементов по строкам: 50498583

 Общая сумма всех элементов по столбцам: 50498583
==7014== 
==7014== I refs:        316,179,887
