import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Завантаження даних
file_path = "USAvsUA.csv"
data = pd.read_csv(file_path)

# Отримання років з заголовків
columns = data.columns
year_columns = [col for col in columns if "[YR" in col]  # Фільтрація колонок, що містять роки
years = [int(col.split("[YR")[1][:-1]) for col in year_columns]  # Витягування років

# Фільтрація даних для України та США
ukraine_data = data[data["Country Code"] == "UKR"]
usa_data = data[data["Country Code"] == "USA"]

# Отримання значень для України та США
ukraine_values = ukraine_data[year_columns].replace("..", np.nan).astype(float).values.flatten()
usa_values = usa_data[year_columns].replace("..", np.nan).astype(float).values.flatten()

# Побудова лінійного графіка
plt.figure(figsize=(12, 6))  # Встановлюємо розміри графіка
plt.plot(years, ukraine_values, label="Ukraine", color="blue", marker="o")  # Графік для України
plt.plot(years, usa_values, label="USA", color="red", marker="o")  # Графік для США
plt.title("Comparison of Indicator Between Ukraine and USA", fontsize=16)  # Заголовок
plt.xlabel("Year", fontsize=12)  # Ось X
plt.ylabel("Value", fontsize=12)  # Ось Y
plt.legend()  # Легенда
plt.grid(True)  # Включення сітки
plt.show()  # Відображення графіка

# Побудова стовпчикової діаграми
country_code = input("Enter country code (UKR or USA): ").strip().upper()  # Введення коду країни
if country_code == "UKR":
    values = ukraine_values  # Вибір даних для України
    country_name = "Ukraine"
elif country_code == "USA":
    values = usa_values  # Вибір даних для США
    country_name = "USA"
else:
    print("Invalid country code!")  # Якщо код країни некоректний
    exit()

# Побудова стовпчикової діаграми для вибраної країни
plt.figure(figsize=(12, 6))  # Розмір графіка
plt.bar(years, values, color="green", alpha=0.7)  # Стовпчики для вибраної країни
plt.title(f"Values for {country_name}", fontsize=16)  # Заголовок
plt.xlabel("Year", fontsize=12)  # Ось X
plt.ylabel("Value", fontsize=12)  # Ось Y
plt.xticks(years, rotation=45)  # Поворот підписів на осі X
plt.grid(axis="y")  # Сітка тільки по осі Y
plt.show()  # Відображення діаграми
