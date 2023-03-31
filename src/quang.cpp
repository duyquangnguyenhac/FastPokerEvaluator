#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

#include "arrays.h"
#include "hash_arrays.h"
#include "poker_engine.h"

using namespace std;
class Quang : public PokerEngine {
   public:
    unordered_map<int, int> map;
    Quang() : PokerEngine() {
        fstream file;
        file.open("prime_multiplications_raw.txt", ios::in);
        int idx = 0;
        if (file.is_open()) {  // checking whether the file is open
            string tp;
            while (getline(file, tp)) {  // read data from file object and put it into string.
                map[stoi(tp)] = idx;
                idx++;
            }
            file.close();  // close the file object.
        }
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
        return values[map[rank_prime]];
    };
};