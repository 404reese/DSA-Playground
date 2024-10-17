import java.util.Scanner;

// Parent class Person
class Person {
    private String name;
    private int age;

    // Constructor for Person
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    // Display method
    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}

// Child class Employee; inheritance from Person
class Employee extends Person {
    private String employeeID;
    private double salary;

    // Constructor for Employee
    public Employee(String name, int age, String employeeID, double salary) {
        // Parent class call
        super(name, age);
        this.employeeID = employeeID;
        this.salary = salary;
    }

    // Display method of Employee
    public void employeeDetail() {
        System.out.println("Employee ID: " + employeeID);
        System.out.println("Salary: INR" + salary);
        // displayInfo method from parent class
        super.displayInfo();
    }
}

// Main class
public class OOPM_5A {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Prompt for and read Person details
        System.out.print("Enter name: ");
        String name = scanner.nextLine();

        System.out.print("Enter age: ");
        int age = scanner.nextInt();

        // Consume the leftover newline character
        scanner.nextLine();

        // Prompt for and read Employee details
        System.out.print("Enter employee ID: ");
        String employeeID = scanner.nextLine();

        System.out.print("Enter salary: ");
        double salary = scanner.nextDouble();

        // Employee instance with input
        Employee emp = new Employee(name, age, employeeID, salary);

        // Display Employee details
        emp.employeeDetail();

        scanner.close();
    }
}
