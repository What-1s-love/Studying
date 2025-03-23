using System;

class Program
{
    static void Main()
    {
        Console.Write("Enter N: ");
        int N = Convert.ToInt32(Console.ReadLine());

        int a = 0, b = 1;

        Console.WriteLine("Fibonacci sequence:");
        for (int i = 0; i < N; i++)
        {
            Console.Write(a + " ");
            int temp = a;
            a = b;
            b = temp + b;
        }
    }
}
