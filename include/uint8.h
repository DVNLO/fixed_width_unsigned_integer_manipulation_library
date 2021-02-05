#pragma once

#include <stdint.h>

inline
uint8_t
fwuim_get_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns the value (in lsb position) of the bit_idx-th bit in vals.
{
    return ((uint8_t)(vals >> bit_idx)) & ((uint8_t)(0x1U));
}

inline
uint8_t
fwuim_set_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns a value after setting the bit_idx-th bit in vals.
{
    return ((uint8_t)(((uint8_t)(0x1U) << bit_idx))) | vals;
}

inline
uint8_t
fwuim_clear_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns a value after clearing the bit_idx-th bit in vals.
{
    return ((uint8_t)(~((uint8_t)(0x1U) << bit_idx))) & vals;
}

inline
uint8_t
fwuim_toggle_bit_uint8(uint8_t const bit_idx, uint8_t const vals)
// returns a value after toggling the bit_idx-th bit in vals.
{
    return ((uint8_t)((uint8_t)(0x1U) << bit_idx)) ^ vals;
}
