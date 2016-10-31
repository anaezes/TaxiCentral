#pragma once

#include <stdlib.h>

#define ALTURA_ECRA 24

#define TAB_BIG "          "
#define TAB "   "


void clearScreen()
{

	if (system("CLS"))
		system("clear");
}
