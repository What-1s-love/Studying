using System;

class Tractor
{
    public string Brand { get; set; }
    public int EnginePower { get; set; } // у кінських силах (hp)
    public string FuelType { get; set; }
    public int MaxSpeed { get; set; } // у км/год
    public decimal Price { get; set; } // у гривнях

    // Метод для виводу даних про трактор
    public void Display()
    {
        Console.WriteLine($"Brand: {Brand}, Engine Power: {EnginePower} HP, Fuel Type: {FuelType}, " +
                          $"Max Speed: {MaxSpeed} km/h, Price: {Price} UAH");
    }
}

class Program
{
    static void Main()
    {
        // Введення кількості тракторів
        Console.Write("Enter the number of tractors: ");
        int n = int.Parse(Console.ReadLine());
        Tractor[] tractors = new Tractor[n];

        // Введення даних для кожного трактора
        for (int i = 0; i < n; i++)
        {
            tractors[i] = new Tractor();

            Console.WriteLine($"\nEnter data for tractor #{i + 1}:");
            Console.Write("Brand: ");
            tractors[i].Brand = Console.ReadLine();

            Console.Write("Engine Power (HP): ");
            tractors[i].EnginePower = int.Parse(Console.ReadLine());

            Console.Write("Fuel Type: ");
            tractors[i].FuelType = Console.ReadLine();

            Console.Write("Max Speed (km/h): ");
            tractors[i].MaxSpeed = int.Parse(Console.ReadLine());

            Console.Write("Price (UAH): ");
            tractors[i].Price = decimal.Parse(Console.ReadLine());
        }

        // Введення критеріїв від покупця
        Console.WriteLine("\n--- Buyer's Requirements ---");
        Console.Write("Minimum Engine Power (HP): ");
        int minPower = int.Parse(Console.ReadLine());

        Console.Write("Minimum Max Speed (km/h): ");
        int minSpeed = int.Parse(Console.ReadLine());

        Console.Write("Maximum Price (UAH): ");
        decimal maxPrice = decimal.Parse(Console.ReadLine());

        // Пошук і вивід тракторів, які задовольняють умови
        Console.WriteLine("\n--- Matching Tractors ---");
        bool found = false;

        foreach (Tractor t in tractors)
        {
            if (t.EnginePower >= minPower && t.MaxSpeed >= minSpeed && t.Price <= maxPrice)
            {
                t.Display();
                found = true;
            }
        }

        // Якщо не знайдено жодного відповідного трактора
        if (!found)
        {
            Console.WriteLine("No tractors match the given criteria.");
        }
    }
}
