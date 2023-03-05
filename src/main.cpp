#include "cactus_kev.cpp"
#include "poker_engine.cpp"
#include "senzee.cpp"

int main() {
    std::cout << "Poker Engines started"
              << "\n";
    PokerEngine* cactus = new CactusKev();
    PokerEngine* senzee = new Senzee();
    cactus->simulate_games(1000000, 5);
    senzee->simulate_games(1000000, 5);
    return 0;
}