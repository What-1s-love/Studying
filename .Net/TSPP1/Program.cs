using System;
using System.Collections.Generic;

namespace WeatherSystem
{
    public interface IWeatherSystem
    {
        bool Authorize(string login, string password);
        void DisplayWeatherData(int month, int day);
        void EditRecord(int recordId, string newData);
        void AddRecord(string data);
        void DisplaySelectedWeatherData(int month, int day);
        double CalculateMonthlyAverage(int month);
        void SaveChangeHistory(int recordId, string oldData, string newData);
        void ExportToWord(List<string> filteredData);
    }

    public class WeatherSystem : IWeatherSystem
    {
        // Авторизація
        public bool Authorize(string login, string password)
        {
            // Перевірка даних користувача
            Console.WriteLine("Авторизація...");
            return true; // Повертає true, якщо успішно авторизовано
        }

        // Перегляд погодних умов
        public void DisplayWeatherData(int month, int day)
        {
            // Логіка для перегляду погодних умов
            Console.WriteLine($"Показати погодні умови за {month}/{day}");
        }

        // Редагування записів
        public void EditRecord(int recordId, string newData)
        {
            // Логіка редагування запису
            Console.WriteLine($"Редагування запису {recordId} з новими даними: {newData}");
        }

        // Додавання запису
        public void AddRecord(string data)
        {
            // Логіка додавання запису
            Console.WriteLine($"Додавання нового запису: {data}");
        }

        // Перегляд вибраної погоди
        public void DisplaySelectedWeatherData(int month, int day)
        {
            // Логіка для перегляду вибраної погоди
            Console.WriteLine($"Перегляд погодних умов за {month}/{day}");
        }

        // Обчислення середніх значень за місяць
        public double CalculateMonthlyAverage(int month)
        {
            // Логіка для обчислення середнього значення
            Console.WriteLine($"Обчислення середніх значень за {month} місяць.");
            return 25.5; // Повертає середнє значення (наприклад, середню температуру)
        }

        // Збереження історії змін
        public void SaveChangeHistory(int recordId, string oldData, string newData)
        {
            // Логіка збереження історії змін
            Console.WriteLine($"Історія змін для запису {recordId}: Старі дані: {oldData}, Нові дані: {newData}");
        }

        // Експорт у Word
        public void ExportToWord(List<string> filteredData)
        {
            // Логіка експорту даних у Word
            Console.WriteLine("Експортування даних у Word...");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            IWeatherSystem system = new WeatherSystem();

            // Приклад авторизації
            system.Authorize("admin", "password123");

            // Приклад перегляду погодних умов
            system.DisplayWeatherData(3, 15);

            // Приклад редагування запису
            system.EditRecord(101, "Нова температура: 15°C");

            // Приклад додавання запису
            system.AddRecord("Температура: 18°C, Опади: 5мм");

            // Перегляд вибраної погоди
            system.DisplaySelectedWeatherData(3, 15);

            // Обчислення середнього значення
            double average = system.CalculateMonthlyAverage(3);
            Console.WriteLine($"Середнє значення за місяць: {average}°C");

            // Збереження історії змін
            system.SaveChangeHistory(101, "Температура: 20°C", "Температура: 15°C");

            // Експорт у Word
            system.ExportToWord(new List<string> { "Дані 1", "Дані 2", "Дані 3" });
        }
    }
}
