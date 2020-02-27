#pragma once

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "terminal.h"

void ask(char question[], char output[]) {
	printf("%s", question);

	scanf_s("%s", output, 256);
}
