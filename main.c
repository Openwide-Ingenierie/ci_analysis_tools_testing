#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

/* FD Leak */
static void fd_leak() {
	int fd = open("/dev/random", O_RDONLY);

	printf("Running %s\n", __FUNCTION__);
	(void)fd;
	printf("Running %s done!\n", __FUNCTION__);
}

/* Use after free */
static void memory_leak(char* bar) {
	char* c = malloc(16*sizeof(char));

	printf("Running %s\n", __FUNCTION__);
	memset(c, 0, sizeof(16*sizeof(char)));
	strcpy(c, bar);
	printf("Running %s done!\n", __FUNCTION__);
}

/* Use after free */
static void use_after_free(char* bar) {
	char* c = malloc(16*sizeof(char));

	printf("Running %s\n", __FUNCTION__);
	memset(c, 0, sizeof(16*sizeof(char)));
	free(c);
	strcpy(c, bar);
	printf("Running %s done!\n", __FUNCTION__);
}

/* Heap corruption */
static void heap_overflow(char* bar) {
	char* c = malloc(16*sizeof(char));

	printf("Running %s\n", __FUNCTION__);
	memset(c, 0, sizeof(16*sizeof(char)));
	strcpy(c, bar);
	free(c);
	printf("Running %s done!\n", __FUNCTION__);
}

/* Stack corruption */
static void stack_smashing(char* bar) {
	char c[12];

	printf("Running %s\n", __FUNCTION__);
	strcpy(c, bar);
	printf("Running %s done!\n", __FUNCTION__);
}

int main(int argc, char** argv) {
	//Supress the "unused parameter" warning
	(void)argc;
	stack_smashing(argv[1]);
	heap_overflow(argv[1]);
	use_after_free(argv[1]);
	memory_leak(argv[1]);
	fd_leak();
	printf("All done !\n");
	return 0;
}

