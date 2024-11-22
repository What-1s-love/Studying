import pandas as pd

# Створення DataFrame з існуючого словника
data = {
    "Vitaly_Prikhodko": [12, 10, 9, 10, 5, 7, 8, 5, 12, 10],
    "Dmytro_Kropyvnytskyi": [12, 10, 9, 5, 6, 7, 4, 3, 12, 4],
    "Mikhail_Romanenko": [12, 3, 4, 6, 5, 5, 3, 7, 5, 4],
    "Maxim_Derizemlya": [12, 4, 10, 7, 5, 8, 3, 3, 5, 7],
    "Victoria_Zhuk": [10, 10, 10, 9, 10, 9, 10, 8, 7, 12],
    "Andrey_Kuryanov": [5, 6, 7, 5, 4, 7, 5, 4, 4, 8],
    "Oksana_Dubovets": [7, 8, 5, 8, 8, 9, 8, 7, 7, 10],
    "Nikita_Stroganov": [6, 7, 8, 9, 10, 10, 10, 10, 10, 9],
    "Karina_Nikolaenko": [2, 3, 5, 4, 5, 4, 3, 3, 5, 8]
}

df = pd.DataFrame(data)

# Виведення DataFrame на екран
print(df)

# Вибірка для одного учня
print(df["Vitaly_Prikhodko"])

# Виконання агрегаційних операцій
print("Середнє значення оцінок Vitaly_Prikhodko = ", df["Vitaly_Prikhodko"].mean())
print("Сума оцінок Vitaly_Prikhodko = ", df["Vitaly_Prikhodko"].sum())
print("Мінімальна оцінка Vitaly_Prikhodko = ", df["Vitaly_Prikhodko"].min())
print("Максимальна оцінка Vitaly_Prikhodko = ", df["Vitaly_Prikhodko"].max())
