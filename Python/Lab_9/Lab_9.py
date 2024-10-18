import string

# Функція для відкриття файлу з обробкою помилок
def open_file(file_name, mode):
    try:
        file = open(file_name, mode, encoding='utf-8')
    except FileNotFoundError:
        print(f"Файл {file_name} не був знайдений!")
        return None
    except IOError:
        print(f"Помилка вводу/виводу при відкритті файлу {file_name}!")
        return None
    else:
        print(f"Файл {file_name} був успішно відкритий!")
        return file

# а) Створюємо файл TF1_1.txt і записуємо в нього текст
file1_name = 'TF1_1.txt'
file1 = open_file(file1_name, 'w')
if file1:
    try:
        file1.write("Привіт, це перший тестовий рядок!\n")
        file1.write("Ось ще один рядок з різними, розділовими знаками.\n")
        file1.write("Python - це чудова мова програмування.")
        print(f"Інформація успішно записана в {file1_name}!")
    finally:
        file1.close()
        print(f"Файл {file1_name} був закритий!")

# б) Читаємо вміст файлу TF1_1.txt, видаляємо розділові знаки і записуємо кожне слово в новий файл TF1_2.txt
file1 = open_file(file1_name, 'r')
file2_name = 'TF1_2.txt'
file2 = open_file(file2_name, 'w')

if file1 and file2:
    try:
        for line in file1:
            # Видаляємо всі розділові знаки
            words = line.translate(str.maketrans('', '', string.punctuation)).split()
            # Записуємо кожне слово в новий рядок у файл TF1_2.txt
            for word in words:
                file2.write(word + '\n')
        print(f"Слова успішно записані в {file2_name}!")
    finally:
        file1.close()
        file2.close()
        print(f"Файли {file1_name} та {file2_name} були закриті!")

# в) Читаємо вміст файлу TF1_2.txt і виводимо його на екран
file2 = open_file(file2_name, 'r')

if file2:
    try:
        for line in file2:
            print(line.strip())
    finally:
        file2.close()
        print(f"Файл {file2_name} був закритий!")
