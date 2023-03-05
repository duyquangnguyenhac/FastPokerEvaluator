
#include "arrays.h"
#include "hash_arrays.h"
#include "poker_engine.h"

class Senzee : public PokerEngine {
   public:
    // Perform a perfect hash lookup(courtesy of Paul Senzee).
    unsigned find_hash(unsigned u) {
        unsigned a, b, r;

        u += 0xe91aaa35;
        u ^= u >> 16;
        u += u << 8;
        u ^= u >> 4;
        b = (u >> 8) & 0x1ff;
        a = (u + (u << 2)) >> 19;
        r = a ^ hash_adjust[b];
        return r;
    }
    short evaluate(int* hand) override {
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
        return hash_values[find_hash(rank_prime)];
    };
};