#include "uint8.h"
#include <stddef.h>
#include <stdio.h>

uint8_t
test_uint8_get_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = ~(0x01);
    uint8_t expected = 0x00;
    // iteratively get the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = get_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val <<= 1;
        val |= 0x1; // set lsb; surround 0 with 1s
    }
    return 0x01;    // pass
}

uint8_t
test_uint8_get_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = 0x01;
    uint8_t expected = 0x01;
    // iteratively get the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = get_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val <<= 1;
        val &= ~(0x01);    // clear lsb; surround 1 with 0s
    }
    return 0x01;    // pass
}

uint8_t
test_uint8_set_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = 0x00;
    uint8_t expected = 0x01;
    // iteratively set the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = set_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val = 0x00; // clear val
        expected <<= 1;
        expected &= ~(0x01);    // clear lsb; surround 1 with 0s
    }
    return 0x01;    // pass
}

uint8_t
test_uint8_set_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = 0x01;
    uint8_t expected = 0x01;
    // iteratively set the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = set_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val <<= 1; // clear val
        expected <<= 1;
        expected &= ~(0x01);    // clear lsb; surround 1 with 0s
    }
    return 0x01;    // pass
}

uint8_t
test_uint8_clear_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = ~(0x01);
    uint8_t expected = ~(0x01);
    // iteratively clear the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = clear_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val <<= 1;
        val |= 0x1; // set lsb; surround 0 with 1s
        expected <<= 1;
        expected |= 0x1; // set lsb; surround 0 with 1s
    }
    return 0x01;    // pass
}

uint8_t
test_uint8_clear_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = 0x01;
    uint8_t expected = 0x00;
    // iteratively clear the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = clear_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val <<= 1;
        val &= ~(0x01);    // clear lsb; surround 1 with 0s
    }
    return 0x01;    // pass
}

uint8_t
test_uint8_toggle_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = ~(0x01);
    uint8_t expected = ~(0x00);
    // iteratively toggle the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = toggle_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val <<= 1;
        val |= 0x1; // set lsb; surround 0 with 1s
    }
    return 0x01;    // pass
}

uint8_t
test_uint8_toggle_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT8_T_BITS = sizeof(uint8_t) * 8U;
    uint8_t val = 0x01;
    uint8_t expected = 0x00;
    // iteratively toggle the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT8_T_BITS; ++i)
    {
        uint8_t const got = toggle_bit_uint8(i, val);
        if(got != expected)
        {
            return 0x00;    // failure
        }
        val <<= 1;
        val &= ~(0x01);    // clear lsb; surround 1 with 0s
    }
    return 0x01;    // pass
}

void 
test_uint8(void)
{
    uint8_t rc; // return code
    rc = test_uint8_get_all_0_bits();
    if(rc)
    {
        puts("test_uint8_get_all_0_bits passed");
    }
    else
    {
        puts("test_uint8_get_all_0_bits failed");
    }
    rc = test_uint8_get_all_1_bits();
    if(rc)
    {
        puts("test_uint8_get_all_1_bits passed");
    }
    else
    {
        puts("test_uint8_get_all_1_bits failed");
    }
    rc = test_uint8_set_all_0_bits();
    if(rc)
    {
        puts("test_uint8_set_all_0_bits passed");
    }
    else
    {
        puts("test_uint8_set_all_0_bits failed");
    }
    rc = test_uint8_set_all_1_bits();
    if(rc)
    {
        puts("test_uint8_set_all_1_bits passed");
    }
    else
    {
        puts("test_uint8_set_all_1_bits failed");
    }
    rc = test_uint8_clear_all_0_bits();
    if(rc)
    {
        puts("test_uint8_clear_all_0_bits passed");
    }
    else
    {
        puts("test_uint8_clear_all_0_bits failed");
    }
    rc = test_uint8_clear_all_1_bits();
    if(rc)
    {
        puts("test_uint8_clear_all_1_bits passed");
    }
    else
    {
        puts("test_uint8_clear_all_1_bits failed");
    }
    rc = test_uint8_toggle_all_0_bits();
    if(rc)
    {
        puts("test_uint8_toggle_all_0_bits passed");
    }
    else
    {
        puts("test_uint8_toggle_all_0_bits failed");
    }
    rc = test_uint8_toggle_all_1_bits();
    if(rc)
    {
        puts("test_uint8_toggle_all_1_bits passed");
    }
    else
    {
        puts("test_uint8_toggle_all_1_bits failed");
    }
}

int main()
{
    test_uint8();
}