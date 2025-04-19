using System;

namespace StringManipulation
{
    class Program
    {
        static void Main(string[] args)
        {
            // 1. Об’єднання рядків
            string s1 = "Hello, ";
            string s2 = "world!";
            string s3 = string.Concat(s1, s2);  // Об'єднання рядків
            Console.WriteLine("String concatenation result: " + s3);

            // 2. Вставлення рядків
            string str1 = "I love ";
            string str2 = "C# programming!";
            string result = str1.Insert(7, str2);  // Вставлення str2 після 7-ї позиції в str1
            Console.WriteLine("String insertion result: " + result);

            // 3. Заміна рядків
            string s4 = "I like coding.";
            string replaced = s4.Replace("coding", "C#");
            Console.WriteLine("String replacement result: " + replaced);

            // 4. Вилучення рядків
            string s5 = "This is a simple example.";
            string removed = s5.Remove(10, 6);  // Видалити 6 символів починаючи з 10-го індексу
            Console.WriteLine("String removal result: " + removed);

            // 5. Порівняння двох рядків
            string s6 = "apple";
            string s7 = "apple";
            bool areEqual = s6.Equals(s7);  // Порівняння рядків на рівність
            Console.WriteLine("String comparison result: " + areEqual);

            // 6. Порівняння символів із двох рядків на певних місцях
            char char1 = s6[1];  // Символ на 1-й позиції рядка s6
            char char2 = s7[1];  // Символ на 1-й позиції рядка s7
            Console.WriteLine($"Character comparison: {char1} and {char2} - Are they equal? {char1 == char2}");

            // 7. Визначення індексу першого входження заданого рядка
            string s8 = "Welcome to the C# world!";
            int index = s8.IndexOf("C#");  // Знайти індекс першого входження "C#" в рядок
            Console.WriteLine("Index of first occurrence of 'C#': " + index);
        }
    }
}
