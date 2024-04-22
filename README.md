# Memory access profiling

# Сборка

mkdir build
cd build
cmake ..
make

или
 
g++ -std=c++17 -g main.cpp -o main

# Запуск профилятора valgrind

valgrind --tool=cachegrind ./main


# Вывод valgrind:

==9430== Cachegrind, a cache and branch-prediction profiler
==9430== Copyright (C) 2002-2017, and GNU GPL'd, by Nicholas Nethercote et al.
==9430== Using Valgrind-3.21.0 and LibVEX; rerun with -h for copyright info
==9430== Command: ./main
==9430== 
Сумма по строкам длительность: 99

 Общая сумма всех элементов по строкам: 50498583
Сумма по столбцам длительность: 104

 Общая сумма всех элементов по столбцам: 50498583
==9430== 
==9430== I refs:        188,513,008

