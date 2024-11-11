import csv

# Функція для читання та виведення вмісту CSV файлу
def read_csv(file_name):
    try:
        with open(file_name, "r", newline='', encoding='utf-8') as csvfile:
            reader = csv.DictReader(csvfile)
            print("Country Name: GDP per capita (current US$) 2019")
            for row in reader:
                print(f"{row['Country Name']}: {row['2019 [YR2019]']}")
    except FileNotFoundError:
        print(f"Файл {file_name} не знайдено!")

# Функція для пошуку даних за назвою країни та запису в новий CSV файл
def search_country_gdp(file_name, output_file):
    try:
        with open(file_name, "r", newline='', encoding='utf-8') as csvfile:
            reader = csv.DictReader(csvfile)
            country_name = input("\nВведіть назву країни для пошуку: ")

            found = False
            with open(output_file, "w", newline='', encoding='utf-8') as csvfile2:
                writer = csv.writer(csvfile2)
                writer.writerow(['Country Name', 'GDP per capita (current US$)'])  # Заголовки

                for row in reader:
                    if row['Country Name'].lower() == country_name.lower():
                        found = True
                        print(f"{row['Country Name']}: {row['2019 [YR2019]']}")
                        writer.writerow([row['Country Name'], row['2019 [YR2019]']])

                if not found:
                    print(f"Країну з назвою '{country_name}' не знайдено.")
                    
    except FileNotFoundError:
        print(f"Файл {file_name} не знайдено!")

# Головна частина програми
if __name__ == "__main__":
    input_file = "WorldBankData.csv"  # Назва вхідного файлу
    output_file = "result_gdp_search.csv"  # Назва вихідного файлу

    read_csv(input_file)  # Виводимо вміст файлу
    search_country_gdp(input_file, output_file)  # Пошук за назвою країни

