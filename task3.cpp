/*Реализовать задание из пункта 1 методом обратного поиска – от целевого состояния к начальному. Сравнить эффективность.*/

/*
Enter A
1
Enter B
1000000
1000000 500000 250000 125000 62500 31250 15625 15622 7811 7808 3904 1952 976 488
244 122 61 58 29 26 13 10 7 4 1 Count of operations :24
Total time:0 sec.
Для продолжения нажмите любую клавишу . . ..
*/

//Обратный поиск работает быстрее, в прямом это заняло 2 секунды. На бОльших количествах сравнений с прямым, обратный срабатывал моментально.

#include <iostream>
#include <deque>
#include <utility>
#include <ctime>
#include <vector>

using namespace std;

vector<int> v;

int main() {
	int b = 2;
	int a = 100;

	//Ввод пользовательских A и B
	cout << "Enter A" << endl;
	cin >> a;
	cout << "Enter B" << endl;
	cin >> b;

	deque<pair<int, size_t>> deq;

	int i = 0;
	int count = 0;
	deq.push_back(pair<int, size_t>(b, 0));

	unsigned int start_time = clock();

	while (deq[i].first != a)
	{
		deq.push_back(pair<int, size_t>(deq[i].first - 3, i));
		if (deq[i].first % 2 == 0)
		deq.push_back(pair<int, size_t>(deq[i].first / 2, i));
		//deq.push_back(pair<int, size_t>(deq[i].first - 2, i));
		++i;
	}

	unsigned int end_time = clock();


	while (i)
	{
		v.push_back(deq[i].first);
		i = deq[i].second;
		++count;
	}

	v.push_back(deq[i].first);

	////Обычный вывод
	//for (int i = v.size() - 1; i >= 0; i--) {
	//	cout << v[i] << ' ';
	//}

	//Вывод с операциями
	for (int i = v.size() - 1; i > 0; i--)
	{
		int next = v[i - 1];
		cout << v[i] << ' ';
		//i = deq[i].second;
		++count;
		if (next - v[i] == 3) cout << " (+3) ";
		else if (next - v[i] == -2) cout << " (-2) ";
		else if ((next - v[i]) == v[i]) cout << " (*2) ";
	}
	cout << v[0] << endl;


	//cout << deq[i].first << endl;
	cout << "Count of operations :" << count << endl;
	cout << "Total time:" << (end_time - start_time) / 1000 << " sec." << endl;

	system("pause");
}