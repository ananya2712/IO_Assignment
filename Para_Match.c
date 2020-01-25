#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
char data; 
struct Node *next; 
}; 

//FUNCTION DEClARATIONS 
void push(struct Node** top_ref, int new_data); //PUSH FUNCTION
int pop(struct Node** top_ref); //POP FUNCTION

int Pair_Match(char char1, char char2) 
{ 
if (char1 == '(' && char2 == ')') 
	return 1; 
else if (char1 == '{' && char2 == '}') 
	return 1; 
else if (char1 == '[' && char2 == ']') 
	return 1; 
else
	return 0; 
} 

int check(char expr[]) 
{ 
int k = 0; 
struct Node *stack = NULL; 
while (expr[i]) 
{
	if (expr[k] == '{' || expr[k] == '(' || expr[k] == '[') 
		push(&stack, exp[i]); 

	if (expr[k] == '}' || expr[k] == ')' || expr[k] == ']') 
	{ 
		if (stack == NULL) 
		return 0; 
		else if ( !Pair_Match(pop(&stack), exp[k]) ) 
		return 0; 
	} 
  k++; 
} 
if (stack == NULL) 
	return 1; 
else
	return 0; 
} 

int main() 
{ 
char expression[100] = "{()}[]"; 
if (check(expression)) 
	printf("Balanced \n"); 
else
	printf("Not Balanced \n"); 
return 0; 
}	 

void push(struct Node** top_ref, int new_data) 
{ 
struct Node* new_node = 
			(struct Node*) malloc(sizeof(struct Node)); 

if (new_node == NULL) 
{ 
	printf("Stack overflow n"); 
	getchar(); 
	exit(0); 
}		 
new_node->data = new_data; 

new_node->next = (*top_ref); 

(*top_ref) = new_node; 
} 

int pop(struct Node** top_ref) 
{ 
char res; 
struct Node *top; 
if (*top_ref == NULL) 
{ 
	printf("Stack overflow n"); // Too many elements in the stack
	getchar(); 
	exit(0); 
} 
else
{ 
	top = *top_ref; 
	res = top->data; 
	*top_ref = top->next; 
	free(top); 
	return res; 
} 
} 
