#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
void three_max(T &num1, T &num2, T &num3) {
	num1 = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
	num2 = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
	num3 = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
}
template <typename T>
void fill_arr(T arr[], const int length) {
	srand(time(0));
	for (int i = 0; i < length; i++)
		arr[i] = rand()%21-10;
}
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}
template <typename T>
T &neg_arr(T arr[], const int length) {
	for (int i = 0; i < length; i++)
		if (arr[i] < 0)
			return arr[i];
	return arr[0];
}
template <typename T>
void change_arr(T arr1[], const int length1, T arr2[], const int length2) {
	for (int i = 0; i < length2; i++)
		for (int j = 0; j < length1; j++)
			if (*(arr2+i) == *(arr1+j))
				*(arr2+i) = 0;
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n1, n2, n3;
	
	cout << "Домашнее задание №23.\n\nЗадача №1.\nВведите три числа: ";
	cin >> n1 >> n2 >> n3;
	three_max(n1, n2, n3);
	cout << n1 << " " << n2 << " " << n3 << "\n\n";

	cout << "Задача №2.\n";
	const int size = 10;
	int arr[size];
	cout << "Массив: \n";
	fill_arr(arr, size);
	show_arr(arr, size);
	if(neg_arr(arr,size)<0)
		cout << "Первый отрицательный элемент = " << neg_arr(arr, size) << ".\n\n";
	else 
		cout << "Отрицательных элементов нет. Первый элемент = " << neg_arr(arr, size) << ".\n\n";

	cout << "Задача №3.\n";
	const int siz = 7;
	int arr1[siz]{2, 7, 3, 5, 7, 8, 1};
	int arr2[siz]{5, 4, 9, 1, 6, 3, 6};
	cout << "Первый массив: \n";
	show_arr(arr1, siz);
	cout << "Второй массив: \n";
	show_arr(arr2, siz);
	cout << "Второй массив после вызова функции: \n";
	change_arr(arr1, siz, arr2, siz);
	show_arr(arr2, siz);
	cout << endl; 

	return 0;
}