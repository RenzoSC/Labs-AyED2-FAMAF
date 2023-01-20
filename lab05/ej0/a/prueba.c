#include <stdio.h>
#include <stdlib.h>



int main(void) {
    char *some_str="h.o.l.a m.u.n.d.o.!";
    char *elem = (char *) malloc(sizeof(some_str));
    elem[0] = some_str[0];
    printf("%s", elem);
    return EXIT_SUCCESS;
}
