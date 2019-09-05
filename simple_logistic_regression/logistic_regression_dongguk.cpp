#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <Windows.h>

struct MyData
{
	float size, price;
};

class LinearHypothesis //linear regression
{
public:
	// y = ax + b;
	float a, b;

	LinearHypothesis() {
		a = 0.0;
		b = 0.0;
	}

	float getY(const float& x)
	{
		return a*x + b;
	}
};

int main() {
	using namespace std;

	vector<MyData> size_price_data;
	size_price_data.reserve(1000);

	/*vector < tuple<float, float> >size_price_data;
	get<0>(size_price_data[0]);
	get<1>(size_price_data[0]);*/

	ifstream fin;
	fin.open("size_price_examples.txt", ios::in);

	float size, price;

	while (!fin.eof()) {
		MyData read_data;
		fin >> read_data.size >> read_data.price;

		size_price_data.push_back(read_data);
	}

	//for(int i = 0; i < size_price_data.size(); ++i)
	for (const auto& itr : size_price_data) {
		cout << itr.size << " " << itr.price << endl;

	}

	LinearHypothesis my_hypothesis;
	for (int itr = 0; itr < 1000; ++itr) {
		const float size_from_data = size_price_data[0].size;
		const float price_from_hypo = my_hypothesis.getY(size_from_data);

		const float error_before = size_price_data[0].price - price_from_hypo;

		const float de_da = -size_from_data;
		const float de_db = -1.0;

		const float learning_rate = 0.01;

		const float error_after = size_price_data[0].price - my_hypothesis.getY(size_from_data);

		my_hypothesis.a = my_hypothesis.a - de_da * learning_rate;
		my_hypothesis.b = my_hypothesis.b - de_db * learning_rate;

		if (itr % 100 == 0) {
			cout << error_before << " " << error_after << endl;
			cout << size_from_data << " " << my_hypothesis.getY(size_from_data) << endl;
		}
	}
	system("pause");
	return 0;
}