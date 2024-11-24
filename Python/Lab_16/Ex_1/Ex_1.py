import nltk
import string
import matplotlib.pyplot as plt
from collections import Counter
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.corpus import gutenberg

# Завантаження необхідних ресурсів з NLTK
nltk.download('gutenberg')
nltk.download('stopwords')
nltk.download('punkt')

# Завантажуємо текст з Project Gutenberg
text = gutenberg.raw('austen-emma.txt')

# Функція для підрахунку кількості слів у тексті
def count_words(text):
    words = nltk.word_tokenize(text)  # Токенізація тексту по словах
    return len(words)

# Підрахунок кількості слів
word_count = count_words(text)
print(f"Кількість слів у тексті: {word_count}")

# Функція для побудови графіка
def plot_word_frequency(word_counts, title):
    common_words = word_counts.most_common(10)  # Топ-10 найбільш вживаних слів
    x = [word[0] for word in common_words]  # Слова
    y = [word[1] for word in common_words]  # Кількість повторів
    plt.bar(x, y)
    plt.title(title)
    plt.xlabel("Слова")
    plt.ylabel("Кількість повторів")
    plt.show()

# Функція для обробки тексту
def analyze_text(text, remove_stopwords=False):
    words = word_tokenize(text.lower())  # Токенізація тексту в нижньому регістрі
    words = [word for word in words if word.isalpha()]  # Видалення пунктуації

    if remove_stopwords:
        stop_words = set(stopwords.words('english'))
        words = [word for word in words if word not in stop_words]  # Видалення стоп-слів

    word_counts = Counter(words)  # Підрахунок слів
    return word_counts

# Аналіз тексту до видалення стоп-слів
word_counts_original = analyze_text(text, remove_stopwords=False)
plot_word_frequency(word_counts_original, "Топ-10 слів ДО видалення стоп-слів")

# Аналіз тексту після видалення стоп-слів
word_counts_no_stopwords = analyze_text(text, remove_stopwords=True)
plot_word_frequency(word_counts_no_stopwords, "Топ-10 слів ПІСЛЯ видалення стоп-слів")


