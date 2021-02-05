#include <stdio.h>

#include "uint16.h"
#include "test_uint16.h"

uint8_t
fwuim_test_uint16_get_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = ~(0x01);
    uint16_t expected = 0x00;
    // iteratively get the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_get_bit_uint16(i, val);
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
fwuim_test_uint16_get_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = 0x01;
    uint16_t expected = 0x01;
    // iteratively get the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_get_bit_uint16(i, val);
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
fwuim_test_uint16_set_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = 0x00;
    uint16_t expected = 0x01;
    // iteratively set the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_set_bit_uint16(i, val);
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
fwuim_test_uint16_set_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = 0x01;
    uint16_t expected = 0x01;
    // iteratively set the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_set_bit_uint16(i, val);
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
fwuim_test_uint16_clear_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = ~(0x01);
    uint16_t expected = ~(0x01);
    // iteratively clear the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_clear_bit_uint16(i, val);
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
fwuim_test_uint16_clear_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = 0x01;
    uint16_t expected = 0x00;
    // iteratively clear the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_clear_bit_uint16(i, val);
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
fwuim_test_uint16_toggle_all_0_bits(void)
// returns 0x01 on pass or 0x00 on failure
{   
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = ~(0x01);
    uint16_t expected = ~(0x00);
    // iteratively toggle the i-th 0 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_toggle_bit_uint16(i, val);
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
fwuim_test_uint16_toggle_all_1_bits(void)
// returns 0x01 on pass or 0x00 on failure
{
    size_t const SIZE_UINT16_T_BITS = sizeof(uint16_t) * 8U;
    uint16_t val = 0x01;
    uint16_t expected = 0x00;
    // iteratively toggle the i-th 1 bit
    for(size_t i = 0; i < SIZE_UINT16_T_BITS; ++i)
    {
        uint16_t const got = fwuim_toggle_bit_uint16(i, val);
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
fwuim_test_uint16(void)
{
    uint8_t rc; // return code
    rc = fwuim_test_uint16_get_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_get_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_get_all_0_bits failed");
    }
    rc = fwuim_test_uint16_get_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_get_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_get_all_1_bits failed");
    }
    rc = fwuim_test_uint16_set_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_set_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_set_all_0_bits failed");
    }
    rc = fwuim_test_uint16_set_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_set_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_set_all_1_bits failed");
    }
    rc = fwuim_test_uint16_clear_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_clear_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_clear_all_0_bits failed");
    }
    rc = fwuim_test_uint16_clear_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_clear_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_clear_all_1_bits failed");
    }
    rc = fwuim_test_uint16_toggle_all_0_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_toggle_all_0_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_toggle_all_0_bits failed");
    }
    rc = fwuim_test_uint16_toggle_all_1_bits();
    if(rc)
    {
        puts("fwuim_test_uint16_toggle_all_1_bits passed");
    }
    else
    {
        puts("fwuim_test_uint16_toggle_all_1_bits failed");
    }
}