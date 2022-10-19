#include "stack.h"
#include <stdio.h>   /* printf */
#include <assert.h>  /* assert */

void StackCreateTest();
void StackPopTest();
void StackPushTest();
void StackPeekTest();
void StackSizeTest();
void StackIsEmptyTest();
void StackCapacityTest();

/*--------------------------------------------*/

int main()
{

	StackCreateTest();
	StackPopTest();
	StackPushTest();
	StackPeekTest();
	StackSizeTest();
	StackIsEmptyTest();
	StackCapacityTest();
	printf("\n\n------------SUCCESS!!!-------------\n\n");
	
	return 0;
}


void StackCreateTest()
{
	size_t element_amount = 8;
	size_t size_of_element = 4;
	stack_ty *stack = StackCreate(element_amount , size_of_element);
	assert(StackIsEmpty(stack) == 1);
	StackDestroy(stack);
}


void StackPopTest()
{
	size_t element_amount = 8;
	size_t size_of_element = 4;
	int a = 2;
	int b = 3;
	int c = 4;
	stack_ty *stack = StackCreate(element_amount , size_of_element);

	StackPush(stack , (void*)&a);
	StackPush(stack , (void*)&b);
	StackPush(stack , (void*)&c);	
	StackPop(stack);
	assert( *((int*)StackPeek(stack)) == 3);
	StackPop(stack);
	assert( *((int*)StackPeek(stack)) == 2);
	StackDestroy(stack);
}


void StackPushTest()
{
	size_t element_amount = 8;
	size_t size_of_element = 4;
	int a = 2;
	int b = 3;
	int c = 4;
	int d = 6;
	int e = 8;
	stack_ty *stack = StackCreate(element_amount , size_of_element);
	
	StackPush(stack , (const void*)&a);
	StackPush(stack , (const void*)&b);
	StackPush(stack , (const void*)&c);
	StackPush(stack , (const void*)&d);
	assert( *((int*)StackPeek(stack)) == 6);
	StackPush(stack , (const void*)&e);
	assert( *((int*)StackPeek(stack)) == 8);
	StackDestroy(stack);

}


void StackPeekTest()
{
	size_t element_amount = 8;
	size_t size_of_element = 2;
	short a = 1;
	short b = 3;
	short c = 5;
	short d = 7;
	stack_ty *stack = StackCreate(element_amount , size_of_element);

	StackPush(stack , (const void*)&a);
	StackPush(stack , (const void*)&b);
	StackPush(stack , (const void*)&c);
	StackPush(stack , (const void*)&d);
	assert( *((short*)StackPeek(stack)) == 7);
	StackPop(stack);
	assert( *((short*)StackPeek(stack)) == 5);
	StackDestroy(stack);	
}


void StackSizeTest()
{
	size_t element_amount = 8;
	size_t size_of_element = 8;
	unsigned long a = 15448465456;
	unsigned long b = 34546546545;
	unsigned long c = 58412155454;
	unsigned long d = 12121342424;
	stack_ty *stack = StackCreate(element_amount , size_of_element);
	
	StackPush(stack , (const void*)&a);
	StackPush(stack , (const void*)&b);
	StackPush(stack , (const void*)&c);
	StackPush(stack , (const void*)&d);
	assert(StackSize(stack) == 4);
	StackDestroy(stack);	
}


void StackIsEmptyTest()
{
	size_t element_amount = 8;
	size_t size_of_element = 1;
	char b = 23;
	char c = 45;
	stack_ty *stack = StackCreate(element_amount , size_of_element);
	
	StackPush(stack , (const void*)&b);
	StackPush(stack , (const void*)&c);
	StackPop(stack);
	StackPop(stack);
	assert(StackIsEmpty(stack) == 1);
	StackDestroy(stack);
}


void StackCapacityTest()
{
	size_t element_amount = 8;
	size_t size_of_element = 5;
	stack_ty *stack = StackCreate(element_amount , size_of_element);
	assert(StackCapacity(stack) == 40);
	StackDestroy(stack);
}














