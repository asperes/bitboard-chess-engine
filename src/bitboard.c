#include "bitboard.h"
#include <stdio.h>

void print_bitboard(uint64_t bitboard) {
    printf("\n");
    for (int rank = 0; rank < RANK_SIZE; rank++) {
        for (int file = 0; file < FILE_SIZE; file++) {
            if (!file) {
                printf(" %d ", RANK_SIZE - rank);
            }

            int square = rank * 8 + file;
            printf(" %d", GET_BIT(bitboard, square) ? 1 : 0);
        }
        printf("\n");
    }
    printf("\n    a b c d e f g h\n\n");
    printf("Bitboard: %lluULL\n", bitboard);
}