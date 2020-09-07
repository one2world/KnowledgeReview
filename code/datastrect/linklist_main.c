#include <cstdio>

#include "linklist.h"


int main(int argc, char** argv)
{
	LinkHeader* header1 = create_linklist();
	LinkHeader* header2 = create_linklist();

	int ret1 = free_linklist(header1, NULL);
	int ret2 = free_linklist(header2, NULL);

	printf("ret1: %d ret2: %d\n", ret1, ret2);

	int pause;
	scanf("%d",&pause);
}