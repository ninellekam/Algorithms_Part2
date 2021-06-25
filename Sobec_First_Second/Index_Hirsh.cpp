#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


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
        sort(citations.begin(), citations.end());
        size_t len = citations.size(), i = 0;
        int answer = i;

	    for (i = 0; i < len; ++i) {
		    if (citations[i] > i) {
                break;
            }
            else {
                answer = std::min<int>(i, citations[i]);
            }
	    }
        if (i == len)
            return answer;
	    return i + 1;
    }

int main() {
	std::vector <int> vec = {1, 3, 1};
	std::cout << hIndex(vec);
}
