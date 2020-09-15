/**
 * @file data.h
 * @brief Very basic data manipulation
 *
 * This header file provides a way to convert
 * integers to ASCII strings and vice versa.
 *
 * @author Atharva Joshi
 * @date 31/07/2020
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief This function converts data from a standard integer
 *        into an ASCII string
 *
 * @param data: Integer to be converted to ASCII
 * @param ptr : Pointer to the ASCII string
 * @param base: Base that tells how to interpret the number
 *
 * @return the length of the converted data
 *
 */

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base);

/**
 * @brief This function converts data back from
 *        an ASCII string into an integer
 *
 * @param ptr   : Pointer to the ASCII string
 * @param digits: Number of digits in your character set
 * @param base  : Base that tells how to interpret the number
 *
 * @return The converted 32-bit signed integer
 *
 */

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
