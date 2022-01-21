#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <utility>


using namespace std;

// Предварительное объявление шаблонных функций
template <typename First, typename Second >pair <First, Second > operator * (	const pair <First, Second >& p1,
																				const pair <First, Second >& p2);
template <typename T>vector<T> operator * (const vector<T>& one, const vector<T>& two);
template <typename Key, typename Value>map<Key, Value> operator * (	const map<Key, Value>& one, 
																	const map<Key, Value>& two);
template<typename T> T Sqr(T x);



template <typename First, typename Second >
// т.к. умножение для пар не определено, вручную определим оператор умножения для пар:
pair <First, Second > operator * (	const pair <First, Second >& p1,
									const pair <First, Second >& p2) {
	// мы можем создавать переменные шаблонного типа
	First f = p1.first * p2.first;
	Second s = p1.second * p2.second;
	return { f, s };
}


template <typename T>
vector<T> operator * (const vector<T>& one, const vector<T>& two) {
	vector<T> s;
	for (size_t i = 0; i < one.size(); i++) {
		s.push_back(one[i] * two[i]);
	}
	return s;
}

template <typename Key, typename Value>
map<Key, Value> operator * (const map<Key, Value>& one, const map<Key, Value>& two) {
	map<Key, Value> s;
	for (const auto& i : one) {
		s[i.first] = i.second * i.second;
	}
	return s;
}

template <typename T> // ключевое слово для объявления типа T
T Sqr(T x) {
	return x * x; // нам нужно, чтобы элемент x поддерживал операцию умножения
}



int main() {
	/*
	vector<vector<int>> s{ {1,2,3}, {10,20,30} };
	for (auto x : Sqr(s)) {
		for (auto y : x) {
			cout << ' ' << y;
		}
		cout << endl;
	}
	*/

	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;


	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}

}
