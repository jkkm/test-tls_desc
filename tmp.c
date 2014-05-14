#include <string.h>
__thread struct { char c[TLSSZ]; } TMP;
void *TMPfunc(void)
{
	return &TMP;
}
