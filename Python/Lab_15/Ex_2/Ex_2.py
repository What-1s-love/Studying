import pandas as pd
import matplotlib.pyplot as plt

# Ігноруємо попередження
import warnings
warnings.filterwarnings("ignore", message="Parsing dates in .*")

# Завантаження файлу
file_path = 'velo_data_2009.csv'
df = pd.read_csv(file_path, sep=';', encoding='latin1', parse_dates=['Date'], index_col='Date')

# Агрегуємо дані за місяцями
monthly_data = df.resample('ME').sum()  # Використовуємо 'ME' замість 'M'

# Побудова стовпчастої діаграми
plt.figure(figsize=(10, 6))  # Збільшуємо висоту графіка
ukrainian_months = [
    "січень", "лютий", "березень", "квітень", "травень", "червень",
    "липень", "серпень", "вересень", "жовтень", "листопад", "грудень"
]
month_numbers = monthly_data.index.month
month_names = [ukrainian_months[m - 1] for m in month_numbers]

plt.bar(month_names, monthly_data['Cyclists'], color='lightblue', edgecolor='black')  # Стовпчики
plt.title('Кількість велосипедистів по місяцях у 2009 році', fontsize=14)
plt.xlabel('Місяці', fontsize=12)
plt.ylabel('Кількість велосипедистів', fontsize=12)
plt.xticks(rotation=45, fontsize=10)  # Обертаємо підписи місяців
plt.grid(axis='y', alpha=0.5)  # Горизонтальна сітка

plt.tight_layout()
plt.show()

# Знаходимо найбільш популярний місяць
most_popular_month = monthly_data.sum(axis=1).idxmax()
month_number = most_popular_month.month
month_name = ukrainian_months[month_number - 1]

# Виводимо лише результат
print(f"Найбільш популярний місяць: {month_number} {month_name}")
