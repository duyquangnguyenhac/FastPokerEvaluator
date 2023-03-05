#include "poker_engine.h"

#include <stdio.h>
#include <stdlib.h>

#include <chrono>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "arrays.h"

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

PokerEngine::PokerEngine() {
    srand(time(NULL));
    deck = generate_deck();
}
int* PokerEngine::generate_deck() {
    int* deck = new int[num_cards];
    int suit = 0x8000;
    int idx = 0;
    for (int i = 0; i < 4; i++, suit >>= 1) {
        for (int j = 0; j < 13; j++, idx++) {
            deck[idx] = primes[j] | (j << 8) | suit | (1 << (16 + j));
        }
    }
    return deck;
}
void PokerEngine::print_deck() {
    int new_line = 0;
    for (int i = 0; i < num_cards; i++) {
        print_card(&deck[i]);
        new_line += 1;
        if (new_line % 4 == 0) {
            std::cout << "\n";
        }
    }
}

void PokerEngine::shuffle() {
    // Durstenfeld Shuffle
    for (int m = num_cards - 1; m > 0; m--) {
        int i = (rand() % m);
        int temp = deck[m];
        deck[m] = deck[i];
        deck[i] = temp;
    }
}

void PokerEngine::print_card(int* card) {
    char* rank = "23456789TJQKA";
    int rank_bit_mask = 0xF;
    char suit;
    int r = (*card >> 8) & rank_bit_mask;
    if (*card & CLUBS) {
        suit = 'c';
    } else if (*card & DIAMONDS) {
        suit = 'd';
    } else if (*card & HEARTS) {
        suit = 'h';
    } else if (*card & SPADES) {
        suit = 's';
    } else {
        std::cout << "ERROR: NO SUIT FOUND";
        exit(0);
    }
    printf("%c%c ", rank[r], suit);
}
void PokerEngine::print_hand(int* hand, int num_cards) {
    for (int i = 0; i < num_cards; i++, hand++) {
        print_card(hand);
    }
}

short PokerEngine::search(int rank_prime) {
    short l = 0;
    short r = 4887;
    short mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (rank_prime < products[mid]) {
            r = mid - 1;
        } else if (rank_prime > products[mid]) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    std::cout << "ERROR: NO MATCH FOUND";
    return -1;
}

short PokerEngine::evaluate(int* hand) {
    int c1 = *hand;
    int c2 = *(hand + 1);
    int c3 = *(hand + 2);
    int c4 = *(hand + 3);
    int c5 = *(hand + 4);

    int hand_value = (c1 | c2 | c3 | c4 | c5) >> 16;
    if (c1 & c2 & c3 & c4 & c5 & 0xF000) {
        return flushes[hand_value];
    }

    short straight_or_high = unique5[hand_value];
    if (straight_or_high != 0) {
        return straight_or_high;
    }

    int rank_prime = (c1 & 0xFF) * (c2 & 0xFF) * (c3 & 0xFF) * (c4 & 0xFF) * (c5 & 0xFF);
    return values[search(rank_prime)];
}

int* PokerEngine::random_five() {
    shuffle();
    int* hand = (int*)malloc(sizeof(int) * 5);
    int cards_cnt = 0;
    for (cards_cnt; cards_cnt < 5; cards_cnt++) {
        hand[cards_cnt] = deck[cards_cnt];
    }
    return hand;
}

void PokerEngine::benchmark_eval() {
    int* hand = random_five();
    auto t1 = high_resolution_clock::now();
    evaluate(hand);
    auto t2 = high_resolution_clock::now();
    free(hand);
    /* Getting number of milliseconds as a double. */
    duration<double, std::milli> ms_double = t2 - t1;
    duration<double, std::nano> ns_double = t2 - t1;
    std::cout << "Time taken to evaluate one 5 cards hand: " << ms_double.count() << "ms"
              << " " << ns_double.count() << "ns\n";
}

short PokerEngine::simulate(int n_player) {
    shuffle();
    int* all_hands[n_player];
    int all_values[n_player];
    short deck_idx = 0;
    for (int i = 0; i < n_player; i++) {
        int hand[5];
        int cards_cnt = 0;
        for (deck_idx; deck_idx < num_cards, cards_cnt < 5; deck_idx++) {
            hand[cards_cnt++] = deck[deck_idx];
        }
        all_hands[i] = hand;
        all_values[i] = evaluate(hand);
    }
    short max_hand_val = *std::max_element(all_values, all_values + n_player);
    // std::cout << "Best Hand Value: " << max_hand_val << "\n";
    // std::vector<int*> winning_hands{};
    // for (int i = 0; i < n_player; i++) {
    //     if (all_values[i] == max_hand_val) {
    //         winning_hands.push_back(all_hands[i]);
    //     }
    // }
    // return winning_hands;
    return 0;
}

void PokerEngine::simulate_games(int num_games, int n_player) {
    int cnt = 0;

    auto t1 = high_resolution_clock::now();
    while (num_games != 0) {
        // printf("Game %c", cnt++);
        simulate(n_player);
        --num_games;
    }
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << "ms\n";
}