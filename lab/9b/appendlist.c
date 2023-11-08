#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int num;
    struct _node *next;
} Node;

Node *buildList(char filename[]);
void printList(char prefix[], Node *head);
Node *merge(Node *head1,  Node *head2);

int main(int argc, char *argv[]) {
	if (argc!=3) {
		printf("Usage: %s file1 file2\n", argv[0]);
		return 1;
	}
    Node *head1=buildList(argv[1]);
    printList("List1: ", head1);
    Node *head2=buildList(argv[2]);
    printList("List2: ", head2);
    Node *head3=merge(head1, head2);
    printList("Merged list: ", head3);
    return 0;
}

// Build a linked list of integers read from a file
Node *buildList(char filename[]) {
    Node *head=NULL, *tail;
	FILE *fp=fopen(filename, "r");
	if (fp==NULL) return NULL;
    while (1) {
        int n;
        fscanf(fp, "%d", &n);
        if (feof(fp)) break;
        Node *newNode=malloc(sizeof(Node));
        newNode->num=n;
        newNode->next=NULL;
		if (head==NULL)
			head=newNode;
		else
			tail->next=newNode;
		tail=newNode;
    }
	fclose(fp);
    return head;
}

// Print the linked list.
void printList(char prefix[], Node *head)
{
	printf("%s", prefix);
    for (Node *cur = head; cur != NULL; cur = cur->next)
        if (cur==head)
            printf("%d", cur->num);
       	else
            printf("-->%d", cur->num);
    printf("\n");
}

// DO NOT CHANGE ANYTHING ABOVE THIS LINE

/*
Merge two lists into one by:
- Appending the shorter list to the longer one.
- If both lists have the same length, put the second list after the first one.
- If one list is empty, return the other list.



You can either relink the existing lists or make new nodes.
*/

// You can write helper functions here if you wish

Node *merge(Node *head1, Node *head2)
{
    //TODO
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    Node *cur1 = head1;
    Node *cur2 = head2;
    int count1 = 0;
    int count2 = 0;
    while (cur1 != NULL) {
        count1++;
        cur1 = cur1->next;
    }
    while (cur2 != NULL) {
        count2++;
        cur2 = cur2->next;
    }
    if (count1 > count2) {
        cur1 = head1;
        while (cur1->next != NULL) {
            cur1 = cur1->next;
        }
        cur1->next = head2;
        return head1;
    }
    else if (count1 < count2) {
        cur2 = head2;
        while (cur2->next != NULL) {
            cur2 = cur2->next;
        }
        cur2->next = head1;
        return head2;
    }
    else {
        cur1 = head1;
        while (cur1->next != NULL) {
            cur1 = cur1->next;
        }
        cur1->next = head2;
        return head1;
    }

}
