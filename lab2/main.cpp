#include "ConfParser.h"

int main() {
	ConfParser parser("workflow.txt");
	parser.parse();
	return 0;
}