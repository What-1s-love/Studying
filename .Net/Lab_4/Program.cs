using System;

class Program
{
    static void Main()
    {
        //Введення кількості співробітників
        Console.Write("Enter the number of employees: ");
        int n = int.Parse(Console.ReadLine());

        //Оголошення масивів
        int[] heights = new int[n];
        int[] weights = new int[n];
        Random rand = new Random();

        //Заповнення масивів випадковими значеннями
        for (int i = 0; i < n; i++)
        {
            heights[i] = rand.Next(150, 201); // Зріст 150-200 см
            weights[i] = rand.Next(50, 121);  // Вага 50-120 кг
        }

        //Вивід початкових даних
        Console.WriteLine("\nInitial data:");
        PrintData(heights, weights);

        //Сортування за зростом
        Array.Sort(heights, weights);

        //Вивід відсортованих даних
        Console.WriteLine("\nSorted data:");
        PrintData(heights, weights);
    }

    // 🔹 Функція для виводу масивів у вигляді таблиці
    static void PrintData(int[] heights, int[] weights)
    {
        Console.WriteLine("Height (cm) | Weight (kg)");
        Console.WriteLine("-------------------------");
        for (int i = 0; i < heights.Length; i++)
        {
            Console.WriteLine($"{heights[i],10} | {weights[i],10}");
        }
    }
}

