using System;

class Tractor
{
    public string Brand { get; set; }
    public double EnginePower { get; set; } // Потужність двигуна
    public string FuelType { get; set; } // Вид пального
    public double Price { get; set; } // Ціна трактора

    public Tractor(string brand, double power, string fuel, double price)
    {
        Brand = brand;
        EnginePower = power;
        FuelType = fuel;
        Price = price;
    }

    // Перевантаження оператора "=="
    public static bool operator ==(Tractor a, Tractor b)
    {
        return a.Brand == b.Brand && a.EnginePower == b.EnginePower && a.FuelType == b.FuelType && a.Price == b.Price;
    }

    // Перевантаження оператора "!="
    public static bool operator !=(Tractor a, Tractor b)
    {
        return !(a == b);
    }

    // Перевантаження оператора "<"
    public static bool operator <(Tractor a, Tractor b)
    {
        return a.Price < b.Price;
    }

    // Перевантаження оператора ">"
    public static bool operator >(Tractor a, Tractor b)
    {
        return a.Price > b.Price;
    }

    // Перевантаження оператора "+"
    public static Tractor operator +(Tractor a, Tractor b)
    {
        return new Tractor("Combined Tractor", (a.EnginePower + b.EnginePower) / 2, "Mixed Fuel", a.Price + b.Price);
    }

    public void DisplayInfo()
    {
        Console.WriteLine($"Brand: {Brand}, Power: {EnginePower} HP, Fuel: {FuelType}, Price: {Price} USD");
    }
}

class Program
{
    static void Main()
    {
        Tractor[] tractors = new Tractor[]
        {
            new Tractor("John Deere", 150, "Diesel", 50000),
            new Tractor("Case IH", 180, "Diesel", 60000),
            new Tractor("Kubota", 130, "Gasoline", 45000)
        };

        // Порівняння об'єктів у циклі
        for (int i = 0; i < tractors.Length - 1; i++)
        {
            Console.WriteLine($"Comparing {tractors[i].Brand} and {tractors[i + 1].Brand}:");

            if (tractors[i] == tractors[i + 1])
                Console.WriteLine("They are equal.");
            else if (tractors[i] != tractors[i + 1])
                Console.WriteLine("They are not equal.");

            if (tractors[i] < tractors[i + 1])
                Console.WriteLine($"{tractors[i].Brand} is cheaper than {tractors[i + 1].Brand}.");
            if (tractors[i] > tractors[i + 1])
                Console.WriteLine($"{tractors[i].Brand} is more expensive than {tractors[i + 1].Brand}.");

            Console.WriteLine();
        }

        // Використання оператора "+"
        Tractor combinedTractor = tractors[0] + tractors[1];
        Console.WriteLine("New combined tractor:");
        combinedTractor.DisplayInfo();
    }
}