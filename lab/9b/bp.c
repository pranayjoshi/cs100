#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _letter {
        char info;
        struct _letter *next;
} Letter;

Letter *buildList(char word[]);
void printList(Letter *head);

int main() {
	char word[100];
	printf("Enter a word: ");
	scanf("%s", word);

	Letter *head = buildList(word);

	printList(head);

	return 0;
}

// DO NOT MODIFY ABOVE THIS LINE

// Optionally implement the following helper function
/*
Letter *addFront(Letter *head, char ch) {
   
}
*/

Letter *addFront(Letter *head, char ch) {
   Letter *newNode = malloc(sizeof(Letter));
   newNode->info = ch;
   newNode->next = head;
   return newNode;
}

// Print the linked list.
// For example, if the linked list represents CRIMSON,
// it prints C-->R-->I-->M-->S-->O-->N
void printList(Letter *head) {
   for (Letter *cur = head; cur != NULL; cur = cur->next) {
	  if (cur == head) {
		 printf("%c", cur->info);
	  }
	  else {
		 printf("-->%c", cur->info);
	  }
   }
   printf("\n");
}

// Build a linked list to represent the specified word.
// Return the head of the linked list built.
Letter *buildList(char str[]) {
   Letter *head = NULL;
   for (int i = 0; i < strlen(str); i++) {
	  head = addFront(head, str[i]);
   }
   return head;
}