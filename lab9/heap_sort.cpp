#include <iostream>

void heap_sort(int *arr, int size);
void build_max_heap(int *arr, int size);
void max_heapify(int *arr, int pos, int size);

void heap_sort(int *arr, int size) {
	build_max_heap(arr, size);

	for (int i = size; i > 0; i--) {
		std::swap(arr[0], arr[i - 1]);
		max_heapify(arr, 0, i - 1);
	}
}

void build_max_heap(int *arr, int size) {
	for (int i = size - 1; i >= 0; i--) {
		max_heapify(arr, i, size);
	}
}

void max_heapify(int *arr, int pos, int size) {
	if (2 * pos < size) {
		int swap = pos;
		int left_child = pos * 2 + 1;
		int right_child = pos * 2 + 2;

		if (left_child < size && arr[left_child] > arr[swap]) {
			swap = left_child;
		}
		if (right_child < size && arr[right_child] > arr[swap]) {
			swap = right_child;
		}

		if (swap == pos) {
			return;
		}

		std::swap(arr[pos], arr[swap]);

		max_heapify(arr, swap, size);
	}
	else {
		return;
	}
}

int main() {
	size_t n = 13;
	int arr[] = { 2, 5, 1, 55, 19, 12, -9, -8, -22, 23, 9, 3, 4 };
	heap_sort(arr, n);

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ", ";
	}
}
