#ifndef __ILRD_OL127_128__STACK_H__
#define __ILRD_OL127_128__STACK_H__

#include <stddef.h> /* size_t */

typedef struct stack stack_ty;

stack_ty *StackCreate(size_t element_amount, size_t size_of_element);

void StackDestroy(stack_ty *stack);

void StackPop(stack_ty *stack);

void StackPush(stack_ty *stack, const void *element);

void *StackPeek(const stack_ty *stack);

size_t StackSize(const stack_ty *stack);

int StackIsEmpty(const stack_ty *stack);

size_t StackCapacity(const stack_ty *stack);


#endif /* __ILRD_OL127_128_STACK_H__ */
