#include "stack.h"
 
#include <stdio.h>
 
#define SUCCESS 1
#define FAIL 0
 
void test();
 
void test() {
struct elem* head = init(45);
 
printf("INITIALIZING STACK\n");
printf("head -> val = %d\n", head->val);
if (head->val == 45)
printf("SUCCESS\n");
else
printf("FAIL\n");
 
push(&head, -123);
printf("PUSHING VALUE -123\n");
printf("head -> val = %d\n", head->val);
if (head->val == -123)
printf("SUCCESS\n");
else
printf("FAIL\n");
 
printf("POP MUST RETURN -123\n");
 
int res = pop(&head);
printf("pop = %d\n", res);
if (res == -123)
printf("SUCCESS\n");
else
printf("FAIL\n");
 
printf("NOW STACK TOP MUST BE VALUE 45\n");
printf("head -> val = %d\n", head->val);
if (head->val == 45)
printf("SUCCESS\n");
else
printf("FAIL\n");
 
destroy(&head);
}
 
int main() {
test();
return 0;
}
 
#include "stack.h"
 
#include <stdlib.h>
 
struct elem* init(int val) {
struct elem* head = (struct elem*)malloc(sizeof(struct elem));
head->val = val;
head->next = NULL;
return head;
}
 
void push(struct elem** head, int val) {
struct elem* tmp = (struct elem*)malloc(sizeof(struct elem));
tmp->val = val;
tmp->next = *head;
*head = tmp;
}
 
int pop(struct elem** head) {
struct elem* tmp = *head;
int value = (*head)->val;
*head = (*head)->next;
free(tmp);
return value;
}
 
void destroy(struct elem** head) {
struct elem* tmp = *head;
while (*head != NULL) {
free(tmp);
*head = (*head)->next;
tmp = *head;
}
}
