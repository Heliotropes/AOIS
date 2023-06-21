#include <vector>
#include <iostream>

using namespace std;

vector <bool> to_binary(int num)
{
	vector <bool> res;
	int size;
	int num_;
	num_ = abs(num);
	while (num_)
	{
		res.emplace(res.begin(), num_ % 2);
		num_ /= 2;
	}
	size = res.size();
	for (size_t i = 0; i < 16 - size; i++)
	{
		res.emplace(res.begin(), 0);
	}
	return res;
}

vector <bool> nearest_from_top(vector<vector<bool>> matr, vector<bool> val)
{
	vector <bool> min;
	vector<vector<bool>> top_list;
	for (int i = 0; i < matr.size(); ++i)
		if (matr[i] > val) top_list.push_back(matr[i]);
	if (!top_list.empty())
	{
		min = top_list[0];
		for (int i = 0; i < top_list.size(); ++i)
			if (top_list[i] < min) min = top_list[i];
	}
	return min;
}
vector <bool> nearest_from_bot(vector<vector<bool>> matr, vector<bool> val)
{
	vector <bool> max;
	vector<vector<bool>> bot_list;
	for (int i = 0; i < matr.size(); ++i)
		if (matr[i] < val) bot_list.push_back(matr[i]);
	if (!bot_list.empty())
	{
		max = bot_list[0];
		for (int i = 0; i < bot_list.size(); ++i)
			if (bot_list[i] > max) max = bot_list[i];
	}
	return max;
}

vector <vector <bool>> interval(vector<vector<bool>> matr, vector<bool> val1, vector<bool> val2)
{
	vector<vector<bool>> list;
	for (int i = 0; i < matr.size(); ++i)
		if (matr[i] > val1 && matr[i] < val2) list.push_back(matr[i]);
	return list;
}
void print(vector<vector<bool>> matr)
{
	for (int i = 0; i < matr.size(); ++i)
	{
		for (int j = 0; j < matr[i].size(); ++j)
			cout << matr[i][j] << " ";
		cout << "\n";
	}
}
void print(vector<bool> matr)
{
	for (int i = 0; i < matr.size(); ++i)
			cout << matr[i] << " ";
}

int main()
{
	int digits[10] = { 232, 125, 1789, 999, 23191,44444, 70, 879, 9340, 11111 };
	vector<vector<bool>> matrix;
	for (int i = 0; i < 10; ++i)
		matrix.push_back(to_binary(digits[i]));
	vector<bool> bot = to_binary(3472);
	vector<bool> top = to_binary(25000);
	vector<bool> value = to_binary(10000);
	print(matrix);
	cout << "\n\nInterval between ";
	print(bot);
	cout << "and ";
	print(top);
	cout << "\n";
	print(interval(matrix, bot, top));
	cout << "\n\n\nNearest to ";
	print(value);
	cout << "\nfrom top: ";
	print(nearest_from_top(matrix, value));
	cout << "\nfrom bot: ";
	print(nearest_from_bot(matrix, value));
}

	
