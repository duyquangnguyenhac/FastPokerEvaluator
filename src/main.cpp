#include <benchmark/benchmark.h>

#include "cactus_kev.cpp"
#include "poker_engine.cpp"
#include "quang.cpp"
#include "senzee.cpp"

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

// Define another benchmark
static void BM_Quang(benchmark::State& state) {
    PokerEngine* quang = new Quang();
    int* hand = quang->random_five();
    for (auto _ : state) {
        quang->evaluate(hand);
    }

    state.PauseTiming();
    state.SetIterationTime(0);
    state.ResumeTiming();
    for (auto _ : state) {
        quang->evaluate(hand);
    }
}

BENCHMARK(BM_Cactus);
BENCHMARK(BM_Senzee);
BENCHMARK(BM_Quang);

int main(int argc, char** argv) {
    std::cout << "Poker Engines started"
              << "\n";
    benchmark::Initialize(&argc, argv);

    // Run the benchmark
    benchmark::RunSpecifiedBenchmarks();

    std::cout << "\n";
    std::cout << "Run simulation games..."
              << "\n";

    PokerEngine* cactus = new CactusKev();
    PokerEngine* senzee = new Senzee();
    PokerEngine* quang = new Quang();
    std::cout << "Senzee: ";
    senzee->simulate_games(1000000, 5);

    std::cout << "Cactus: ";
    cactus->simulate_games(1000000, 5);

    std::cout << "Quang: ";
    quang->simulate_games(1000000, 5);
    return 0;
}