using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Select a formula variant (1, 2, 3, 4): ");
        string option = Console.ReadLine();

        Console.Write("Enter the value of x: ");
        if (!double.TryParse(Console.ReadLine(), out double x))
        {
            Console.WriteLine("Error! Invalid input for x.");
            return;
        }

        double z = 0;
        bool valid = true;

        switch (option)
        {
            case "1":
                Console.WriteLine("Choose a subvariant (first, second, third): ");
                string subOption1 = Console.ReadLine().ToLower();
                if (subOption1 == "first") z = Math.Pow(Math.Sin(x), 2);
                else if (subOption1 == "second")
                {
                    if (x <= 0) valid = false;
                    else z = Math.Pow(Math.Log(x), 2);
                }
                else if (subOption1 == "third")
                {
                    if (Math.Cos(x) == 0) valid = false;
                    else z = 1 / Math.Cos(Math.Pow(x, 3));
                }
                else valid = false;
                break;

            case "2":
                Console.WriteLine("Choose a subvariant (a, b, c):");
                string subOption2 = Console.ReadLine().ToLower();
                if (subOption2 == "a")
                {
                    if (Math.Tan(x) < 0 || Math.Cos(x) == 0) valid = false;
                    else z = Math.Sqrt(Math.Tan(x));
                }
                else if (subOption2 == "b")
                {
                    if (Math.Cos(x) == 0) valid = false;
                    else z = 1 / Math.Tan(x);
                }
                else if (subOption2 == "c")
                {
                    if (Math.Tan(x) <= 0 || Math.Cos(x) == 0) valid = false;
                    else z = Math.Log(Math.Tan(x));
                }
                else valid = false;
                break;

            case "3":
                Console.WriteLine("Choose a subvariant (100, 200, 250):");
                if (!int.TryParse(Console.ReadLine(), out int subOption3)) valid = false;
                else if (subOption3 == 100)
                {
                    if (Math.Sin(x) < 0) valid = false;
                    else z = Math.Sqrt(Math.Sin(x));
                }
                else if (subOption3 == 200)
                {
                    if (Math.Cos(x) == 0) valid = false;
                    else z = 1 / Math.Cos(x);
                }
                else if (subOption3 == 250)
                {
                    if (Math.Tan(x) == 0) valid = false;
                    else z = Math.Log(Math.Abs(Math.Tan(x)));
                }
                else valid = false;
                break;

            case "4":
                Console.WriteLine("Choose a subvariant (alfa, beta, gamma):");
                string subOption4 = Console.ReadLine().ToLower();
                Console.Write("Enter the value of a: ");
                if (!double.TryParse(Console.ReadLine(), out double a)) valid = false;

                if (subOption4 == "alfa")
                {
                    if (a + Math.Sin(x) < 0) valid = false;
                    else z = Math.Sqrt(a + Math.Sin(x));
                }
                else if (subOption4 == "beta")
                {
                    if (a * x < 0) valid = false;
                    else z = Math.Sqrt(Math.Sin(a * x));
                }
                else if (subOption4 == "gamma")
                {
                    if (a - x <= 0) valid = false;
                    else z = Math.Log(a - x);
                }
                else valid = false;
                break;

            default:
                valid = false;
                break;
        }

        if (valid)
            Console.WriteLine($"Result: z = {z}");
        else
            Console.WriteLine("Error! Calculation is not possible.");
    }
}
