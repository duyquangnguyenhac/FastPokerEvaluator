#ifndef POKER_ENGINE_H_
#define POKER_ENGINE_H_

class PokerEngine {
   private:
    int* deck;
    int num_players;
    int num_cards = 52;
    const static int CLUBS = 0x8000;
    const static int DIAMONDS = 0x4000;
    const static int HEARTS = 0x2000;
    const static int SPADES = 0x1000;

   public:
    PokerEngine();
    int* generate_deck();
    void print_card(int* card);
    void print_deck();
    void print_hand(int* hand, int num_cards);
    void shuffle();
    short evaluate(int* hand);
    short search(int rank_prime);
    short simulate(int n_player);
    void simulate_games(int num_games, int n_player);
    int* random_five();
    void benchmark_eval();
};

#endif