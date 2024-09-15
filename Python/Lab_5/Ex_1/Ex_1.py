def generate_fibonacci(n):
    # Створення пустого списку для зберігання чисел Фібоначчі
    fibonacci_sequence = []

    # Перевірка, чи n дійсне число
    if n <= 0:
        print("Кількість елементів повинна бути додатним числом.")
        return fibonacci_sequence

    # Додавання перших елементів послідовності Фібоначчі
    a, b = 1, 1
    for _ in range(n):
        fibonacci_sequence.append(a)
        a, b = b, a + b

    return fibonacci_sequence

def main():
    try:
        # Запит користувача про довжину масиву
        n = int(input("Введіть кількість елементів послідовності Фібоначчі: "))
        
        # Генерація послідовності Фібоначчі
        fibonacci_sequence = generate_fibonacci(n)
        
        # Виведення результату
        print("Послідовність Фібоначчі:")
        print(fibonacci_sequence)
    
    except ValueError:
        print("Будь ласка, введіть дійсне число.")

if __name__ == "__main__":
    main()

