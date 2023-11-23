#include<iostream>
#include<vector>
using namespace std;

void adjust(vector<int> &arr, int len, int index)
{
	int left = 2 * index + 1; // index�����ӽڵ�
	int right = 2 * index + 2;// index�����ӽڵ�

	int max = index;
	if (left<len && arr[left] > arr[max]) {
		max = left;
	}
	if (right<len && arr[right] > arr[max]) {
		max = right;
	}

	if (max != index)
	{
		swap(arr[max], arr[index]);
		adjust(arr, len, max);
	}

}

// ������
void heapSort(vector<int>& arr, int size)
{
	// ��������ѣ������һ����Ҷ�ӽڵ����ϣ�
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		adjust(arr, size, i);
	}

	// ���������
	for (int i = size - 1; i >= 1; i--)
	{
		swap(arr[0], arr[i]);           // ����ǰ���ķ��õ�����ĩβ
		adjust(arr, i, 0);              // ��δ�������Ĳ��ּ������ж�����
	}
}

int main()
{
	vector<int> arr = { 8,6,7,4,100,108,2,1 };
	heapSort(arr, arr.size());
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
	return 0;
}
