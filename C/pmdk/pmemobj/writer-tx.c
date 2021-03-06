#include <stdio.h>
#include <string.h>
#include <libpmemobj.h>

#define LAYOUT_NAME "intro_2"
#define MAX_BUF_LEN 10
struct my_root
{
    char buf[MAX_BUF_LEN];
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage: %s file-name\n", argv[0]);
        return 1;
    }
    // 创建内存pool
    PMEMobjpool *pop = pmemobj_create(argv[1], LAYOUT_NAME,
                                      PMEMOBJ_MIN_POOL, 0666);

    if (pop == NULL)
    {
        perror("pmemobj_create");
        return 1;
    }
    // 创建根对象
    PMEMoid root = pmemobj_root(pop, sizeof(struct my_root));
    struct my_root *rootp = pmemobj_direct(root);

    char buf[MAX_BUF_LEN] = {0};
    if (scanf("%9s", buf) == EOF)
    {
        fprintf(stderr, "EOF\n");
        return 1;
    }
    // 开始事务操作
    TX_BEGIN(pop)
    {
        // 向事务中增加一块持久内存
        pmemobj_tx_add_range(root, 0, sizeof(struct my_root));
        // 然后可以放心的操作原来的内存块
        memcpy(rootp->buf, buf, strlen(buf));
    }
    TX_END

    pmemobj_close(pop);

    return 0;
}