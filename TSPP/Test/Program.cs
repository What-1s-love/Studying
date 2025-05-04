using System;
using MySql.Data.MySqlClient;

class Program
{
    static void Main()
    {
        // Connection string
        string connectionString = "server=127.0.0.1;port=3306;database=WeatherData;User id=root;pwd=234234234;";

        try
        {
            // Establishing connection to the database
            using (var connection = new MySqlConnection(connectionString))
            {
                connection.Open();
                Console.WriteLine("Connection to the database successful.");

                // SQL query to fetch data from the Weather table
                string query = "SELECT * FROM Weather LIMIT 10;";  // Fetching first 10 rows as an example

                using (var command = new MySqlCommand(query, connection))
                using (var reader = command.ExecuteReader())
                {
                    // Displaying results
                    while (reader.Read())
                    {
                        // Assuming the table has columns 'id' and 'temperature'
                        Console.WriteLine($"ID: {reader["id"]}, Temperature: {reader["temperature"]}");
                    }
                }
            }
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Error: {ex.Message}");
        }
    }
}
