using System;
using System.IO;
using System.Globalization;

class Program
{
    static void Main()
    {
        string[] input = File.ReadAllText("InputFile.txt").Split(' ');
        double xmin = double.Parse(input[0], CultureInfo.InvariantCulture);
        double xmax = double.Parse(input[1], CultureInfo.InvariantCulture);
        double dx = double.Parse(input[2], CultureInfo.InvariantCulture);
        double k = double.Parse(input[3], CultureInfo.InvariantCulture);

        using (StreamWriter writer = new StreamWriter("output.txt"))
        {
            writer.WriteLine("x\t\tZ");
            for (double x = xmin; x <= xmax; x += dx)
            {
                double kx = k * x;
                double tanKx = Math.Tan(kx);
                double sinKx = Math.Sin(kx);
                double cosKx = Math.Cos(kx);

                if (Math.Abs(tanKx) < 1e-8 || sinKx <= 0)
                {
                    writer.WriteLine($"{x:F3}\t\tundefined");
                }
                else
                {
                    double first = Math.Cbrt(1.0 / tanKx);
                    double second = cosKx / Math.Log(sinKx);
                    double Z = first + second;
                    writer.WriteLine($"{x:F3}\t\t{Z:F5}");
                }
            }
        }

        Console.WriteLine("Function Z(x) tabulated and saved to output.txt.");
    }
}
