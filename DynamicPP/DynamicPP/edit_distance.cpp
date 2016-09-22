#include <iostream>
#include <vector>
#include <string>
//<summary>
//transform string x(source) to string y (target) using optimized way:
//left (0) - right (0) - replace (4) - delete (2) - insert (3), cost is in parenthesis
//</summary>
void print(char(*construct)[300], int i, int j)
{
	if ((i == 0) && (j == 0))
		return;
	if (construct[i][j] == 'r')
	{
		print(construct, i - 1, j - 1);
		std::cout << "Right\n";
	}
	if (construct[i][j] == 'e')
	{
		print(construct, i - 1, j - 1);
		std::cout << "Replace\n";
	}
	if (construct[i][j] == 'd')
	{
		print(construct, i - 1, j);
		std::cout << "Delete\n";
	}
	if (construct[i][j] == 'i')
	{
		print(construct, i, j - 1);
		std::cout << "Insert\n";
	}
}
void main()
{
	std::string X("");
	std::string Y("");
	std::cout << "The source: ";
	std::getline(std::cin, X);
	std::cout << "The target: ";
	std::getline(std::cin, Y);
	int m = X.length();
	int n = Y.length();
	std::vector<char> source;
	std::vector<char> target;
	int table[300][300]; //look-up table, table[i][j] is the minimium cost for transforming 1st i chars of x to 1st j chars of y
	char construct[300][300]; //'l' for left(0), 'r' for right(0),'e' for replace(4),'d' for delete(2),'i' for insert(3)
	for (int i = 1; i <= m; i++)
		source.push_back(X[i - 1]);
	for (int i = 1; i <= n; i++)
		target.push_back(Y[i - 1]);
	int current = 0;
	std::vector<char> middle = source;
	for (int i = 0; i <= m; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			table[i][j] = 50000;
		}
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				if (i == 0 && j == 0)
				{
					table[i][j] = 0;
				}
				else
				{
					if (i > 0 && j > 0)
					{
						if (source[i - 1] == target[j - 1])//right
						{
							table[i][j] = table[i - 1][j - 1];
							construct[i][j] = 'r';
						}
						else
						{
							if (table[i][j] > table[i - 1][j - 1] + 4)//replace
							{
								table[i][j] = table[i - 1][j - 1] + 4;
								construct[i][j] = 'e';
							}
							if (table[i][j] > table[i - 1][j] + 2)//delete
							{
								table[i][j] = table[i - 1][j] + 2;
								construct[i][j] = 'd';
							}
							if (table[i][j] > table[i][j - 1] + 3)//insert
							{
								table[i][j] = table[i][j - 1] + 3;
								construct[i][j] = 'i';
							}
						}
					}
					else
					{
						if (i > 0 && (table[i][j] > table[i - 1][j] + 2))//delete
						{
							table[i][j] = table[i - 1][j] + 2;
							construct[i][j] = 'd';
						}
						if (j > 0 && (table[i][j] > table[i][j - 1] + 3))//insert
						{
							table[i][j] = table[i][j - 1] + 3;
							construct[i][j] = 'i';
						}
					}
				}
			}
		}
	}

		std::cout << "Length of source: " << m << std::endl;
		std::cout << "Length of target: " << n << std::endl;
		std::cout << "Minimum cost for transforming is: " << table[m][n] << std::endl;
		std::cout << "The sequence is:\n";
		print(construct, m, n);

		system("pause");
}