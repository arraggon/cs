#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "stack.h"


/*
 * Define your call struct here.
 */

struct call
{
	int callId;
	char callName[100];
	char callReason[100];
};

struct call* call_create(){
	struct call* call = (struct call*)malloc(sizeof(struct call));
	return call;
}

int get_option(){
	printf("1. Receive a new call\n");
    printf("2. Answer a call\n");
    printf("3. Current state of the stack - answered calls\n");
    printf("4. Current state of the queue - calls to be answered\n");
    printf("5. Quit\n");
    printf("Choose an option: ");
    int option;
    scanf("%d", &option);
	return option;
}

void receive(int id, struct queue* q){
	struct call* c = call_create();
	c->callId = id;
	printf("Enter caller's name: ");
	scanf("%s", c->callName);
	printf("Enter call reason: ");
	scanf("%s", c->callReason);
	
	queue_enqueue(q, c);
}

void answer(struct queue* q, struct stack* s, int n){
	if (queue_isempty(q)) {
        printf("No more calls need to be answered at the moment!\n");
    } else {
		n++;
        struct call *answeredCall = queue_dequeue(q);
		stack_push(s, answeredCall);
        
        printf("The following call has been answered and added to the stack!\n");
        printf("Call ID: %d\nCaller’s name: %s\nCall reason: %s\n\n", 
               answeredCall->callId, answeredCall->callName, answeredCall->callReason);
    }
}

void answeredCall(struct stack* s, int n) {
    if (stack_isempty(s)) {
        printf("The stack is empty. No calls have been answered yet.\n");
    } else {
        struct call* lastCall = (struct call*)stack_top(s); // Assumes a function peekStack() that returns the top element without popping it
        printf("Number of calls answered: %d\n", n); // Assumes a function sizeStack() that returns the number of elements
        printf("Details of the last call answered:\n");
        printf("Call ID: %d\n", lastCall->callId);
        printf("Caller’s name: %s\n", lastCall->callName);
        printf("Call reason: %s\n", lastCall->callReason);
    }
}

void unAnsweredCall(struct queue* q,int n1, int n2) {
    if (queue_isempty(q)) {
        printf("The queue is empty. There are no calls waiting to be answered.\n");
    } else {
        struct call* nextCall = (struct call*)queue_front(q); // Assumes a function peekQueue() that returns the front element without dequeuing it
        printf("Number of calls to be answered: %d\n", n1-n2); // Assumes a function sizeQueue() that returns the number of elements
        printf("Details of the next call to be answered:\n");
        printf("Call ID: %d\n", nextCall->callId);
        printf("Caller’s name: %s\n", nextCall->callName);
        printf("Call reason: %s\n", nextCall->callReason);
    }
}


int main(int argc, char const *argv[]) {
	struct stack* s = stack_create();
	struct queue* q = queue_create();
	while (1){
		int id = 0, answeredCallNum = 0;
		int option = get_option();
		if (option == 5)
		{
			break;
		} 
		switch (option)
		{
		case 1:
				receive(++id, q);
			break;
		case 2:
				answer(q, s, answeredCallNum);
			break;
		case 3:
				answeredCall(s, answeredCallNum);
			break;
		case 4:
				unAnsweredCall(q, id+1, answeredCallNum);
			break;
		default:
			break;
		}
	}
	
	return 0;
}
