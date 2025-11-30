#ifndef BITBOARD_H
#define BITBOARD_H

#include <stdint.h>
#include "defs.h"

#define SET_BIT(bitboard, square)   ((bitboard) |= (1ULL << (square)))
#define CLEAR_BIT(bitboard, square) ((bitboard) &= ~(1ULL << (square)))
#define GET_BIT(bitboard, square)   ((bitboard) & (1ULL << (square)))

void print_bitboard(uint64_t bitboard);

#endif