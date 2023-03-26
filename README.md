# FastPokerEvaluator
Two implementations of Cactus Kev and Paul Senzee Poker Hand Evaluator

## Overview
Use CMake and Make to build and run the project.

A recent output of the benchmark obtained by running the PokerEvaluator executable.
Main functionalities are used in the main.cpp file. 

```bash
Poker Engines started
2023-03-26T15:29:30-04:00
Running ./PokerEvaluator
Run on (8 X 2400 MHz CPU s)
CPU Caches:
  L1 Data 64 KiB
  L1 Instruction 128 KiB
  L2 Unified 4096 KiB (x8)
Load Average: 1.94, 2.54, 2.71
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Cactus         154 ns          153 ns      4400440
BM_Senzee        43.0 ns         43.0 ns     16479080
Ran 1000000 games for 5 players in 750.655ms
Ran 1000000 games for 5 players in 533.775ms
```