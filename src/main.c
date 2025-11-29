#include <stdio.h>
#include <stdint.h>


// constants
#define RANK_SIZE 8
#define FILE_SIZE 8

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

    uint64_t bitboard = 789ULL;

    print_bitboard(bitboard);

    return 0;
}