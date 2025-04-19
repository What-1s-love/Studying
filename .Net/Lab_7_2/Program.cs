using System;

public class Person
{
    public string Name { get; set; }
    public int Age { get; set; }

    public Person(string name, int age)
    {
        Name = name;
        Age = age;
    }

    public virtual void DisplayInfo()
    {
        Console.WriteLine($"Name: {Name}, Age: {Age}");
    }
}

public class Student : Person
{
    public string Course { get; set; }

    public Student(string name, int age, string course) : base(name, age)
    {
        Course = course;
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Course: {Course}");
    }
}

public class Teacher : Person
{
    public string Subject { get; set; }

    public Teacher(string name, int age, string subject) : base(name, age)
    {
        Subject = subject;
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Subject: {Subject}");
    }
}

public class DepartmentHead : Teacher
{
    public string DepartmentName { get; set; }

    public DepartmentHead(string name, int age, string subject, string departmentName)
        : base(name, age, subject)
    {
        DepartmentName = departmentName;
    }

    public override void DisplayInfo()
    {
        base.DisplayInfo();
        Console.WriteLine($"Department: {DepartmentName}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        // Створюємо об'єкти різних класів
        Person person = new Person("John Doe", 45);
        Student student = new Student("Alice Johnson", 21, "Computer Science");
        Teacher teacher = new Teacher("Dr. Smith", 40, "Mathematics");
        DepartmentHead departmentHead = new DepartmentHead("Prof. Brown", 50, "Physics", "Department of Physics");

        // Виводимо інформацію про кожну людину
        Console.WriteLine("Person Info:");
        person.DisplayInfo();
        Console.WriteLine();

        Console.WriteLine("Student Info:");
        student.DisplayInfo();
        Console.WriteLine();

        Console.WriteLine("Teacher Info:");
        teacher.DisplayInfo();
        Console.WriteLine();

        Console.WriteLine("Department Head Info:");
        departmentHead.DisplayInfo();
    }
}
