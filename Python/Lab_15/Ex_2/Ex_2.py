import pandas as pd
import matplotlib.pyplot as plt

# Завантажуємо дані з файлу
file_path = 'velo_data_2009.csv'
df = pd.read_csv(file_path, sep=';', encoding='latin1', parse_dates=['Date'], dayfirst=False, index_col='Date')

# Ресемплінг даних по місяцях
monthly_data = df.resample('ME').sum()

# Знаходимо найбільш популярний місяць
most_popular_month = monthly_data.idxmax()

print("Найбільш популярний місяць:", most_popular_month, monthly_data.loc[most_popular_month])

# Побудова графіку
plt.figure(figsize=(10, 6))
monthly_data.plot(kind='bar', color='skyblue')
plt.title("Відвідування велодоріжок у 2009 році")
plt.xlabel("Місяць")
plt.ylabel("Кількість велосипедистів")
plt.xticks(rotation=45)
plt.tight_layout()
plt.show()
