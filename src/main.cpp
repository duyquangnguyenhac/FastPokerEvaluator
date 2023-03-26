#include <benchmark/benchmark.h>

#include "cactus_kev.cpp"
#include "poker_engine.cpp"
#include "senzee.cpp"

using namespace benchmark;

static void BM_Senzee(benchmark::State& state) {
    PokerEngine* senzee = new Senzee();
    int* hand = senzee->random_five();

    for (auto _ : state) {
        senzee->evaluate(hand);
    }

    state.PauseTiming();
    state.SetIterationTime(0);
    state.ResumeTiming();

    for (auto _ : state) {
        senzee->evaluate(hand);
    }
}
// Register the function as a benchmark

// Define another benchmark
static void BM_Cactus(benchmark::State& state) {
    PokerEngine* cactus = new CactusKev();
    int* hand = cactus->random_five();
    for (auto _ : state) {
        cactus->evaluate(hand);
    }

    state.PauseTiming();
    state.SetIterationTime(0);
    state.ResumeTiming();
    for (auto _ : state) {
        cactus->evaluate(hand);
    }
}
BENCHMARK(BM_Cactus);
BENCHMARK(BM_Senzee);

int main(int argc, char** argv) {
    std::cout << "Poker Engines started"
              << "\n";
    Initialize(&argc, argv);

    // Run the benchmark
    RunSpecifiedBenchmarks();

    PokerEngine* cactus = new CactusKev();
    PokerEngine* senzee = new Senzee();

    cactus->simulate_games(1000000, 5);
    senzee->simulate_games(1000000, 5);
    return 0;
}