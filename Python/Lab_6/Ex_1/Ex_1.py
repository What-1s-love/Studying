def insert_after_element(lst, target, new_element):
    #Перевіремо чи є елемент у списку
    if target in lst:
        #Отримаємо індекс цього елементу
        index = lst.index(target)
        #Вставляємо новий елемент
        lst.insert(index + 1, new_element)
    else:
        print(f"Елемент {target} не знайдено у списку.")
    return lst

def main():
    #Введення списку з клавіатури
    user_input = input("Введіть елементи списку через пробіл: ")
    lst = user_input.split() #Перетворюємо кожний елемент на список
    target = input("Введіть елемент, після якого потрібно вставити новий елемент: ")
    new_element = input("Введіть новий елемент: ")

    #Вставка нового елементу
    updated_list = insert_after_element(lst, target, new_element)
    print("Оновлений список: ", *updated_list)

if __name__== "__main__":
    main()
