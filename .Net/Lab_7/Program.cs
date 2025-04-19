using System;
using System.Collections.Generic;

// 🔹 Базовий клас "Корабель"
public class Ship
{
    public string Name { get; set; }
    public string Purpose { get; set; }
    public double Displacement { get; set; } // Водотоннажність
    public double EnginePower { get; set; }  // Потужність двигуна
    public string FuelType { get; set; }

    public void PrintInfo()
    {
        Console.WriteLine($"Ship: {Name}");
        Console.WriteLine($"Purpose: {Purpose}");
        Console.WriteLine($"Displacement: {Displacement} tons");
        Console.WriteLine($"Engine Power: {EnginePower} kW");
        Console.WriteLine($"Fuel Type: {FuelType}");
        Console.WriteLine("-----------------------------------");
    }
}

// 🔸 Похідний клас "Авіаносець"
public class AircraftCarrier : Ship
{
    public Dictionary<string, int> Aircrafts { get; set; } = new Dictionary<string, int>();

    public void AddAircraft(string model, int quantity)
    {
        if (Aircrafts.ContainsKey(model))
            Aircrafts[model] += quantity;
        else
            Aircrafts[model] = quantity;
    }

    public void PrintAircraftInfo()
    {
        Console.WriteLine($"Aircraft Carrier: {Name}");
        Console.WriteLine("Aircrafts on board:");
        foreach (var aircraft in Aircrafts)
        {
            Console.WriteLine($"- {aircraft.Key}: {aircraft.Value}");
        }
        Console.WriteLine("-----------------------------------");
    }
}

// 🔸 Похідний клас "Ракетоносець"
public class MissileCruiser : Ship
{
    public string MissileType { get; set; }
    public int MissileCount { get; set; }

    public void PrintMissileInfo()
    {
        Console.WriteLine($"Missile Cruiser: {Name}");
        Console.WriteLine($"Missile Type: {MissileType}");
        Console.WriteLine($"Missile Count: {MissileCount}");
        Console.WriteLine("-----------------------------------");
    }
}

// 🔹 Головна програма
class Program
{
    static void Main()
    {
        // 🔹 Створення авіаносця
        AircraftCarrier carrier = new AircraftCarrier();
        carrier.Name = "USS Enterprise";
        carrier.Purpose = "Air Support";
        carrier.Displacement = 95000;
        carrier.EnginePower = 280000;
        carrier.FuelType = "Nuclear";
        carrier.AddAircraft("F-35", 20);
        carrier.AddAircraft("F/A-18", 15);

        // 🔹 Створення ракетоносця
        MissileCruiser cruiser = new MissileCruiser();
        cruiser.Name = "Kyiv";
        cruiser.Purpose = "Missile Strikes";
        cruiser.Displacement = 11500;
        cruiser.EnginePower = 75000;
        cruiser.FuelType = "Diesel";
        cruiser.MissileType = "P-800";
        cruiser.MissileCount = 16;

        // 🔹 Створення звичайного корабля
        Ship genericShip = new Ship();
        genericShip.Name = "Titan";
        genericShip.Purpose = "Transport";
        genericShip.Displacement = 15000;
        genericShip.EnginePower = 40000;
        genericShip.FuelType = "Diesel";

        // 🔹 Виведення інформації
        carrier.PrintInfo();            // Базова інформація
        carrier.PrintAircraftInfo();    // Інфо про літаки

        cruiser.PrintInfo();            // Базова інформація
        cruiser.PrintMissileInfo();     // Інфо про ракети
    }
}