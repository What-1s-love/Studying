import nltk
import string
import matplotlib.pyplot as plt
from collections import Counter
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.corpus import gutenberg

# Завантаження необхідних ресурсів з NLTK
nltk.download('gutenberg')  # Для текстів з Project Gutenberg
nltk.download('stopwords')  # Для списку стоп-слів
nltk.download('punkt')  # Для токенізації
nltk.download('wordnet')  # Для лемматизації (якщо буде потрібно)

# Завантажуємо текст з Project Gutenberg (наприклад, "Emma" Джейн Остін)
text = gutenberg.raw('austen-emma.txt')

# Функція для підрахунку слів у тексті
def count_words(text):
    sentences = nltk.sent_tokenize(text)  # Токенізація по реченням
    word_count = 0
    for sentence in sentences:
        words = nltk.word_tokenize(sentence)  # Токенізація по словах
        word_count += len(words)
    return word_count

# Функція для знаходження найбільш вживаних слів
def most_used_words(text):
    words = word_tokenize(text.lower())  # Токенізація тексту в нижньому регістрі
    words = [word for word in words if word.isalpha()]  # Видаляємо пунктуацію
    stop_words = set(stopwords.words('english'))  # Отримуємо стоп-слова
    filtered_words = [word for word in words if word not in stop_words]  # Видалення стоп-слів
    word_counts = Counter(filtered_words)  # Підрахунок слів
    common_words = word_counts.most_common(10)  # 10 найбільш вживаних слів

    # Візуалізація на діаграмі
    x = [word[0] for word in common_words]  # Слова
    y = [word[1] for word in common_words]  # Кількість повторів
    plt.bar(x, y)
    plt.title("10 найбільш вживаних слів у тексті")
    plt.xlabel("Слова")
    plt.ylabel("Кількість повторів")
    plt.show()

# Підрахунок слів у тексті
word_count = count_words(text)
print(f"Кількість слів у тексті: {word_count}")

# Визначення 10 найбільш вживаних слів до обробки
most_used_words(text)

# Видалення пунктуації та стоп-слів, потім пошук найбільш вживаних слів
text_no_stopwords = ' '.join([word for word in word_tokenize(text.lower()) if word.isalpha() and word not in stopwords.words('english')])
most_used_words(text_no_stopwords)

