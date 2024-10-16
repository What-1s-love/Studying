	#include <iostream>
	#include <cstdio>
	#include <locale>
	#include <vector>
	#include <cmath>
	#include <locale>

	using namespace std;

	void gradient(std::vector<std::vector<double>>&x_iter, vector<double>&grad, int i)
	{
		      i = i - 1;
	
			       grad[0] = static_cast<double>(28.0 * x_iter[i][0] + 10.0 * x_iter[i][1] + 4.0 * x_iter[i][2] + -4.0 * pow(x_iter[i][1], 2) - 37.76);
		       grad[1] = static_cast<double>(10.0 * x_iter[i][0] + 10.0 * x_iter[i][1] + -4.0 * x_iter[i][1] * (2.0 * x_iter[i][0] + x_iter[i][2] + -1.0 * pow(x_iter[i][1], 2) - 2.19) + -10.0 * pow(x_iter[i][2], 2) - 9.0);
		       grad[2] = static_cast<double>(4.0 * x_iter[i][0] + 2.0 * x_iter[i][2] + -2.0 * pow(x_iter[i][1], 2) + 4.0 * x_iter[i][2] * (3.0 * x_iter[i][0] + x_iter[i][1] + pow(x_iter[i][2], 2) - 4.9) + -12.0 * x_iter[i][2] * (x_iter[i][0] + 2.0 * x_iter[i][1] + -3.0 * x_iter[i][2] + 0.2) - 4.38);
	
			}

	void find_Max(vector<double> grad, double& max)
	{
		   max = fabs(grad[0]);
		   for (int i = 1; i < 3; i++)
			      if (fabs(grad[i]) > max)
			         max = fabs(grad[i]);
	
			}
	void iterations(vector<double> x, double lyambda, double epsilon)
	{
		   int n(100), k(3);
		   vector <vector <double>>x_iter(n, vector<double>(k));
		   vector<double> grad;
	
			   grad.resize(5);
		   double max(11);
		   int it(1);
		   int g(n);
		   for (int j = 0; j < 3; j++)
			      x_iter[0][j] = x[j];
	
			   long long  count(0);
		   for (int i = 1; max > epsilon; i++) {
			      gradient(x_iter, grad, i);
		
			
				      int p = 1;
		
				      for (int j = 0; j < 3; j++) {
			
					         x_iter[i][j] = static_cast<double>((x_iter[static_cast<std::vector<std::vector<double, std::allocator<double>>, std::allocator<std::vector<double, std::allocator<double>>>>::size_type>(i) - it][j] - lyambda * grad[j]));
			
				
				
		}
			       count++;
		
				       find_Max(grad, max);
			       ++g;
		
				       x_iter.resize(g);
			       x_iter[static_cast<std::vector<std::vector<double, std::allocator<double>>, std::allocator<std::vector<double, std::allocator<double>>>>::size_type>(g) - 1].resize(3);
			       x_iter.reserve(g);
			       ++p;
		
	}
		   //find_Max(grad, max);
			   cout << "X is equal " << endl;
		   for (int j = 0; j < 3; j++)
			      cout << x_iter[static_cast<std::vector<std::vector<double, std::allocator<double>>, std::allocator<std::vector<double, std::allocator<double>>>>::size_type>(g) - n - 1][j] << endl;
		   cout << "The quantity of iterations " << count;
		}
	int main()
	{
		   std::locale::global(std::locale(""));
	
			   cout << "Hi, we will investigate such system of functions" << endl;
		   cout << "2 * x - y^2 + z - 2.19" << endl;
		   cout << "x + 2 * y - 3 * z + 0.2" << endl;
		   cout << "3 * x + y + z^2 - 4.9" << endl;
		   double epsilon(0.0001), lyambda(0.00001);
		   std::locale::global(std::locale(""));
		   wchar_t lambdaSymbol = L'\u03BB';
		   wchar_t epsilonSzmbol = L'\u0395';
		   wcout << epsilonSzmbol << " = " << epsilon << endl;;
		   std::wcout << lambdaSymbol << " = " << lyambda << std::endl;
		   int N(3);
	
			   vector<double> x;
	   for (int i = 0; i < N; i++)
			      x.push_back(1);
		   iterations(x, lyambda, epsilon);
	
}