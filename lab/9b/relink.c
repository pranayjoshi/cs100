#include <stdio.h>

typedef struct _letter {
        char info;
        struct _letter *next;
} Letter;

int main(void) {
        Letter a, b, c, d, e, f, g, h, i, j, k, l, m;

        a.info = 'E'; b.info = 'L'; c.info = 'E';
        d.info = 'V'; e.info = 'E'; f.info = 'N';
        g.info = 'P'; h.info = 'L'; i.info = 'U';
        j.info = 'S'; k.info = 'T'; l.info = 'W';
        m.info = 'O';

		a.next = &b; b.next = &c; c.next = &d;
		d.next = &e; e.next = &f; f.next = &g;
		g.next = &h; h.next = &i; i.next = &j;
		j.next = &k; k.next = &l; l.next = &m;
		m.next = NULL;

        // Print the word
        Letter *ptr = &a;
        while ( ptr != NULL ) {
                printf("%c", ptr->info);
                ptr = ptr->next;
        }
        printf("\n");

        // Relinks the 13 nodes here so that it spells "TWELVEPLUSONE"
        // YOU CANNOT CHANGE THE "info" FIELD of ANY NODES

        // After rearranging, print the new word
        ptr = &k;
        while ( ptr != NULL ) {
                printf("%c", ptr->info);
                ptr = ptr->next;
        }
        printf("\n");

        return 0;
}
