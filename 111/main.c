#include <stdio.h>
#include "left.h"
#include "right.h"


int main() {
	int withdraw;
	set_bank();
	withdraw = get_bank();
	printf("%n", withdraw);

	return 0;
}