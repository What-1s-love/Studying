import json
import matplotlib.pyplot as plt

# Завантажуємо дані з JSON файлу
with open("teams_data.json", "r", encoding="utf-8") as file:
    data = json.load(file)

# Отримуємо список команд і їх очок
teams = [team["team"] for team in data["teams"]]
points = [team["points"] for team in data["teams"]]

# Створення кругової діаграми
fig, ax = plt.subplots()
ax.pie(points, labels=teams, autopct='%1.1f%%', startangle=90, colors=plt.cm.Paired.colors)

# Робимо кругову діаграму круглою
ax.axis('equal')

# Додаємо заголовок
plt.title("Розподіл очок між командами")

# Відображаємо графік
plt.show()

