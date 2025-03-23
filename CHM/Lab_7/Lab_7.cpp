#include <iostream>
#include <vector>
#include<math.h>
#include<iomanip>
using namespace std;


void itetations(std::vector<std::vector<double>>& delta_y,
    std::vector<std::vector<double>>& x,
    std::vector<std::vector<double>>& y,
    std::vector<std::vector<double>>& k, int max_size, double h, double a, double y_0)

{
    double sum_delta(0);
    for (int i = 0; i <= max_size; ++i)
    {
        if (i == 0)
        {
            x[0][0] = a;
            y[0][0] = y_0;
        }
        else
        {
            x[i][0] = x[i - 1][0] + h;
            y[i][0] = y[i - 1][0] + sum_delta;
        }
        sum_delta = 0;
        for (int j = 0; j < 4; ++j)
        {

            if (j != 0)
            {
                if (j != 3)
                {
                    x[i][j] = x[i][0] + h / 2;
                    y[i][j] = y[i][0] + k[i][j - 1] / 2;
                }
                else
                {
                    x[i][j] = x[i][0] + h;
                    y[i][j] = y[i][0] + k[i][j - 1];
                }
            }


            k[i][j] = (1 + 0.4 * y[i][j] * sin(x[i][j]) - 1.5 * pow(y[i][j], 2)) * h;

            if (j == 0 or j == 3)
                delta_y[i][j] = k[i][j];
            else
                delta_y[i][j] = 2 * k[i][j];

            sum_delta += delta_y[i][j];

            if (j == 3)
                sum_delta /= 6;
        }
    }
}
void find(double a, double b, double epsilon, double h, double y_0)
{

    vector <vector <double>>delta_y(10, vector<double>(10));
    vector <vector <double>>x(10, vector<double>(10));
    vector <vector <double>>y(10, vector<double>(10));
    vector <vector <double>>k(10, vector<double>(10));

    vector <vector <double>>delta_y_2(15, vector<double>(15));
    vector <vector <double>>x_2(15, vector<double>(15));
    vector <vector <double>>y_2(15, vector<double>(15));
    vector <vector <double>>k_2(15, vector<double>(15));
    int max_size = (b - a) / h;

    itetations(delta_y, x, y, k, max_size, h, a, y_0);

    h /= 2;
    max_size *= 2;
    itetations(delta_y_2, x_2, y_2, k_2, max_size, h, a, y_0);

    cout << "Error " << endl;
    int m(0);
    for (int i = 0; i <= max_size / 2; ++i)
    {
        cout << "Iteration " << i + 1 << ": " << fabs(y[i][0] - y_2[m][0]) / 15.0 << endl;
        m += 2;
    }
    cout << endl << endl;
    cout << "Our function in the table form " << endl;
    cout << setw(6) << "X" << "    " << "Y     " << endl;
    for (int i = 0; i <= max_size / 2; ++i)
        cout << setw(6) << x[i][0] << "    " << y[i][0] << endl;
}
int main()
{
    double a, b, epsilon, h, y_0;
    cout << "Enter the a ";
    cin >> a;
    cout << "Enter the b ";
    cin >> b;
    cout << "Enter the epsilon ";
    cin >> epsilon;
    cout << "Enter the step ";
    cin >> h;
    cout << "Enter the y0 ";
    cin >> y_0;

    find(a, b, epsilon, h, y_0);
}
