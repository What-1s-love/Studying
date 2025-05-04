using System;

class Vehicle
{
    public double Speed { get; set; }
    public double FuelConsumption { get; set; }
    public double Capacity { get; set; }

    public virtual double GetFuelEfficiency()
    {
        return FuelConsumption > 0 ? Speed / FuelConsumption + Capacity : 0;
    }
}

class Car : Vehicle
{
    public int NumberOfDoors { get; set; }
    public bool HasAirConditioning { get; set; }

    public override double GetFuelEfficiency()
    {
        double efficiency = base.GetFuelEfficiency();
        if (HasAirConditioning)
            efficiency -= 2;  // Зменшення ефективності через кондиціонер
        return efficiency;
    }
}

class Motorcycle : Vehicle
{
    public bool HasSidecar { get; set; }
    public double EngineCapacity { get; set; }

    public override double GetFuelEfficiency()
    {
        double efficiency = base.GetFuelEfficiency();
        if (HasSidecar)
            efficiency -= 1;  // Коляска зменшує ефективність
        return efficiency;
    }
}

class Truck : Vehicle
{
    public double MaxLoad { get; set; }
    public int AxlesCount { get; set; }

    public override double GetFuelEfficiency()
    {
        double efficiency = base.GetFuelEfficiency();
        if (Capacity > MaxLoad)
            efficiency -= 5;  // Штраф за перевищення вантажопідйомності
        return efficiency;
    }
}

class Program
{
    static void Main()
    {
        Car myCar = new Car
        {
            Speed = 120,
            FuelConsumption = 8,
            Capacity = 5,
            NumberOfDoors = 4,
            HasAirConditioning = true
        };

        Motorcycle myBike = new Motorcycle
        {
            Speed = 100,
            FuelConsumption = 3,
            Capacity = 2,
            HasSidecar = false,
            EngineCapacity = 650
        };

        Truck myTruck = new Truck
        {
            Speed = 80,
            FuelConsumption = 15,
            Capacity = 20,
            MaxLoad = 18,
            AxlesCount = 4
        };

        Console.WriteLine($"Car Fuel Efficiency: {myCar.GetFuelEfficiency()}");
        Console.WriteLine($"Motorcycle Fuel Efficiency: {myBike.GetFuelEfficiency()}");
        Console.WriteLine($"Truck Fuel Efficiency: {myTruck.GetFuelEfficiency()}");
    }
}