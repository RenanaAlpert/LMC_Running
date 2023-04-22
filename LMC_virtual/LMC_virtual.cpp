#include <algorithm>
#include <array>
#include "Lmc.h"

const short BINARY[] = {
901,
399,
901,
199,
902,
0
};

const short SIMPLEST_PROGRAM[] = {
0
};

int main()
{
	experis::Memory memory{};
	std::copy(BINARY, SIMPLEST_PROGRAM + (sizeof(SIMPLEST_PROGRAM) / sizeof(*SIMPLEST_PROGRAM)), memory.begin());

	experis::Lmc lmc{};
	lmc.Execute(memory);
}