#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>


// Индекс Хирша вычисляется по специальной формуле: он равен N, если N работ автора процитировали N и более раз.
// То есть если 10 работ автора процитировали 10 раз,
// то и индекс Хирша будет равен 10
// (если работ будет 11, но каждую из них процитируют по 10 раз,
// то индекс все равно будет равен 10).
// Чтобы посчитать свой Хирш самостоятельно,
// достаточно отсортировать публикации по цитируемости и,
// двигаясь по порядку, дойти до последней публикации в списке,
// у которой цитируемость будет выше ее порядкового номера.
// Порядковый номер этой публикации и будет равняться индексу Хирша.

int hIndex(std::vector<int>& citations) {
	std::unordered_map <int, int> buckets;
	size_t len = citations.size(), sum = 0;

	for(size_t i = 0; i < len; ++i)
		++buckets[std::min<int>(citations[i], len)];

	for(size_t i = len; i >= 0; --i) {
		sum += buckets[i];
		if (sum > i)
			return i;
	}
	return 0;
}

int main() {
	std::vector <int> vec = {1, 3, 1};
	std::cout << hIndex(vec);
}
