# FastPokerEvaluator
A short project to provide implementations of Cactus Kev and Paul Senzee Poker Hand Evaluator.

## Overview

A recent output of the benchmark obtained by running the PokerEvaluator executable.

```bash
Poker Engines started
2023-03-26T15:32:58-04:00
Running ./PokerEvaluator
Run on (8 X 2400 MHz CPU s)
CPU Caches:
  L1 Data 64 KiB
  L1 Instruction 128 KiB
  L2 Unified 4096 KiB (x8)
Load Average: 2.01, 2.38, 2.60
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Cactus         164 ns          164 ns      4148320
BM_Senzee        42.2 ns         42.1 ns     16561854

Run simulation games...
Ran 1000000 games for 5 players in 755.22ms
Ran 1000000 games for 5 players in 532.532ms
```

## How to build and run this project
Clone this project to your local machine

If you don't already have google benchmark, find some instructions here ...

Navigate to the /build 

Run 
```console 
    quangnguyen@JJames build % cmake ..
```
to build the project. 

Then, in the same folder, run the PokerEvaluator executable.


