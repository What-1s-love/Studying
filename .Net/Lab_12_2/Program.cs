using System;
using System.IO;

class Program
{
    static void Main()
    {
        string[] lines = File.ReadAllLines("InputFile.txt");
        string[] dims = lines[0].Split(' ');
        int n = int.Parse(dims[0]); // rows A
        int m = int.Parse(dims[1]); // cols A / rows B
        int p = int.Parse(dims[2]); // cols B

        int[,] A = new int[n, m];
        int[,] B = new int[m, p];
        int[,] C = new int[n, p];

        int lineIndex = 1;

        // Read A
        for (int i = 0; i < n; i++)
        {
            string[] parts = lines[lineIndex++].Split(' ');
            for (int j = 0; j < m; j++)
                A[i, j] = int.Parse(parts[j]);
        }

        // Read B
        for (int i = 0; i < m; i++)
        {
            string[] parts = lines[lineIndex++].Split(' ');
            for (int j = 0; j < p; j++)
                B[i, j] = int.Parse(parts[j]);
        }

        // Multiply A * B = C
        for (int i = 0; i < n; i++)
            for (int j = 0; j < p; j++)
                for (int k = 0; k < m; k++)
                    C[i, j] += A[i, k] * B[k, j];

        // Write output
        using (StreamWriter writer = new StreamWriter("output.txt"))
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < p; j++)
                    writer.Write(C[i, j] + " ");
                writer.WriteLine();
            }
        }

        Console.WriteLine("Matrix multiplication complete. Result in output.txt.");
    }
}
