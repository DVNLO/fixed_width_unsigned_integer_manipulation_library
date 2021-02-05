#pragma once

#include <stdint.h>

inline
uint64_t
fwuim_get_bit_uint64(uint8_t const bit_idx, uint64_t const vals)
// returns the value (in lsb position) of the bit_idx-th bit in vals.
{
    return (vals >> bit_idx) & (uint64_t)(0x1);
}

inline
uint64_t
fwuim_set_bit_uint64(uint8_t const bit_idx, uint64_t const vals)
// returns a value after setting the bit_idx-th bit in vals.
{
    return ((uint64_t)(0x1) << bit_idx) | vals;    
}

inline
uint64_t
fwuim_clear_bit_uint64(uint8_t const bit_idx, uint64_t const vals)
// returns a value after clearing the bit_idx-th bit in vals.
{
    return (~((uint64_t)(0x1) << bit_idx)) & vals;
}

inline
uint64_t
fwuim_toggle_bit_uint64(uint8_t const bit_idx, uint64_t const vals)
// returns a value after toggling the bit_idx-th bit in vals.
{
    return ((uint64_t)(0x1) << bit_idx) ^ vals;
}
