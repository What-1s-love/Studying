import requests
from bs4 import BeautifulSoup

# Функція для виконання HTTP-запиту
def get_html(url):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            return response.text
        else:
            print(f"Error: HTTP {response.status_code}")
            return None
    except Exception as e:
        print(f"Error during request: {e}")
        return None

# Функція для аналізу HTML і пошуку заголовків
def parse_html(html):
    soup = BeautifulSoup(html, 'html.parser')
    # Знаходимо всі теги <h2> на сторінці
    titles = [title.text.strip() for title in soup.find_all('h2')]
    return titles

# Функція для виведення результатів
def print_titles(titles):
    if not titles:
        print("No titles found on the page.")
    else:
        print("\nFound Titles:")
        for i, title in enumerate(titles, 1):
            print(f"{i}. {title}")

# Основна функція програми
def main():
    url = input("Enter the URL of the webpage: ")
    html = get_html(url)
    if html:
        titles = parse_html(html)
        print_titles(titles)

if __name__ == "__main__":
    main()

