
def fibonacci_numbers(limit):
    """Генерує числа Фібоначчі до заданого ліміту."""
    fib_set = set()
    a, b = 0, 1
    while b <= limit:
        fib_set.add(b)
        a, b = b, a + b
    return fib_set

def main():
    # Створюємо множину від 1 до 50
    num_set = set(range(1, 51))
    
    # Генеруємо числа Фібоначчі до 50
    fib_set = fibonacci_numbers(50)
    
    # Знаходимо перетин множин
    intersection = num_set.intersection(fib_set)
    
    # Кількість чисел Фібоначчі в множині
    count_fib_numbers = len(intersection)

    # Виводимо результат
    print("Множина чисел Фібоначчі:", intersection)
    print("Кількість чисел Фібоначчі від 1 до 50:", count_fib_numbers)

if __name__ == "__main__":
    main()
