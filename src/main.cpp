#include "poker_engine.cpp"
int main() {
    PokerEngine engine = PokerEngine();
    // engine.simulate_games(1000000, 10);
    engine.benchmark_eval();
    return 0;
}