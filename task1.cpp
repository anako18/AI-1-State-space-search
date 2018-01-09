/*���� ��� ����� ����� � ��������, 2 � 100, � ����� ��� �������� � ���������� 3� � ��������� �� 2�.
����� ����������� ������������������ ��������, ����������� �������� �� ������� ����� ������. - BFS*/

/*�� �� �����, ��� � � ������ 1, ������ ����������� �������� �������� 2�.*/


//������ 1 �������, ��� ��������� � 3:
/*
Enter A
1
Enter B
1000000
1 4 7 10 13 26 29 58 61 122 244 488 976 1952 3904 7808 7811 15622 15625 31250 62
500 125000 250000 500000 1000000
Count of operations :24
Total time:1 sec.
��� ����������� ������� ����� ������� . . .
*/


#include <iostream>
#include <deque>
#include <utility>
#include <ctime>
#include <vector>

using namespace std;
vector<int> v;


int main() {
	int a = 2;
	int b = 100;

	//���� ���������������� A � B
	cout << "Enter A" << endl;
	cin >> a;
	cout << "Enter B" << endl;
	cin >> b;

	deque<pair<int, size_t>> deq;

	int i = 0;
	int count = 0;
	deq.push_back(pair<int, size_t>(a, 0));
	
	unsigned int start_time = clock();

	while (deq[i].first != b)
	{
		deq.push_back(pair<int, size_t>(deq[i].first + 3, i));
		deq.push_back(pair<int, size_t>(deq[i].first * 2, i));
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

	////������� �����
	//for (int i = v.size() - 1; i >= 0; i--) {
	//	cout << v[i] << ' ';
	//}

	//����� � ����������
	for (int i = v.size() - 1; i > 0; i--) 
	{
		int next = v[i-1];
		cout << v[i] << ' ';
		//i = deq[i].second;
		++count;
		if (next - v[i] == 3) cout << " (+3) ";
		else if (next - v[i] == -2) cout << " (-2) ";
		else if ((next - v[i]) == v[i]) cout << " (*2) ";
	}
	cout << v[0] << endl;


	cout << endl << "Count of operations :" << count << endl;
	cout << "Total time:" << (end_time - start_time)/1000 << " sec." << endl;
	
	system("pause");
}