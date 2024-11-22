﻿# Author: Natan Nedaikhlib
import csv
import json
import sys

def create_csv_file(csv_filename):
    """
    Creates a CSV file and writes data into it.
    """
    try:
        with open(csv_filename, 'w', newline='', encoding='utf-8') as csvfile:
            fieldnames = ['id', 'name', 'age']
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

            # Write the header row
            writer.writeheader()

            # Write data rows
            writer.writerow({'id': '1', 'name': 'Alexander', 'age': '25'})
            writer.writerow({'id': '2', 'name': 'Maria', 'age': '30'})
            writer.writerow({'id': '3', 'name': 'Ivan', 'age': '22'})

    except IOError as e:
        print(f"Error writing to CSV file: {e}")
        sys.exit(1)

def convert_csv_to_json(csv_filename, json_filename):
    """
    Reads data from a CSV file and writes it to a JSON file.
    """
    data_list = []  # Initialize data_list here

    try:
        with open(csv_filename, 'r', encoding='utf-8') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                data_list.append(row)

        data = {'employees': data_list}  # Create the data dictionary after data_list is populated

        with open(json_filename, 'w', encoding='utf-8') as jsonfile:
            json.dump(data, jsonfile, ensure_ascii=False, indent=4)  # Dump 'data' instead of 'data_list'

    except FileNotFoundError:
        print(f"File {csv_filename} not found.")
        sys.exit(1)
    except IOError as e:
        print(f"Error working with files: {e}")
        sys.exit(1)
    except Exception as e:
        print(f"Unknown error: {e}")
        sys.exit(1)
        
# Студентка 2 Шаповал Анастасія         
def convert_json_to_csv(json_filename, csv_filename):
    """
    Reads data from a JSON file and writes it to a CSV file, adding new rows.
    """
    try:
        # Read data from the JSON file
        with open(json_filename, 'r', encoding='utf-8') as jsonfile:
            data = json.load(jsonfile)

        # Check if 'employees' key exists in JSON data
        if 'employees' not in data:
            print(f"Key 'employees' not found in {json_filename}")
            sys.exit(1)

        employees = data['employees']

        # Define fieldnames for the CSV file
        fieldnames = ['id', 'name', 'age']

        # Write data to the CSV file
        with open(csv_filename, 'w', newline='', encoding='utf-8') as csvfile:
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

            # Write the header row
            writer.writeheader()

            # Write rows from JSON data
            for employee in employees:
                writer.writerow(employee)

            # Add new rows to the CSV file
            writer.writerow({'id': '4', 'name': 'Olga', 'age': '28'})
            writer.writerow({'id': '5', 'name': 'Sergey', 'age': '35'})

    except FileNotFoundError:
        print(f"File {json_filename} not found.")
        sys.exit(1)
    except IOError as e:
        print(f"Error working with files: {e}")
        sys.exit(1)
    except Exception as e:
        print(f"Unknown error: {e}")
        sys.exit(1)        

# Студент 3 Суков Микола  
def update_and_convert_csv_to_json(csv_filename, json_filename):
    """
    Reads data from a CSV file, adds new rows, and writes it back to a JSON file.
    """
    data_list = []
    fieldnames = ['id', 'name', 'age']

    try:
        with open(csv_filename, 'r+', newline='', encoding='utf-8') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                data_list.append(row)

            # Add new rows to the CSV data list
            if not any(row['id'] == '6' for row in data_list):
                data_list.append({'id': '6', 'name': 'Artem', 'age': '40'})
            if not any(row['id'] == '7' for row in data_list):
                data_list.append({'id': '7', 'name': 'Anna', 'age': '31'})

            # Move the file cursor to the beginning to overwrite
            csvfile.seek(0)
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(data_list)
            csvfile.truncate()

        data = {'employees': data_list}

        with open(json_filename, 'w', encoding='utf-8') as jsonfile:
            json.dump(data, jsonfile, ensure_ascii=False, indent=4)

    except FileNotFoundError:
        print(f"File {csv_filename} not found.")
        sys.exit(1)
    except IOError as e:
        print(f"Error working with files: {e}")
        sys.exit(1)
    except Exception as e:
        print(f"Unknown error: {e}")
        sys.exit(1)


if __name__ == "__main__":
    csv_filename = 'data_student2.csv'
    json_filename = 'data_student3.json'

    # Update CSV and convert to JSON
    update_and_convert_csv_to_json(csv_filename, json_filename)

    print(f"Data from {csv_filename} successfully updated and converted to {json_filename}")


  # Студент 4 Бєліков Владислав
def convert_json_to_csv_with_updates(json_filename, csv_filename):
    """
    Reads data from a JSON file, adds new rows, and writes it to a new CSV file.
    """
    try:
        # Read data from the JSON file
        with open(json_filename, 'r', encoding='utf-8') as jsonfile:
            data = json.load(jsonfile)

        # Check if 'employees' key exists in JSON data
        if 'employees' not in data:
            print(f"Key 'employees' not found in {json_filename}")
            sys.exit(1)

        employees = data['employees']

        # Add new employees to the data
        if not any(emp['id'] == '8' for emp in employees):
            employees.append({'id': '8', 'name': 'Victor', 'age': '29'})
        if not any(emp['id'] == '9' for emp in employees):
            employees.append({'id': '9', 'name': 'Diana', 'age': '33'})

        # Define fieldnames for the CSV file
        fieldnames = ['id', 'name', 'age']

        # Write updated data to the new CSV file
        with open(csv_filename, 'w', newline='', encoding='utf-8') as csvfile:
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)

            # Write the header row
            writer.writeheader()

            # Write all rows from the updated employee list
            for employee in employees:
                writer.writerow(employee)

    except FileNotFoundError:
        print(f"File {json_filename} not found.")
        sys.exit(1)
    except IOError as e:
        print(f"Error working with files: {e}")
        sys.exit(1)
    except Exception as e:
        print(f"Unknown error: {e}")
        sys.exit(1)


if __name__ == "__main__":
    # Update and convert JSON to a new CSV file
    json_filename = 'data_student3.json'
    new_csv_filename = 'data_student4.csv'

    convert_json_to_csv_with_updates(json_filename, new_csv_filename)

    print(f"Data from {json_filename} successfully converted and saved to {new_csv_filename}")



