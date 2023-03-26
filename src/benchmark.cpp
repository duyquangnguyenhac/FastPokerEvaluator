#include <benchmark/benchmark.h>

#include "cactus_kev.cpp"
#include "poker_engine.cpp"
#include "senzee.cpp"

static void BM_Senzee(benchmark::State& state) {
    PokerEngine* senzee = new Senzee();
    for (auto _ : state) {
        senzee->evaluate(senzee->random_five());
    }
}
// Register the function as a benchmark

// Define another benchmark
static void BM_Cactus(benchmark::State& state) {
    PokerEngine* cactus = new CactusKev();
    for (auto _ : state) {
        cactus->evaluate(cactus->random_five());
    }
}
BENCHMARK(BM_Cactus);
BENCHMARK(BM_Senzee);

BENCHMARK_MAIN();