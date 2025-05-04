using System;

abstract class Device
{
    public string Brand { get; set; }
    public string Model { get; set; }

    public abstract void InputData();
    public abstract void DisplayData();
}

class Smartphone : Device
{
    public int BatteryLife { get; set; }

    public override void InputData()
    {
        Console.Write("Enter Smartphone Brand: ");
        Brand = Console.ReadLine();
        Console.Write("Enter Model: ");
        Model = Console.ReadLine();
        Console.Write("Enter Battery Life (hours): ");
        BatteryLife = int.Parse(Console.ReadLine());
    }

    public override void DisplayData()
    {
        Console.WriteLine($"Smartphone: {Brand} {Model}, Battery Life: {BatteryLife} hours");
    }
}

class Laptop : Device
{
    public double ScreenSize { get; set; }

    public override void InputData()
    {
        Console.Write("Enter Laptop Brand: ");
        Brand = Console.ReadLine();
        Console.Write("Enter Model: ");
        Model = Console.ReadLine();
        Console.Write("Enter Screen Size (inches): ");
        ScreenSize = double.Parse(Console.ReadLine());
    }

    public override void DisplayData()
    {
        Console.WriteLine($"Laptop: {Brand} {Model}, Screen Size: {ScreenSize}\"");
    }
}

class Program
{
    static void Main()
    {
        Smartphone phone = new Smartphone();
        phone.InputData();
        phone.DisplayData();

        Laptop laptop = new Laptop();
        laptop.InputData();
        laptop.DisplayData();
    }
}