#include "attacks.h"
#include "bitboard.h"

uint64_t mask_pawn_attacks(int side, int square) {
    uint64_t attacks = 0ULL;
    uint64_t bitboard = 0ULL;

    SET_BIT(bitboard, square);

    if (side == white) {
        if ((bitboard >> 7) & NOT_A_FILE) attacks |= (bitboard >> 7);
        if ((bitboard >> 9) & NOT_H_FILE) attacks |= (bitboard >> 9);
    } else {
        if ((bitboard << 7) & NOT_H_FILE) attacks |= (bitboard << 7);
        if ((bitboard << 9) & NOT_A_FILE) attacks |= (bitboard << 9);
    }

    return attacks;
}

void init_attack_tables() {
    for (int square = 0; square < SQUARES_SIZE; square++)
    {
        pawn_attacks[white][square] = mask_pawn_attacks(white, square);
        pawn_attacks[black][square] = mask_pawn_attacks(black, square);
    }
}