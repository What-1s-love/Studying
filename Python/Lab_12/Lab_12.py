import json

# Початкові дані про команди
data = {
    "teams": [
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
}

# Запис початкових даних у JSON файл
with open("teams_data.json", "w", encoding="utf-8") as file:
    json.dump(data, file, ensure_ascii=False, indent=4)

# Функція для додавання нової команди
def add_team(data):
    team_name = input("Введіть назву команди: ")
    points = int(input("Введіть кількість очок: "))
    data["teams"].append({"team": team_name, "points": points})
    data["teams"].sort(key=lambda x: x['points'], reverse=True)
    return data

# Функція для виведення даних про команди
def display_teams(data):
    print("Команди та їх очки:")
    for team in data["teams"]:
        print(f"{team['team']}: {team['points']} points")

# Функція для пошуку місця команди та команд з меншими очками
def find_team_position(data):
    points = int(input("Введіть кількість очок команди: "))
    position = 1
    teams_with_less_points = []

    # Знаходження місця команди
    for team in data["teams"]:
        if points >= team["points"]:
            break
        position += 1

    # Збір команд з меншими очками
    for team in data["teams"][position-1:]:
        teams_with_less_points.append(team)

    # Виведення результатів
    print(f"Команда зайняла {position}-е місце.")
    print("Команди з меншою кількістю очок:")
    for team in teams_with_less_points:
        print(f"{team['team']}: {team['points']} points")

# Головне меню
while True:
    print("\nВиберіть дію:\n 1 - Вивести команди\n 2 - Додати нову команду\n 3 - Знайти місце команди\n 4 - Вийти")
    choice = int(input("Оберіть опцію:\n"))

    # Завантаження даних з JSON файлу
    with open("teams_data.json", "r+", encoding="utf-8") as file:
        data = json.load(file)

        if choice == 1:
            display_teams(data)
        
        elif choice == 2:
            data = add_team(data)
            file.seek(0)
            json.dump(data, file, ensure_ascii=False, indent=4)
            file.truncate()
        
        elif choice == 3:
            find_team_position(data)
        
        elif choice == 4:
            print("Вихід з програми.")
            break
        
        else:
            print("Невірний вибір. Спробуйте ще раз.")
