import requests
from bs4 import BeautifulSoup
import csv
import time

# Функція для виконання HTTP-запиту
def get_html(url):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            return response.text  # Повертаємо HTML-код
        else:
            print(f"Error: HTTP {response.status_code}")  # Помилка при отриманні даних
            return None
    except requests.exceptions.RequestException as e:
        print(f"Error during request: {e}")  # Виведення помилки з підключенням
        return None

# Функція для парсингу HTML та отримання заголовків
def parse_html(html):
    soup = BeautifulSoup(html, 'html.parser')
    titles = [title.text.strip() for title in soup.find_all(['h1', 'h2', 'h3'])]  # Шукаємо заголовки h1, h2, h3
    return titles

# Функція для виведення результатів на екран
def print_titles(titles, url):
    if not titles:
        print(f"No titles found on the page: {url}")
    else:
        print(f"\nFound Titles on {url}:")
        for i, title in enumerate(titles, 1):
            print(f"{i}. {title}")

# Функція для збереження результатів у файл CSV
def save_to_csv(titles, url):
    with open("titles.csv", "a", newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        for title in titles:
            writer.writerow([url, title])  # Записуємо URL та заголовок

# Головна функція програми
def main():
    urls = input("Enter URLs separated by commas: ").split(',')  # Користувач вводить кілька URL через кому
    for url in urls:
        url = url.strip()  # Обрізаємо зайві пробіли
        print(f"\nProcessing URL: {url}")
        html = get_html(url)  # Отримуємо HTML-код
        if html:
            titles = parse_html(html)  # Парсимо HTML для отримання заголовків
            print_titles(titles, url)  # Виводимо заголовки на екран
            save_to_csv(titles, url)  # Зберігаємо заголовки у файл CSV
            time.sleep(2)  # Затримка перед обробкою наступної сторінки

if __name__ == "__main__":
    main()
