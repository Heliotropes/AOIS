#include <vector>
#include <iostream>

using namespace std;

bool dict[16] = {0,1,0,0,1,0,0,0,1,1,1,1,0,1,0,1};

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

vector <bool> add(vector <bool> a, vector <bool> b)
{
	vector <bool> res;
	bool trans = false;
	for (size_t i = a.size(); i > 0; i--)
	{

		if (a[i - 1] == 0 && b[i - 1] == 0 && !trans)
		{
			res.emplace(res.begin(), 0);
			trans = false;
		}
		else if (a[i - 1] == 0 && b[i - 1] == 0 && trans)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (a[i - 1] == 1 && b[i - 1] == 0 && !trans)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (a[i - 1] == 1 && b[i - 1] == 0 && trans)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (a[i - 1] == 0 && b[i - 1] == 1 && !trans)
		{
			res.emplace(res.begin(), 1);
			trans = false;
		}
		else if (a[i - 1] == 0 && b[i - 1] == 1 && trans)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (a[i - 1] == 1 && b[i - 1] == 1 && !trans)
		{
			res.emplace(res.begin(), 0);
			trans = true;
		}
		else if (a[i - 1] == 1 && b[i - 1] == 1 && trans)
		{
			res.emplace(res.begin(), 1);
			trans = true;
		}
	}
	return res;
}

vector <vector<char>> Bonding(vector <vector<char>> original)
{
	vector <vector<char>> result;
	vector<char > part_of_result;
	for (int i = 0; i < original.size(); ++i) {
		for (int j = i + 1; j < original.size(); ++j)
		{
			part_of_result.clear();
			int fits = 0;
			if (original[i][0] == original[j][0]) {
				++fits;
				part_of_result.push_back(original[j][0]);
			}
			if (original[i][1] == original[j][1]) {
				++fits;
				part_of_result.push_back(original[j][1]);
			}
			if (original[i][2] == original[j][2]) {
				++fits;
				part_of_result.push_back(original[j][2]);
			}
			if (fits == 2) {
				result.push_back(part_of_result);
			}
		}
	}
	if (result.empty())
		for (int i = 0; i < original.size(); ++i)
			result.push_back(original[i]);
	return result;
}

bool CheckInt(int number, vector <int> met)
{
	for (int i = 0; i < met.size(); ++i)
		if (number == met[i]) return 1;
	return 0;
}

int position(char symbol)
{
	for (int i = 0; i < 16; ++i)
		if (symbol == dict[i]) return i;
	return -1;
}

vector <vector<char>> Bonding2(vector <vector<char>> original)
{
	vector <vector<char>> result;
	vector<char > part_of_result;
	vector <int> met;
	for (int i = 0; i < original.size(); ++i) {
		bool fits = 0;
		if (CheckInt(i, met)) continue;
		for (int j = i + 1; j < original.size(); ++j)
		{
			if (original[i][0] == original[j][0])
				if (abs(position(original[i][1]) - position(original[j][1])) == 3) {
					part_of_result.push_back(original[j][0]);
					result.push_back(part_of_result);
					part_of_result.clear();
					fits = 1;
					met.push_back(j);
				}
			if (original[i][0] == original[j][1])
				if (abs(position(original[i][1]) - position(original[j][0])) == 3) {
					part_of_result.push_back(original[j][1]);
					result.push_back(part_of_result);
					part_of_result.clear();
					fits = 1;
					met.push_back(j);
				}
			if (original[i][1] == original[j][0])
				if (abs(position(original[i][0]) - position(original[j][1])) == 3) {
					part_of_result.push_back(original[j][0]);
					result.push_back(part_of_result);
					part_of_result.clear();
					fits = 1;
					met.push_back(j);
				}
			if (original[i][1] == original[j][1])
				if (abs(position(original[i][0]) - position(original[j][0])) == 3) {
					part_of_result.push_back(original[j][1]);
					result.push_back(part_of_result);
					part_of_result.clear();
					fits = 1;
					met.push_back(j);
				}
		}
		if (!fits) result.push_back(original[i]);
	}
	return result;
}

