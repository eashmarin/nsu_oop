#include "ConfExecutor.h"

int main(int argc, char **argv) {
	string fileName = "workflow.txt";
	if (argc > 1)
		fileName = argv[1];

	ConfExecutor exec(fileName);
	exec.execute();

	return 0;
}