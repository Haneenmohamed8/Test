#include "monty.h"

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current bytecode.
 */
void pint(stack_t **stack, unsigned int line_number)
{
        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
                fclose(bus.file);
                free(bus.content);
                free_stack(*stack);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (*stack)->n);
}




#include "monty.h"

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current bytecode.
 */
void pop(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
                fclose(bus.file);
                free(bus.content);
                free_stack(*stack);
                exit(EXIT_FAILURE);
        }

        temp = *stack;
        *stack = (*stack)->next;
        if (*stack != NULL)
                (*stack)->prev = NULL;
        free(temp);
}



#include "monty.h"

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: The line number of the current bytecode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

        if (*stack == NULL || (*stack)->next == NULL)
        {
                fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
                fclose(bus.file);
                free(bus.content);
                free_stack(*stack);
                exit(EXIT_FAILURE);
        }

        temp = (*stack)->next;
        (*stack)->next = temp->next;
        if (temp->next != NULL)
                temp->next->prev = *stack;
        temp->prev = NULL;
        temp->next = *stack;
        (*stack)->prev = temp;
        *stack = temp;
}




#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Stack head.
 * @counter: Line number.
 */
void f_add(stack_t **head, unsigned int counter)
{
        if (*head == NULL || (*head)->next == NULL)
        {
                fprintf(stderr, "L%u: can't add, stack too short\n", counter);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }

        (*head)->next->n += (*head)->n;
        f_pop(head, counter);
}




#include "monty.h"
/**
  *f_nop- nothing
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void f_nop(stack_t **head, unsigned int counter)
{
	(void) counter;
	(void) head;
}
