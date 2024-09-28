def quick_sort(lst):
    # Базовий випадок рекурсії: якщо список порожній або містить один елемент, він уже відсортований
    if len(lst) <= 1:
        return lst
    else:
        # Вибираємо опорний елемент
        pivot = lst[len(lst) // 2]  # Вибираємо середній елемент як опорний
        left = [x for x in lst if x < pivot]  # Елементи, менші за опорний
        middle = [x for x in lst if x == pivot]  # Елементи, рівні опорному
        right = [x for x in lst if x > pivot]  # Елементи, більші за опорний
        # Рекурсивно сортуємо ліву і праву частини
        return quick_sort(left) + middle + quick_sort(right)

def main():
    # Введення списку з клавіатури
    user_input = input("Введіть елементи списку через пробіл: ")
    # Перетворення введеного рядка у список чисел
    lst = list(map(int, user_input.split()))
    
    # Виклик функції швидкого сортування
    sorted_list = quick_sort(lst)
    
    # Виведення відсортованого списку
    print("Відсортований список:", *sorted_list)

if __name__ == "__main__":
    main()

