import pandas as pd
import matplotlib.pyplot as plt

# Завантажуємо дані з CSV
file_path = 'velo_data_2009.csv'  # вказуємо ваш шлях до файлу
df = pd.read_csv(file_path, sep=';', encoding='latin1', parse_dates=['Date'], dayfirst=True, index_col='Date')

# Агрегуємо дані за місяцями
monthly_data = df.resample('M').sum()

# Виводимо дані на екран
print(monthly_data)

# Побудова графіку
plt.figure(figsize=(15, 10))  # розмір графіку
monthly_data.plot()  # побудова лінійного графіку
plt.title('Кількість велосипедистів по місяцях у 2009 році')  # заголовок графіку
plt.xlabel('Місяці')  # підпис осі X
plt.ylabel('Кількість велосипедистів')  # підпис осі Y
plt.grid(True)  # відображення сітки

# Показуємо графік
plt.xticks(monthly_data.index.month, 
           labels=monthly_data.index.strftime('%b'), rotation=45)  # підпис місяців
plt.show()

# Знаходимо найбільш популярний місяць
most_popular_month = monthly_data.idxmax()

# Виводимо найбільш популярний місяць
print("Найбільш популярний місяць:", most_popular_month.strftime('%B %Y'), monthly_data.loc[most_popular_month])
