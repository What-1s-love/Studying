# Початковий словник з назвами команд як ключами та очками як значеннями
football_teams = {
    'Team1': 38,
    'Team2': 35,
    'Team3': 33,
    'Team4': 30,
    'Team5': 28,
    'Team6': 26,
    'Team7': 24,
    'Team8': 20,
    'Team9': 18
}

# Функція для виведення всіх команд та їх очок
def display_teams(teams_dict):
    for team, points in teams_dict.items():
        print(f"{team}: {points} points")

# Функція для додавання або видалення команди
def modify_team(teams_dict, team_name, points=None):
    if points is not None:
        teams_dict[team_name] = points
        print(f"Додано/Оновлено команду {team_name} з {points} очками.")
    else:
        try:
            del teams_dict[team_name]
            print(f"Видалено команду {team_name}.")
        except KeyError:
            print(f"Помилка: Команду {team_name} не знайдено.")

# Функція для перегляду команд, відсортованих за очками або назвою
def sorted_teams(teams_dict, by="points"):
    if by == "points":
        sorted_teams_list = sorted(teams_dict.items(), key=lambda x: x[1], reverse=True)
    else:
        sorted_teams_list = sorted(teams_dict.items())
    
    for team, points in sorted_teams_list:
        print(f"{team}: {points} очок")

# Функція для визначення місця та слабших команд для 10-ї команди
def find_team_position(teams_dict, team_name):
    sorted_by_points = sorted(teams_dict.items(), key=lambda x: x[1], reverse=True)
    team_points = teams_dict.get(team_name)
    position = None
    weaker_teams = []

    for i, (team, points) in enumerate(sorted_by_points):
        if team == team_name:
            position = i + 1  # Оскільки індексація починається з 0
        elif points < team_points:
            weaker_teams.append(team)
    
    if position:
        print(f"{team_name} на {position} місці. Команди з меншими очками: {', '.join(weaker_teams)}")
    else:
        print(f"Команду {team_name} не знайдено.")

# Приклад використання
print("Початкові команди та очки:")
display_teams(football_teams)

print("\nДодавання 10-ї команди:")
modify_team(football_teams, 'Team10', 29)

print("\nВиведення відсортованих команд за очками:")
sorted_teams(football_teams, by="points")

print("\nВизначення місця команди Team10:")
find_team_position(football_teams, 'Team10')

print("\nВидалення команди Team9:")
modify_team(football_teams, 'Team9')

print("\nФінальні команди та очки:")
display_teams(football_teams)

