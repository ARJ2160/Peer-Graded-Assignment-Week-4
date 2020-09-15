/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
*****************************************************************************/
/**
 * @file <stats.c> 
 * @brief <This program calculates the statistics of given array>
 *
 * <The program calculates the Maximum,minimum,mean,median etc of the given array and also display arrays in original and descendng form>
 *
 * @author <Atharva.R.Joshi>
 * @date <13th July 2020 >
 *
 */
#include <stdio.h>
#include "stats.h"
#include "platform.h"
#define SIZE (40)

void print_statistics(unsigned char *ptr, unsigned int size)//To find statistics
{
 #ifdef VERBOSE
  find_median(ptr,SIZE);
  find_mean(ptr,SIZE);
  find_maximum(ptr,SIZE);
  find_minimum(ptr,SIZE);printf("\n");
 #endif
}//print_statistics ends
void find_median(unsigned char *ptr, unsigned int size)//To find median
{
int temp,i,j;
   for(i = 0;i < size-1;i++)
    {
      for(j = 0;j < size-i-1;j++)
      {
         if(ptr[j] > ptr[j+1])
            {
            	temp=ptr[j];
            	ptr[j]=ptr[j+1];
            	ptr[j+1]=temp;
            }
      }
   }
  printf("\nThe Median of the is=%u",(ptr[(size-1)/2]+ptr[size/2])/2);
}//find_median ends
void sort(unsigned char *ptr, unsigned int size)//To sort in Descending order
{
int temp,i,j;
   for(i = 0;i < size-1;i++)
    {
      for(j = 0;j < size-i-1;j++)
      {
         if(ptr[j] < ptr[j+1])
            {
            	temp=ptr[j];
            	ptr[j]=ptr[j+1];
            	ptr[j+1]=temp;
            }
      }
   }
   printf("\nIn Descending Order=");
   for(i=0;i<size;i++)
     {
        printf("%u\t", ptr[i]);
     }
}//sort ends
void find_mean(unsigned char *ptr, unsigned int size)//To find mean
{
        int mean; double total=0.0;
	for(int i=0;i<size;i++)
	{
		total+=ptr[i];
	}
	mean=total/size;  
        printf("\nThe Mean of is=%u",mean);
}//find_mean ends
void find_maximum(unsigned char *ptr, unsigned int size)//To find maximum value
{
    printf("\nThe Maximum of is=%u",ptr[size-1]);
}//find_maximum ends
void find_minimum(unsigned char *ptr, unsigned int size)//To find minimum value
{
     printf("\nThe Minimum value from is=%u",ptr[0]);
}//find_minimum ends
void print_array(unsigned char *ptr, unsigned int size)//To print original array
{
    #ifdef VERBOSE
    int i;
    for(i=0;i<=size-1;i++)
    {
        printf("%u\t", ptr[i]);
    }
    printf("\n");
    #endif
}//print_array ends
