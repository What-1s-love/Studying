using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("Enter the number of elements for the first array:");
        int[] array1 = ReadArray();
        Console.WriteLine("Enter the number of elements for the second array:");
        int[] array2 = ReadArray();
        Console.WriteLine("Enter the number of elements for the third array:");
        int[] array3 = ReadArray();

        ProcessArray(array1, "First array");
        ProcessArray(array2, "Second array");
        ProcessArray(array3, "Third array");
    }

    static int[] ReadArray()
    {
        int n;
        while (!int.TryParse(Console.ReadLine(), out n) || n <= 0)
        {
            Console.WriteLine("Invalid input. Please enter a positive integer:");
        }

        int[] array = new int[n];
        Console.WriteLine("Enter the elements of the array:");
        for (int i = 0; i < n; i++)
        {
            while (!int.TryParse(Console.ReadLine(), out array[i]))
            {
                Console.WriteLine("Invalid input. Please enter an integer:");
            }
        }
        return array;
    }

    static void ProcessArray(int[] array, string arrayName)
    {
        if (array.Length == 0)
        {
            Console.WriteLine($"{arrayName} is empty.");
            return;
        }

        int min = array[0], max = array[0];
        int minIndex = 0, maxIndex = 0;

        for (int i = 1; i < array.Length; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
                minIndex = i;
            }
            if (array[i] > max)
            {
                max = array[i];
                maxIndex = i;
            }
        }

        Console.WriteLine($"{arrayName}: ");
        Console.WriteLine($"Minimum value: {min} at index {minIndex}");
        Console.WriteLine($"Maximum value: {max} at index {maxIndex}\n");
    }
}
