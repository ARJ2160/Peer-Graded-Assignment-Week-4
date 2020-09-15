/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Atharva R Joshi
 * @date 31/07/2020
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves elements from one address to other
 *
 * Given a pointer to the source and destination along with the
 * no of bytes to be moved, the function performs the move operation
 * with guard against memory overlapping
 *
 * @param src Pointer to the begining of data in source location
 * @param dst Pointer to the begining of data in destination
 * @param length No of bytes of data to be transferred
 *
 * @return Pointer to the begining of destination memory space
 */
uint8_t* my_memmove(uint8_t * src, uint8_t * dest, size_t length);

/**
 * @brief Copies elements from one address to other
 *
 * Given a pointer to the source and destination along with the
 * no of bytes to be copied, the function performs the copy
 * operation.
 *
 * Caution: No guard against memory overlapping
 * Improper use may result in corrupt data
 *
 * @param src Pointer to the begining of data in source location
 * @param dst Pointer to the begining of data in destination
 * @param length No of bytes of data to be transferred
 *
 * @return Pointer to the begining of destination memory space
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dest, size_t length);

/**
 * @brief Initializes the given memory space to the given value
 *
 * Given a pointer to begining of memory space, size of the
 * memory space and value to be stored. The function saves the
 * value to all address in the given memory space.
 *
 * @param src Pointer to the begining of the memory space
 * @param length Length/size of the memory space
 * @param value Value to be initialized
 *
 * @return Pointer to the begining of the memory space
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Initializes the given memory space to zero
 * Given a pointer to the begining of a memory space and size of
 * the space, the function initializes all locations in the memory
 * space to zero
 *
 * Note: Uses my_memset() function with value=0 param internally
 *
 * @param src Pointer to the begining of the memory space
 * @param length Length/size of the memory space
 *
 * @return Pointer to the begining of the memory space
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverses the order of bytes in the given memory space
 *
 * Given a pointer to the begining of memory space and size of
 * the space, the function reverses the order of bytes within
 * the given space
 *
 * @param src Pointer to the begining of the memory space
 * @param length Length/size of the meory space
 *
 * @return Pointer to the begining of the memory space
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Reverses the given amount of words in memory
 *
 * Given the number of words to be reserved in memory, the function
 * reserves memory and returns pointer, pointing to the begining
 * of the reserved space
 *
 * @param length Number of words to be reserved;
 *
 * @return Pointer to the begining of the reserved space
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Deallocates the memory space addressed by the pointer
 *
 * Given a pointer to the begining of a memory space, the function
 * deallocates the memory space and frees up the held space
 *
 * @param src Pointer to the begining of the memory space
 *
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