vector <vector<char>> CheckRepeat(vector <vector<char>> original)
{
		for (int i = 0; i < original.size(); ++i)
			for (int j = i + 1; j < original.size(); ++j)
				if (original[i] == original[j]) original.erase(original.begin() + j);
		return original;
}

vector <vector <bool>> interval(vector<vector<bool>> matr, vector<bool> val1, vector<bool> val2)
{
	vector<vector<bool>> list;
	for (int i = 0; i < matr.size(); ++i)
		if (matr[i] > val1 && matr[i] < val2) list.push_back(matr[i]);
	return list;
}

vector <vector <bool>> to_diagonal(vector<vector<bool>> matr)
{
	vector<vector<bool>> list = matr;
	for (int i = 0; i < 16; i++)
	{
		int k = i;
		int j = 0;
		while (j < 16)
		{
			if (k >= 16) k -= 16;
			list[k][j] = matr[i][j];
			++k;
			++j;
		}
	}
	return list;
}

vector <vector <bool>> sum_of_fields(vector<vector<bool>> matr, vector<bool> marker)
{
	vector<vector<bool>> list = matr;
	for (int i = 0; i < 16; i++)
		if (list[i][0] == marker[0] && list[i][1] == marker[1] && list[i][2] == marker[2])
		{
			vector <bool> A;
			vector <bool> B;
			vector <bool> S;
			for (int k = 3; k < 7; k++)
				A.push_back(list[i][k]);
			A.emplace(A.begin(), 0);
			for (int k = 7; k < 11; k++)
				B.push_back(list[i][k]);
			B.emplace(B.begin(), 0);
			for (int k = 11; k < 15; k++)
				S.push_back(list[i][k]);
			S = add(A, B);
			for (int k = 11; k < 15; k++)
				list[i][k] = S[k - 11];
		}
	
	return list;
}

vector<bool> function2(vector<bool> w1, vector<bool> w2)
{
	vector<bool> result;
	for (int i = 0; i < 16; i++)
	{
		result.push_back(w1[i] * !w2[i]);
	}
	return result;
}
vector<bool> function7(vector<bool> w1, vector<bool> w2)
{
	vector<bool> result;
	for (int i = 0; i < 16; i++)
	{
		result.push_back(w1[i] || w2[i]);
	}
	return result;
}

vector<bool> function8(vector<bool> w1, vector<bool> w2)
{
	vector<bool> result;
	for (int i = 0; i < 16; i++)
	{
		result.push_back(!(w1[i] || w2[i]));
	}
	return result;
}
vector<bool> function13(vector<bool> w1, vector<bool> w2)
{
	vector<bool> result;
	for (int i = 0; i < 16; i++)
	{
		result.push_back(!w1[i] || w2[i]);
	}
	return result;
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
	int digits[16] = { 232, 125, 1789, 999, 23191,44444, 70, 879, 9340, 11111, 5555, 234, 78, 18901, 4333, 13131 };
	vector<vector<bool>> matrix;
	for (int i = 0; i < 16; ++i)
		matrix.push_back(to_binary(digits[i]));
	vector<bool> bot = to_binary(3472);
	vector<bool> top = to_binary(25000);
	cout << "default:\n";
	print(matrix);
	cout << "\n\nDiagonal:\n";
	vector<vector<bool>> diagonal = to_diagonal(matrix);
	print(diagonal);
	cout << "\n\nSum of A and B in words with V = 1,0,1:\n";
	vector<vector<bool>> sum = sum_of_fields(matrix, {1,0,1});
	print(sum);
	cout << "\nf2 between 1 and 2:";
	print(function2(matrix[0], matrix[1]));
	cout << "\nf7 between 4 and 5:";
	print(function7(matrix[3], matrix[4]));
	cout << "\nf8 between 7 and 8:";
	print(function8(matrix[6], matrix[7]));
	cout << "\nf13 between 10 and 11:";
	print(function13(matrix[9], matrix[10]));
	cout << "\n\nInterval between ";
	print(bot);
	cout << "and ";
	print(top);
	cout << "\n";
	print(interval(matrix, bot, top));
}
