#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef MAX
#error set MAX in test-tls_desc.sh
#endif

int main(int argc, char *argv[])
{
	int i;
	char *c;
	void *v, *p;
	for (i = 1; i <= MAX - 1; i++) {
		asprintf(&c, "./tmp%d.so", i);
		v = dlopen(c, RTLD_NOW);
		if (!v) { printf("%s\n", dlerror()); abort(); }
		asprintf(&c, "TMP%d", i);
		p = dlsym(v, c);
	}
	asprintf(&c, "TMP%d", MAX);
	v = dlopen(c, RTLD_NOW);
	if (!v) { printf("%s\n", dlerror()); abort(); }
	asprintf(&c, "TMP%d", MAX);
	p = dlsym(v, c);
	return 0;
}
