// Дан отсортированный массив целых чисел а, целое число К и индекс элемента index
// Вернуть ближайших К чисел массива, к а[index]
// (задача проще, чем та, где заккоментировано)

#include <iostream>
#include <vector>
#include <algorithm>

// int findCrossOver(std::vector<int> & arr, int low, int high, int x) {
// 	if (arr[high] <= x)
// 		return high;
// 	if (arr[low] > x)
// 		return low;

// 	int mid = (low + high) / 2;

// 	if (arr[mid] <= x && arr[mid+1] > x)
// 		return mid;

// 	if(arr[mid] < x)
// 		return findCrossOver(arr, mid + 1, high, x);

// 	return findCrossOver(arr, low, mid - 1, x);
// }


void printKclosest(std::vector<int> & arr, int x, int k, int len) {
	// int l = findCrossOver(arr, 0, len - 1, x);
	int l = k;
	int r = l + 1;
	int count = 0;

	if (arr[l] == x)
		l--;

	while (l >= 0 && r < len && count < k) {
		if (x - arr[l] < arr[r] - x)
			printf("%d ", arr[l--]);
		else
			printf("%d ", arr[r++]);
		count++;
	}

	while (count < k && l >= 0)
		printf("%d ", arr[l--]), count++;

	while (count < k && r < len)
		printf("%d ", arr[r++]), count++;
}

int main() {
	std::vector<int> vec = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
	int x = 35, k = 4;
	printKclosest(vec, vec[k], 4, vec.size());
	return 0;
}