# Memory access profiling

mkdir build
cd build
cmake ..
make


g++ -std=c++17 -g main.cpp -o main
valgrind --tool=cachegrind ./main



==8489== Cachegrind, a cache and branch-prediction profiler
==8489== Copyright (C) 2002-2017, and GNU GPL'd, by Nicholas Nethercote et al.
==8489== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==8489== Command: ./main
==8489== 
Сумма по строкам. длительность: 338

 Общая сумма всех элементов по строкам: 50498583
Сумма по столбцам. длительность: 343

 Общая сумма всех элементов по столбцам: 50498583
==8489== 
==8489== I refs:        322,184,546

