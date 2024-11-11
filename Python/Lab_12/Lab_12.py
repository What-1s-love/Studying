import json

# Функція для створення початкового JSON файлу з інформацією про команди
def create_json_file(filename):
    teams = [
        {"team": "Team A", "points": 35},
        {"team": "Team B", "points": 30},
        {"team": "Team C", "points": 28},
        {"team": "Team D", "points": 25},
        {"team": "Team E", "points": 22},
        {"team": "Team F", "points": 20},
        {"team": "Team G", "points": 18},
        {"team": "Team H", "points": 15},
        {"team": "Team I", "points": 12}
    ]
    with open(filename, 'w', encoding='utf-8') as file:
        json.dump(teams, file, ensure_ascii=False, indent=4)

# Функція для виведення вмісту JSON файлу
def display_json_content(filename):
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            data = json.load(file)
            for team in data:
                print(f"{team['team']}: {team['points']} points")
    except FileNotFoundError:
        print(f"Файл {filename} не знайдено!")

# Функція для додавання нової команди в JSON файл
def add_team(filename, team_name, points):
    try:
        with open(filename, 'r+', encoding='utf-8') as file:
            data = json.load(file)
            data.append({"team": team_name, "points": points})
            data.sort(key=lambda x: x['points'], reverse=True)  # Сортування за очками
            file.seek(0)
            json.dump(data, file, ensure_ascii=False, indent=4)
            file.truncate()
    except FileNotFoundError:
        print(f"Файл {filename} не знайдено!")

# Функція для пошуку місця та виведення команд з меншою кількістю очок
def find_team_position(filename, points, output_file):
    try:
        with open(filename, 'r', encoding='utf-8') as file:
            data = json.load(file)
            position = 1
            teams_with_less_points = []
            
            # Знаходимо місце команди
            for team in data:
                if points >= team["points"]:
                    break
                position += 1
            
            # Виводимо команди з меншою кількістю очок
            for team in data[position-1:]:
                teams_with_less_points.append(team)
            
            # Записуємо результат у новий JSON файл
            with open(output_file, 'w', encoding='utf-8') as out_file:
                json.dump({"position": position, "teams_with_less_points": teams_with_less_points}, out_file, ensure_ascii=False, indent=4)
            
            print(f"Команда зайняла {position}-е місце.")
            print("Команди з меншою кількістю очок:")
            for team in teams_with_less_points:
                print(f"{team['team']}: {team['points']} points")
                
    except FileNotFoundError:
        print(f"Файл {filename} не знайдено!")

# Головна частина програми з меню для вибору дій
if __name__ == "__main__":
    json_file = "teams_data.json"
    result_file = "result_data.json"

    # Створюємо початковий JSON файл
    create_json_file(json_file)

    while True:
        print("\nОберіть дію:")
        print("1. Вивести вміст JSON файлу")
        print("2. Додати нову команду")
        print("3. Знайти місце команди та команди з меншою кількістю очок")
        print("4. Вийти")

        choice = input("Введіть номер дії: ")
        
        if choice == '1':
            display_json_content(json_file)
        
        elif choice == '2':
            team_name = input("Введіть назву команди: ")
            points = int(input("Введіть кількість очок: "))
            add_team(json_file, team_name, points)
        
        elif choice == '3':
            points = int(input("Введіть кількість очок команди: "))
            find_team_position(json_file, points, result_file)
        
        elif choice == '4':
            print("Вихід з програми.")
            break
        
        else:
            print("Невірний вибір. Спробуйте ще раз.")
