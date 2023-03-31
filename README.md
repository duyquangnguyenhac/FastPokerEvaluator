# FastPokerEvaluator
A short project to provide implementations of Cactus Kev and Paul Senzee Poker Hand Evaluator.

## Overview

A recent output of the benchmark obtained by running the PokerEvaluator executable.

```bash
Poker Engines started
2023-03-31T14:17:01-04:00
Running ./PokerEvaluator
Run on (8 X 2400 MHz CPU s)
CPU Caches:
  L1 Data 64 KiB
  L1 Instruction 128 KiB
  L2 Unified 4096 KiB (x8)
Load Average: 2.52, 4.38, 4.55
-----------------------------------------------------
Benchmark           Time             CPU   Iterations
-----------------------------------------------------
BM_Cactus         152 ns          152 ns      4249945
BM_Senzee        42.2 ns         42.2 ns     16719173
BM_Quang          330 ns          330 ns      2121952

Run simulation games...
Senzee: Ran 1000000 games for 5 players in 531.664ms
Cactus: Ran 1000000 games for 5 players in 752.377ms
Quang: Ran 1000000 games for 5 players in 870.794ms
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


