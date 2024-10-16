import string

# a) Створюємо файл TF1_1.txt і записуємо в нього текст
with open('TF1_1.txt', 'w', encoding='utf-8') as file1:
    file1.write("Привіт, це перший тестовий рядок!\n")
    file1.write("Ось ще один рядок з різними, розділовими знаками.\n")
    file1.write("Python - це чудова мова програмування.")

# б) Читаємо вміст файла TF1_1, видаляємо розділові знаки і записуємо кожне слово в новий файл TF1_2.txt
with open('TF1_1.txt', 'r', encoding='utf-8') as file1, open('TF1_2.txt', 'w', encoding='utf-8') as file2:
    for line in file1:
        # Видаляємо всі розділові знаки за допомогою translate і string.punctuation
        words = line.translate(str.maketrans('', '', string.punctuation)).split()
        # Записуємо кожне слово в новий рядок у файл TF1_2.txt
        for word in words:
            file2.write(word + '\n')

# в) Читаємо вміст файла TF1_2.txt і виводимо його на екран
with open('TF1_2.txt', 'r', encoding='utf-8') as file2:
    for line in file2:
        print(line.strip())
