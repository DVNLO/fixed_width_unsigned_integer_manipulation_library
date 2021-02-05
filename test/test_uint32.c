#include <stdio.h>

#include "uint32.h"
#include "test_uint32.h"

uint8_t
fwuim_test_uint32_get_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = ~(0x01);
    uint32_t expected = 0x00;
    // iteratively get the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_get_bit_uint32(i, val);
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
fwuim_test_uint32_get_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = 0x01;
    uint32_t expected = 0x01;
    // iteratively get the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_get_bit_uint32(i, val);
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
fwuim_test_uint32_set_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = 0x00;
    uint32_t expected = 0x01;
    // iteratively set the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_set_bit_uint32(i, val);
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
fwuim_test_uint32_set_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = 0x01;
    uint32_t expected = 0x01;
    // iteratively set the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_set_bit_uint32(i, val);
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
fwuim_test_uint32_clear_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = ~(0x01);
    uint32_t expected = ~(0x01);
    // iteratively clear the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_clear_bit_uint32(i, val);
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
fwuim_test_uint32_clear_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = 0x01;
    uint32_t expected = 0x00;
    // iteratively clear the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_clear_bit_uint32(i, val);
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
fwuim_test_uint32_toggle_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = ~(0x01);
    uint32_t expected = ~(0x00);
    // iteratively toggle the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_toggle_bit_uint32(i, val);
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
fwuim_test_uint32_toggle_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT32_T_BITS = sizeof(uint32_t) * 8U;
    uint32_t val = 0x01;
    uint32_t expected = 0x00;
    // iteratively toggle the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT32_T_BITS; ++i)
    {
        uint32_t const got = fwuim_toggle_bit_uint32(i, val);
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
fwuim_test_uint32(void)
{
    uint8_t rc; // return code
    rc = fwuim_test_uint32_get_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_get_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_get_all_0_bits failed");
    }
    rc = fwuim_test_uint32_get_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_get_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_get_all_1_bits failed");
    }
    rc = fwuim_test_uint32_set_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_set_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_set_all_0_bits failed");
    }
    rc = fwuim_test_uint32_set_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_set_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_set_all_1_bits failed");
    }
    rc = fwuim_test_uint32_clear_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_clear_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_clear_all_0_bits failed");
    }
    rc = fwuim_test_uint32_clear_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_clear_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_clear_all_1_bits failed");
    }
    rc = fwuim_test_uint32_toggle_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_toggle_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_toggle_all_0_bits failed");
    }
    rc = fwuim_test_uint32_toggle_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint32_toggle_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint32_toggle_all_1_bits failed");
    }
}