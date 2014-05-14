#!/bin/sh

# how many dlopen's
MAX=16
# tls space consumed
SZ=128

# gnu, gnu2, desc, trad
DIALECT="trad"
CFLAGS="-mtls-dialect=$DIALECT -DTLSSZ=$SZ"
LDFLAGS="-fPIC -shared"
GDFLAGS="-ftls-model=global-dynamic"
IEFLAGS="-ftls-model=initial-exec"

for i in $(seq 1 $[$MAX - 1]); do cp tmp.c tmp$i.c; sed -e s\!TMP\!TMP$i\!g -i tmp$i.c; gcc $CFLAGS $LDFLAGS $GDFLAGS -o tmp$i.so tmp$i.c; done
cp tmp.c tmp$MAX.c; sed -e s\!TMP\!TMP$MAX\!g -i tmp$MAX.c; gcc $CFLAGS $LDFLAGS $IEFLAGS -o tmp$MAX.so tmp$MAX.c;

gcc -pie -fPIC -o main main.c -ldl -DMAX=$MAX
