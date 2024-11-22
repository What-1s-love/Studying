import nltk
import string
import matplotlib.pyplot as plt
from collections import Counter
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize
from nltk.corpus import gutenberg

# ������������ ���������� ������� � NLTK
nltk.download('gutenberg')  # ��� ������ � Project Gutenberg
nltk.download('stopwords')  # ��� ������ ����-���
nltk.download('punkt')  # ��� ����������
nltk.download('wordnet')  # ��� ������������ (���� ���� �������)

# ����������� ����� � Project Gutenberg (���������, "Emma" ����� ����)
text = gutenberg.raw('austen-emma.txt')

# ������� ��� ��������� ��� � �����
def count_words(text):
    sentences = nltk.sent_tokenize(text)  # ���������� �� ��������
    word_count = 0
    for sentence in sentences:
        words = nltk.word_tokenize(sentence)  # ���������� �� ������
        word_count += len(words)
    return word_count

# ������� ��� ����������� ������� �������� ���
def most_used_words(text):
    words = word_tokenize(text.lower())  # ���������� ������ � �������� ������
    words = [word for word in words if word.isalpha()]  # ��������� ����������
    stop_words = set(stopwords.words('english'))  # �������� ����-�����
    filtered_words = [word for word in words if word not in stop_words]  # ��������� ����-���
    word_counts = Counter(filtered_words)  # ϳ�������� ���
    common_words = word_counts.most_common(10)  # 10 ������� �������� ���

    # ³��������� �� ������
    x = [word[0] for word in common_words]  # �����
    y = [word[1] for word in common_words]  # ʳ������ �������
    plt.bar(x, y)
    plt.title("10 ������� �������� ��� � �����")
    plt.xlabel("�����")
    plt.ylabel("ʳ������ �������")
    plt.show()

# ϳ�������� ��� � �����
word_count = count_words(text)
print(f"ʳ������ ��� � �����: {word_count}")

# ���������� 10 ������� �������� ��� �� �������
most_used_words(text)

# ��������� ���������� �� ����-���, ���� ����� ������� �������� ���
text_no_stopwords = ' '.join([word for word in word_tokenize(text.lower()) if word.isalpha() and word not in stopwords.words('english')])
most_used_words(text_no_stopwords)

