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
 * @file <Add File Name> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Add FirsName LastName>
 * @date <Add date >
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  unsigned int length = sizeof(test)/sizeof(test[0]);

  /* Statistics and Printing Functions Go Here */
		print_array(test,length);
  		printf("\n");

  		print_statistics(test,length);						  	printf("\n");

  		sort_array(test,length);							print_array(test, length);	
	}

/* Add other Implementation File Code Here */
void print_statistics(unsigned char* test, unsigned int length)
	
	{
		printf("Array statistics:\n");
		printf("Minimum: %d\n", find_minimum(test, length));
		printf("Maximum: %d\n", find_maximum(test, length));
		printf("Mean: %d\n", find_mean(test, length));
		printf("Median: %d\n", find_median(test, length));

	 }

void print_array(unsigned char* test, unsigned int length)
	
	 {
	     	printf("Array: [");

	     	for (unsigned int i = 0; i < length; i++)
	                 {						  					printf("%d", test[i]);
														if (i != length - 1)
												   		{
														   	  printf(", ");
												                }
										              		 }
		    	     printf("]");
	  }

unsigned char find_median(unsigned char* test, unsigned int length) 
	
	 {
    	    sort_array(test, length);

	    if (length % 2 == 0) 
			    		
		{
	// if the length is even, return the average of the two middle values
		 unsigned int index = length / 2;		  		 		 
		 return (test[index - 1] + test[index])/2;
		} 			        	  
	    else	        	   		
	    	{
					        	   				// if the length is odd, return the middle value
		 return test[length / 2];
		}
	 }

unsigned char find_mean(unsigned char* test, unsigned int length)
	 {
	    unsigned int sum = 0;
	    for (unsigned int i = 0; i < length; i++)
		 {
			 sum += test[i];
		 }
	    return sum / length;    
	 }

unsigned char find_maximum(unsigned char* test, unsigned int length) 
	{
	    unsigned char max = test[0];
  	    for (unsigned int i = 1; i < length; i++) 
	    {
		    if (test[i] > max) 
		    {
			    max = test[i];
		    }
	    }
	    return max;
 	}

unsigned char find_minimum(unsigned char* test, unsigned int length)
	{
	    unsigned char min = test[0];
	    for (unsigned int i = 1; i < length; i++) 
	    {
		    if (test[i] < min) 
		    {
			    min = test[i];
		    }
	    }
	    return min;
	}

void sort_array(unsigned char* test, unsigned int length) 
	{
	     for (unsigned int i = 0; i < length - 1; i++) 
     	      {
	      	      for (unsigned int j = i + 1; j < length; j++)	 
	      	      {
	      		      if (test[j] > test[i])
	      		      {
				      // swap the values
				      unsigned char temp = test[i];
				      test[i] = test[j];
				      test[j] = temp;
			      }
		      }
	      }
       	
	}
