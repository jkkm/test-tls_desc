#include <string.h>
__thread struct { char c[512]; } TMP;
void *TMPfunc(void)
{
	return &TMP;
}
