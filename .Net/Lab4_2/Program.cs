using System;

class Program
{
    static void Main()
    {
        // Генератор випадкових чисел
        Random rand = new Random();

        // Введення кількості студентів
        Console.Write("Enter the number of students: ");
        int n;
        while (!int.TryParse(Console.ReadLine(), out n) || n <= 0)
        {
            Console.WriteLine("Invalid input! Enter a positive integer:");
        }

        // Масиви імен студентів та їхніх балів
        string[] names = new string[n];
        int[] grades = new int[n];

        // Приклади випадкових імен студентів
        string[] sampleNames = { "Alice", "Bob", "Charlie", "David", "Emma", "Frank", "Grace", "Helen", "Ivan", "Jack" };

        // Заповнюємо масиви випадковими значеннями
        for (int i = 0; i < n; i++)
        {
            names[i] = sampleNames[rand.Next(sampleNames.Length)]; // Випадкове ім'я
            grades[i] = rand.Next(50, 101); // Оцінка від 50 до 100
        }

        // Сортуємо студентів за їхніми оцінками
        Array.Sort(grades, names);

        // Вивід результатів
        Console.WriteLine("\nSorted list of students:");
        Console.WriteLine($"{"Name",-10} | {"Grade",-5}");
        Console.WriteLine(new string('-', 20));

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"{names[i],-10} | {grades[i],-5}");
        }
    }
}
