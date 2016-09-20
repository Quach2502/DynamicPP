//#include <iostream>
//#include <vector>
//void print(int (*construct)[40], int i, int j)
//{
//	if (i == j)
//		std::cout << "A" << i;
//	else
//	{
//		std::cout << "(";
//		print(construct, i, construct[i][j]);
//		print(construct, construct[i][j] + 1, j);
//		std::cout << ")";
//	}
//}
//void main()
//{
//	std::vector<int> sizes;
//	int number = 0;
//	int i, j;
//	std::cout << "How many matrices?\n";
//	std::cin >> number;
//	int memo[40][40];
//	int construct[40][40];
//	std::cout << "Input sizes:\n";
//	for (i = 0; i <= number; i++)
//	{
//		int size;
//		std::cin >> size;
//		sizes.push_back(size);
//	}
//	for (int x = 1; x <= number; x++)
//	{
//		for (int y = 1; y <= number; y++)
//			memo[x][y] = 100000000;
//	}
//	for (int x = 1; x <= number; x++)
//		memo[x][x] = 0;
//	
//	int l; //length of the chain 
//	for (l = 2; l <= number; l++)
//	{
//		for (i = 1; i <= number-l+1; i++)
//		{
//			j = i + l - 1;
//			for (int k = i; k < j; k++)
//			{
//				int result = memo[i][k] + memo[k+1][j] + sizes[i-1] * sizes[k] * sizes[j];
//				if (result < memo[i][j])
//				{
//					memo[i][j] = result;
//					construct[i][j] = k;
//				}
//			}
//		}
//	}
//	std::cout << "Optimization for the multiplication: " << memo[1][number] << std::endl;
//	std::cout << "That is\n";
//	print(construct, 1, number);
//	system("pause");
//}