#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stack_t *stack = NULL;

int main(int argc, char *argv[]){
    if (argc != 2){
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL){
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[256];
    int line_number = 0;

    while (fgets(line, sizeof(line), file) != NULL){
        line_number++;

        char *opcode = strtok(line, "\n\t\r");
        if (opcode != NULL){
            if (strcmp(opcode, "push") == 0){
                char *arg = strtok(NULL, "\n\t\r");
                push(&stack, line_number);
            }else if (strcmp(opcode, "pall") == 0){
                pall(&stack, line_number);
            }else{
                fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);

    freeStack(&stack);
    return (0);
}

void push(stack_t **stack, unsigned int line_number){
    if (stack == NULL) {
        fprintf(stderr, "L%d: Error - Stack is NULL\n", line_number);
        exit(EXIT_FAILURE);
        }
}

void pall(stack_t **stack, unsigned int line_number){
    if (stack == NULL) {
        fprintf(stderr, "L%d: Error - Stack is NULL\n", line_number);
        exit(EXIT_FAILURE);
    }
}

void freeStack(stack_t **stack){
    if (stack == NULL) {
        fprintf(stderr, "Error - Stack is NULL\n");
        exit(EXIT_FAILURE);
    }
}

