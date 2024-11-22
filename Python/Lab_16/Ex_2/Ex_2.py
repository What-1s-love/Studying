import nltk
from nltk.tokenize import word_tokenize  # Додаємо імпорт функції word_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer, PorterStemmer
import string

# Завантажуємо необхідні ресурси
nltk.download('punkt')  # Для токенізації
nltk.download('stopwords')  # Для списку стоп-слів
nltk.download('wordnet')  # Для лемматизації

# Зчитуємо текст з файлу
text = '''This is a simple example text. You can add more text here as you like. 
          The goal is to process this text and perform tokenization, lemmatization, and stemming.'''

# Токенізація по словах
words = word_tokenize(text)

# Лемматизація
lemmatizer = WordNetLemmatizer()
lemmatized_words = [lemmatizer.lemmatize(word) for word in words]

# Стеммінг
stemmer = PorterStemmer()
stemmed_words = [stemmer.stem(word) for word in words]

# Видалення стоп-слів
stop_words = set(stopwords.words('english'))
filtered_words = [word for word in words if word.lower() not in stop_words]

# Видалення пунктуації
filtered_words_no_punctuation = [word for word in filtered_words if word not in string.punctuation]

# Виведення результатів
print("Original Text:", text)
print("Tokenized Words:", words)
print("Lemmatized Words:", lemmatized_words)
print("Stemmed Words:", stemmed_words)
print("Filtered Words (no stopwords):", filtered_words)
print("Filtered Words (no punctuation):", filtered_words_no_punctuation)

# Записуємо оброблений текст у файл
with open('processed_text.txt', 'w') as f:
    f.write(" ".join(filtered_words_no_punctuation))
