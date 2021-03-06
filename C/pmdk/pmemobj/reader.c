#include <stdio.h>
#include <string.h>
#include <libpmemobj.h>
//#include "layout.h"

#define LAYOUT_NAME "intro_2" /* will use this in create and open */
#define MAX_BUF_LEN 10        /* maximum length of our buffer */

struct my_root
{
    //size_t len; /* = strlen(buf) */
    char buf[MAX_BUF_LEN];
};

int main(int argc, char *argv[])
{
    PMEMobjpool *pop = pmemobj_open(argv[1], LAYOUT_NAME);
    if (pop == NULL)
    {
        perror("pmemobj_open");
        return 1;
    }

    printf("%d\n", sizeof(struct my_root));
    PMEMoid root = pmemobj_root(pop, sizeof(struct my_root));
    struct my_root *rootp = pmemobj_direct(root);

    /*     if (rootp->len == strlen(rootp->buf))
        printf("%s\n", rootp->buf); */
    printf("%p:%s\n", rootp, rootp->buf);

    pmemobj_close(pop);
    return 0;
}