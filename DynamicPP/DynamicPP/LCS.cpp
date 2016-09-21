#include <iostream>
#include <vector>
#include <string>
void print(char(*construct)[100], std::vector<char> X, int i, int j)
{
	if ((i == 0) || (j == 0))
		return;
	if (construct[i][j] == 'd')
	{
		print(construct, X, i - 1, j - 1);
		std::cout << X[i - 1];
	}
	else
	{
		if (construct[i][j] == 'u')
			print(construct, X, i - 1, j);
		else
			print(construct, X, i, j - 1);
	}
}
void main()
{
	std::string X("");
	std::string Y("");
	std::vector<char> X_vector, Y_vector;
	int i, j;
	std::cout << "Input X: ";
	std::getline(std::cin, X);
	std::cout << "Input Y: ";
	std::getline(std::cin, Y);
	for (int i = 0; i < X.length(); i++)
		X_vector.push_back(X[i]);
	for (int i = 0; i < Y.length(); i++)
		Y_vector.push_back(Y[i]);
	int table[100][100];
	char construct[100][100]; //'d' for diagonal, 'u' for up,'l' for left
	for (int i = 1; i <= X_vector.size(); i++)
	{
		table[i][0] = 0;
	}
	for (int i = 1; i <= Y_vector.size(); i++)
	{
		table[0][i] = 0;
	}
	table[0][0] = 0;
	for (int i = 1; i <= X_vector.size(); i++)
	{
		for (int j = 1; j <= Y_vector.size(); j++)
		{
			if (X_vector[i - 1] == Y_vector[j - 1])
			{
				table[i][j] = table[i - 1][j - 1] + 1;
				construct[i][j] = 'd';
			}
			else
			{
				if (table[i - 1][j] >= table[i][j - 1])
				{
					table[i][j] = table[i - 1][j];
					construct[i][j] = 'u';
				}
				else
				{
					table[i][j] = table[i][j - 1];
					construct[i][j] = 'l';
				}
			}
		}
	}
	std::cout << "Length of the longest common subsequence: " << table[X_vector.size()][Y_vector.size()] << std::endl;
	std::cout << "That is:\n";
	print(construct, X_vector, X_vector.size(), Y_vector.size());
	std::cout << std::endl;
	system("pause");
}