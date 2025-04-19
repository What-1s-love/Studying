using System;

class Program
{
    static void Main()
    {
        // Генератор випадкових чисел
        Random rand = new Random();

        // Введення кількості товарів
        Console.Write("Enter the number of products: ");
        int n;
        while (!int.TryParse(Console.ReadLine(), out n) || n <= 0)
        {
            Console.WriteLine("Invalid input! Enter a positive integer:");
        }

        // Масиви назв товарів та їхніх цін
        string[] products = new string[n];
        int[] prices = new int[n];

        // Приклади випадкових назв товарів
        string[] sampleProducts = { "Laptop", "Phone", "Tablet", "TV", "Headphones", "Mouse", "Keyboard", "Camera", "Smartwatch", "Speaker" };

        // Заповнюємо масиви випадковими значеннями
        for (int i = 0; i < n; i++)
        {
            products[i] = sampleProducts[rand.Next(sampleProducts.Length)]; // Випадковий товар
            prices[i] = rand.Next(100, 2001); // Ціна від 100 до 2000
        }

        // Сортуємо товари за ціною в порядку зростання
        Array.Sort(prices, products);

        // Розвертаємо масиви, щоб отримати сортування за спаданням
        Array.Reverse(prices);
        Array.Reverse(products);

        // Вивід результатів
        Console.WriteLine("\nSorted list of products by price (descending):");
        Console.WriteLine($"{"Product",-12} | {"Price",-6}");
        Console.WriteLine(new string('-', 22));

        for (int i = 0; i < n; i++)
        {
            Console.WriteLine($"{products[i],-12} | {prices[i],-6}");
        }
    }
}
