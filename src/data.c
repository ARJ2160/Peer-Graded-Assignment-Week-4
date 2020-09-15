/**
 * @file data.c
 * @brief Perform basic data manipulation.
 *
 *
 * @author Atharva R Joshi
 * @date 31/07/2020
 *
 */

#include <stdint.h>
#include <stddef.h>
#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t* ptr, uint32_t base){

  	int32_t temp = data;
  	uint8_t size;
  	int i = 0;
  
  	if(temp<0){
    		temp *= -1;
  	}
  	else if(temp==0){
    		*ptr = '0';
    		*(ptr+1) = '\0';
   		 return 2;
	}
  
	while(temp>0){
    		*(ptr+i) = temp % base;
   		 if( *(ptr+i) >= 0 && *(ptr+i) <= 9 ){
	  		*(ptr+i) += 48;
		}
		else{
	  	*(ptr+i) += 55;
		}
    		temp /= base;
   	 	i++;
	}
  
  	if(data < 0){
   		 *(ptr+i) = '-';
    		i++;
  	}
  
  	*(ptr+i) = '\0';
  	ptr = my_reverse(ptr, i);
  	size = i+1;
  	return size;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
  
	uint8_t negative;
	int32_t value = 0;
	uint8_t temp;
	int i=0;
  
	if( *ptr == '-' ){
		negative = 1;
		i++;
	}
	else{
	negative = 0;
	}
  
	while( *(ptr+i) != '\0' ){
		temp = *(ptr+i);
		if( temp >= '0' && temp <= '9' ){
			temp -= 48;
		}
		else{
			temp -= 55;
		}
		value *= base;
		value += temp;
		i++;
	}
  
	if(negative){
		value *= -1;
	}

	return value;
}
