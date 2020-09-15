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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Atharva R Joshi
 * @date 31/07/2020
 *
 */
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include "memory.h"

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t* my_memmove(uint8_t *src, uint8_t *dest, size_t length){
  uint8_t *ptr_s;
  uint8_t *ptr_d;

  if( src == dest );

  else if( dest >= src && src+length-1 >= dest ){
    ptr_s = src+length;
    ptr_d = dest+length;
    while( ptr_s > src ){
      ptr_s--;
      ptr_d--;
      *ptr_d = *ptr_s;
    }
  }

  else{
    ptr_s = src;
    ptr_d = dest;
    while( ptr_s < src+length ){
      *ptr_d = *ptr_s;
      ptr_s++;
      ptr_d++;
    }
  }

  return dest;

}

uint8_t* my_memcopy(uint8_t *src, uint8_t *dest, size_t length){
  int i;
  
  for( i=0; i<length; i++){
    *(dest+i) = *(src+i);
  }

  return dest;

}

uint8_t* my_memset(uint8_t *src, size_t length, uint8_t value){
  int i;

  for( i=0; i<length; i++){
    *(src+i) = value;
  }
  
  return src;

}

uint8_t* my_memzero(uint8_t *src, size_t length){

  return (my_memset(src, length, 0));

}

uint8_t* my_reverse(uint8_t *src, size_t length){
  
  int hl = length/2;
  int i;
  uint8_t temp;
  
  for( i=0; i<hl; i++){
    temp = *(src+i);
    *(src+i) = *(src+length-1-i);
    *(src+length-1-i) = temp;
  }

  return src;

}

int32_t* reserve_words(size_t length){

  int32_t* mem = (int32_t*)malloc(4*length);
  
  return mem;

}

void free_words(uint32_t* src){
  
  free(src);

} 
