#include <iostream>
#include "swap.h"

using namespace std;
int main() {
	int arr[3][3] = { 100,100,100,90,50,100,60,70,80 };
	cout << "�����ĳɼ�Ϊ��" << arr[0][0] + arr[0][1] + arr[0][2] << endl;
	cout << "���ĵĳɼ�Ϊ��" << arr[1][0] + arr[1][1] + arr[1][2] << endl;
	cout << "����ĳɼ�Ϊ��" << arr[2][0] + arr[2][1] + arr[2][2] << endl;

	swap(1, 2);
	return 0;
}