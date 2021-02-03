#ifndef FIXED_WIDTH_UNSIGNED_INTEGER_MANIPULATION_LIB_UINT8_H
#define FIXED_WIDTH_UNSIGNED_INTEGER_MANIPULATION_LIB_UINT8_H

#include <stdint.h>

inline
uint8_t
get_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns the value (in lsb position) of the bit_idx-th bit in vals.
{
    return (vals >> bit_idx) & 0x1;
}

inline
uint8_t
set_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns a value after setting the bit_idx-th bit in vals.
{
    return (0x1 << bit_idx) | vals;    
}

inline
uint8_t
clear_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns a value after clearing the bit_idx-th bit in vals.
{
    return (~(0x1 << bit_idx)) & vals;
}

inline
uint8_t
toggle_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns a value after toggling the bit_idx-th bit in vals.
{
    return (0x1 << bit_idx) ^ vals;
}

#endif // FIXED_WIDTH_UNSIGNED_INTEGER_MANIPULATION_LIB_UINT8_H