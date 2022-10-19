/*****************************************************   
 * Author : Avia Avikasis                            *
 * Reviewer: Gal Cohen                               *                                                 
 * Description : imlementation of stack data         *
 * structure.                                        *
 *                                                   *
 *****************************************************/
#include "stack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

struct stack
{
    char* top;
    char* base;
    size_t size_of_element;
    size_t capacity;  
};



stack_ty *StackCreate(size_t element_amount, size_t size_of_element)
{
	stack_ty *stack = (stack_ty*)malloc(sizeof(stack_ty));
	if(NULL == stack)
	{
		return NULL;
	}
	stack -> base = (char*)malloc(element_amount * size_of_element);
	if(NULL == stack->base)
	{
		free(stack);
		return NULL;
	}

	stack -> top = stack -> base;
	stack -> size_of_element = size_of_element;
	stack -> capacity = element_amount * size_of_element;
	
	return stack;
}



void StackDestroy(stack_ty *stack)
{
	assert(NULL != stack);
	free(stack -> base);
	free(stack);	
}


void StackPop(stack_ty *stack)
{
	assert(NULL != stack);
	stack -> top -= stack -> size_of_element;
}


void StackPush(stack_ty *stack, const void *element)
{
	assert(NULL != stack);
	assert(NULL != element);
	memcpy(stack -> top , element , stack -> size_of_element);
	(stack -> top) += (stack -> size_of_element); 
}

void *StackPeek(const stack_ty *stack)
{
	return (stack -> top) - (stack -> size_of_element);
}


size_t StackSize(const stack_ty *stack)
{
	return ((stack -> top) - (stack -> base)) / stack -> size_of_element;
}

int StackIsEmpty(const stack_ty *stack)
{
	return (stack -> top == stack -> base);
}


size_t StackCapacity(const stack_ty *stack)
{
	return stack -> capacity;
}



























