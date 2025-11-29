#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// constants
#define RANK_SIZE 8
#define FILE_SIZE 8

// macros
#define SET_BIT(bitboard, square) (bitboard |= (1ULL << square))
#define GET_BIT(bitboard, square) (bitboard & (1ULL << square))

// enums
enum {
    a8, b8, c8, d8, e8, f8, g8, h8,
    a7, b7, c7, d7, e7, f7, g7, h7,
    a6, b6, c6, d6, e6, f6, g6, h6,
    a5, b5, c5, d5, e5, f5, g5, h5,
    a4, b4, c4, d4, e4, f4, g4, h4,
    a3, b3, c3, d3, e3, f3, g3, h3,
    a2, b2, c2, d2, e2, f2, g2, h2,
    a1, b1, c1, d1, e1, f1, g1, h1,
};

/*
"a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
"a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
"a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
"a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
"a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
"a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
"a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
"a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
*/

// macros
#define GET_BIT(bitboard, square) (bitboard & (1ULL << square))

void print_bitboard(uint64_t bitboard) {
    printf("\n");
    for (size_t rank = 0; rank < RANK_SIZE; rank++)
    {
        for (size_t file = 0; file < FILE_SIZE; file++)
        {
            if(!file) {
                printf(" %zu ", RANK_SIZE - rank);
            }

            int square = rank * 8 + file;
            printf(" %d", GET_BIT(bitboard, square) ? 1 : 0);
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n\n");
}

// main
int main() {
    printf("Bitboard Chess Engine\n");

    uint64_t bitboard = 0ULL;
    print_bitboard(bitboard);

    return 0;
}