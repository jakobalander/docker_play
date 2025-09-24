#include <iostream>
#include <source_location>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	std::cout << std::source_location::current().file_name() << "\n";
	const size_t num_allocs = 10 * 1024 * 1024;
	char* p = static_cast<char*>(malloc(num_allocs));
	if (p == nullptr) {
		std::cout << "allocation failed\n";
		return -1;
	}
	memset(p, 'A', num_allocs);
	std::cout << "done memsetting\n";
	sleep(1000);
	free(p);
}
