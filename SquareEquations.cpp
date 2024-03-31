#include<stdio.h>
#include<math.h>
#include<vector>
void get_coofs(double& a, double& b, double& c)
{
	if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
	{
		printf("There is an error in your input. Please try again\n");
		while (getchar() != '\n');
		get_coofs(a, b, c);
	}
}
std::vector<double> SolveSquareEquation(double a, double b, double c)
{
	double D = b * b - 4 * a * c;
	if (D < 0)
		return {};
	else if (D == 0)
		return { -b / (2 * a) };
	else if (D > 0)
		return { (-b + sqrt(D)) / (2 * a),(-b - sqrt(D)) / (2 * a) };
}
int main(void)
{
	double a, b, c;
	printf("Enter cooficients a,b,c(via space) of square equation ax^2+bx+c=0, which decisions u wanna get(you can only enter integer or decimal):\n");
	get_coofs(a, b, c);
	std::vector<double>roots = SolveSquareEquation(a, b, c);
	if (roots.size() == 0)
		printf("Equation has no any roots\n");
	else if (roots.size() == 1)
	{
		double x = roots[0];
		int int_x = int(x);
		if (x - int_x == 0)
			printf("Equation has only one root - x = %d\n", int_x);
		else
			printf("Equation has only one root - x = %lf\n", x);
	}
	else if (roots.size() == 2)
	{
		double x1 = roots[0], x2 = roots[1];
		int int_x1 = int(x1), int_x2 = int(x2);
		printf("Equation has 2 roots:\n");
		if (x1 - int_x1 == 0)
			printf("First - %d\n", int_x1);
		else
			printf("First - %lf\n", x1);
		if (x2 - int_x2 == 0)
			printf("Second - %d\n", int_x2);
		else
			printf("Second - %lf\n", x2);
	}
}