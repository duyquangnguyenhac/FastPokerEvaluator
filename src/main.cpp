#include "poker_engine.cpp"
int main() {
    PokerEngine engine = PokerEngine();
    engine.simulate_games(1000000, 10);
    return 0;
}