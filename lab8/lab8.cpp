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

vector<bool> f2(vector<bool> w1, vector<bool> w2)
{
	vector<bool> result;
	for (int i = 0; i < 16; i++)
	{
		result.push_back(w1[i] * !w2[i]);
	}
	return result;
}
vector<bool> f7(vector<bool> w1, vector<bool> w2)
{
	vector<bool> result;
	for (int i = 0; i < 16; i++)
	{
		result.push_back(w1[i] || w2[i]);
	}
	return result;
}

vector<bool> f8(vector<bool> w1, vector<bool> w2)
{
	vector<bool> result;
	for (int i = 0; i < 16; i++)
	{
		result.push_back(!(w1[i] || w2[i]));
	}
	return result;
}
vector<bool> f13(vector<bool> w1, vector<bool> w2)
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
	print(f2(matrix[0], matrix[1]));
	cout << "\nf7 between 4 and 5:";
	print(f7(matrix[3], matrix[4]));
	cout << "\nf8 between 7 and 8:";
	print(f8(matrix[6], matrix[7]));
	cout << "\nf13 between 10 and 11:";
	print(f13(matrix[9], matrix[10]));
	cout << "\n\nInterval between ";
	print(bot);
	cout << "and ";
	print(top);
	cout << "\n";
	print(interval(matrix, bot, top));
}
