using System;

namespace TruckSelection
{
    class Truck
    {
        // Поля класу для зберігання даних про вантажівку
        string brand;
        double loadCapacity;
        double maxSpeed;
        double price;
        int attribute;

        // Метод для введення даних про вантажівку
        public void Input(int n)
        {
            string s;
            Console.WriteLine("Enter the brand of truck number {0}", n + 1);
            brand = Console.ReadLine();

            Console.WriteLine("Enter the load capacity (kg) of truck number {0}", n + 1);
            s = Console.ReadLine();
            loadCapacity = Convert.ToDouble(s);

            Console.WriteLine("Enter the maximum speed (km/h) of truck number {0}", n + 1);
            s = Console.ReadLine();
            maxSpeed = Convert.ToDouble(s);

            Console.WriteLine("Enter the price of truck number {0}", n + 1);
            s = Console.ReadLine();
            price = Convert.ToDouble(s);
        }

        // Метод для аналізу, чи відповідає вантажівка вимогам покупця
        public void Analyse(ref double desiredWeight, ref double desiredSpeed, ref double desiredPrice)
        {
            if (loadCapacity >= desiredWeight && maxSpeed >= desiredSpeed && price <= desiredPrice)
                attribute = 1;  // Вантажівка підходить
            else
                attribute = 0;  // Вантажівка не підходить
        }

        // Метод для виведення результатів
        public void Output(int n)
        {
            if (attribute == 1)
            {
                Console.WriteLine("Truck number {0} is suitable for you.", n + 1);
                Console.WriteLine("Brand: {0}, Load Capacity: {1} kg, Max Speed: {2} km/h, Price: {3}", brand, loadCapacity, maxSpeed, price);
            }
            else
                Console.WriteLine("Truck number {0} isn't suitable for you.", n + 1);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            uint numberOfTrucks;
            string s;

            // Введення кількості вантажівок
            Console.WriteLine("Enter the number of trucks:");
            s = Console.ReadLine();
            numberOfTrucks = Convert.ToUInt32(s);

            Truck[] trucks = new Truck[numberOfTrucks];

            // Введення даних для кожної вантажівки
            for (int i = 0; i < trucks.Length; i++)
            {
                trucks[i] = new Truck();
                trucks[i].Input(i);
            }

            // Введення вимог покупця
            double desiredWeight, desiredSpeed, desiredPrice;

            Console.WriteLine("Enter desired load capacity (kg):");
            desiredWeight = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter desired maximum speed (km/h):");
            desiredSpeed = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Enter your maximum budget for the truck:");
            desiredPrice = Convert.ToDouble(Console.ReadLine());

            // Перевірка кожної вантажівки на відповідність вимогам
            for (int i = 0; i < trucks.Length; i++)
            {
                trucks[i].Analyse(ref desiredWeight, ref desiredSpeed, ref desiredPrice);
                trucks[i].Output(i);
            }
        }
    }
}
