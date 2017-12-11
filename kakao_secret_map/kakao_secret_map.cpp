#include <iostream>
#include <string>

using namespace std;

void convert_two(int num, int** arr, int cnt, int size) {
	int ans = 0, index = 0;
	for (int i = 1; i <= size; i++) {
		int binary = num % 2;
		if (num != NULL)
			arr[cnt][size - i] = binary;
		else
			arr[cnt][size - i] = 0;
		num /= 2;
	}
};

void merge_map(int** arr1, int** arr2, string** ans, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			if (arr1[i][j] || arr2[i][j] == 1)
				ans[i][j] = '#';
			else
				ans[i][j] = ' ';
	}
};


void main() {
	int arr_size, temp, cnt = 0;
	cin >> arr_size;

	int *input1 = new int[arr_size];
	int *input2 = new int[arr_size];

	int **arr1 = new int*[arr_size];
	int **arr2 = new int*[arr_size];
	string **ans = new string*[arr_size];


	for (int i = 0; i < arr_size; ++i) {
		arr1[i] = new int[arr_size];
		arr2[i] = new int[arr_size];
		ans[i] = new string[arr_size];

	}
	string *new_arr1 = new string[arr_size];
	string *new_arr2 = new string[arr_size];

	for (int i = 0; i < arr_size; i++) {
		cin >> temp;
		input1[i] = temp;
	}

	for (int i = 0; i < arr_size; i++) {
		cin >> temp;
		input2[i] = temp;
	}
	for (int i = 0; i < arr_size; i++) {
		convert_two(input1[i], arr1, cnt, arr_size);
		convert_two(input2[i], arr2, cnt, arr_size);
		cnt++;
	}

	merge_map(arr1, arr2, ans, arr_size);

	for (int i = 0; i < arr_size; i++) {
		for (int j = 0; j < arr_size; j++)
			cout << ans[i][j] << ' ';
		printf("\n");
	}


	system("pause");
}

//Using shift operators
//
//#include <iostream>
//#include <bitset>
//#include <string>
//
//using namespace std;
//
//void Buildarray(string* arr, int size) {
//	for (int i = 0; i < size; i++) {
//		unsigned int temp;
//		cin >> temp;
//		bitset<16> bitset{ temp << (16 - size) };
//		arr[i] = bitset.to_string();
//	}
//}
//
//void main()
//{
//	int map_size;
//	cin >> map_size;
//
//	string* array1 = new string[map_size];
//	string* array2 = new string[map_size];
//
//	Buildarray(array1, map_size);
//	Buildarray(array2, map_size);
//
//	for (int i = 0; i < map_size; i++) {
//		for (int j = 0; j < map_size; j++) {
//			if (array1[i].at(j) - 48 || array2[i].at(j) - 48 == 1)
//				cout << "#";
//			else
//				cout << " ";
//		}
//		cout << endl;
//	}
//	system("pause");
//}


