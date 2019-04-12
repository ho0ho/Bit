#include <stdio.h>

#include "nocommon.h"
#include "nodup.h"

int main() {
	TAG2 rlt;
	rlt = put(10, 5);
	printf("%d %d\n", rlt.fir, rlt.sec);
	puts("\n== 7 ==");
}