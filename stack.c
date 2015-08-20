#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#define N 5




//Initialization of the stack

Stack* init(){
	Stack *s;
	s = (Stack*)malloc(sizeof(Stack));
	if (s == NULL){
		printf("FATAL ERROR!\n");
		exit(1);
	}
	s->n = 0;
	return s;
}

//Push Operation

void push(int q,Stack*s){
	//Checks stack overflow
	if (s->n == N){
		printf("Stack Overflow!\n");
		exit(1);
	}	
	s->vector[s->n] = q;
	s->n++;
}

int pop(Stack*s){
	int v;
	if (s->n == 0){
		printf("There's no element in the stack!\n");
		exit(2);
	}
	s->n--;
	v = s->vector[s->n];
	
	return v;
	
}

void print_stack(Stack*s){
	int i;
	for(i = 0; i<s->n; i++){
		printf("vector[%d] = %d \n",i, s->vector[i]);
	}
}

void print_inverse_stack(Stack*s){
	int i;
	for(i = s->n-1; i>=0; i--){
		printf("vector[%d] = %d \n",i, s->vector[i]);
	}
}
