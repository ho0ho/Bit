#include <stdio.h>
#include "tag.h"

int main() {

	TAG rlt;
	rlt = put(10, 5);
	printf("%d\n", rlt.fir, rlt.sec);
}