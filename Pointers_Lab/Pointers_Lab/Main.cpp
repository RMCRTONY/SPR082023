#include <iostream>
#include <vector>
#include "TriangleHeap.h"
#include "TriangleStack.h"

int AddNumbersReturnInt(int* a, int* b);
void AddNumbersReturnVoid(int a, int b, int* sum);
void SwapValues(int* a, int* b);

int main() {

	//MEMORY LEAK DETECTOR CODE (goes at the beginning of main):
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtSetBreakAlloc(-1); //set block for memory leak (-1) runs as normal
	_CrtDumpMemoryLeaks();



	TriangleStack st1;
	TriangleStack st2;

	st1.SetBase(5);
	st1.SetHeight(3);
	st2.SetBase(10);
	st2.SetHeight(15);

	std::vector<TriangleStack> stacks;
	stacks.push_back(st1);
	stacks.push_back(st2);

	TriangleHeap ht1;
	TriangleHeap ht2;

	ht1.SetBase(5);
	ht1.SetHeight(3);
	ht2.SetBase(10);
	ht2.SetHeight(15);

	std::vector<TriangleHeap> heaps;
	heaps.push_back(ht1);
	heaps.push_back(ht2);

	std::cout << "\tStacks:\n";

	for (int i = 0; i < stacks.size(); i++) {
		std::cout << i << ": " << stacks[i].GetArea() << std::endl;
	}

	std::cout << "\tHeaps:\n";

	for (int j = 0; j < heaps.size(); j++) {
		std::cout << j << ": " << heaps[j].GetArea() << std::endl;
	}

}

int AddNumbersReturnInt(int* a, int* b) {
	return *a + *b;
}

void AddNumbersReturnVoid(int a, int b, int* sum) {
	*sum = a + b;
}

void SwapValues(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}