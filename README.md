# Payroll Management System in C++

This project is a console-based application written in **C++** to manage the payroll of a company. It was developed as the final project for the **Introduction to Programming** course at the **Pontificia Universidad Javeriana**.

## 🚀 Features

The system handles three types of employees: **Administrative Staff**, **Professors**, and **Monitors**, each with specific attributes and salary rules.

### 📋 Menu Options:

1. Load employees from a `Nomina.txt` file  
2. Add a new employee  
3. Delete an employee by ID  
4. Add a subject to a professor  
5. Add a subject to a monitor  
6. Calculate the salary of an employee  
7. Calculate the salary of a professor  
8. Calculate the salary of a monitor  
9. Generate the payroll report in `Reporte.txt`  
0. Exit

---

## 🧠 Project Structure

The system is based on `struct`s to organize the data:

- `Empleado`: name, surname, ID, job type, salary  
- `Cargo`: position, rank (if applicable), list of subjects  
- `Asignatura`: subject name and number of hours

---

## 💸 Salary Calculation Rules

- **Employee**:  
  `salary = minimum_wages * 1,000,000 * 0.75` (includes legal deductions)

- **Professor**:  
  `salary = rank * minimum_wage * (total_hours * 0.75)`  
  Ranks:
    - Catedra → 0.5  
    - Instructor → 1  
    - Assistant → 1.5  
    - Associate → 2  
    - Full (Titular) → 2.5  

- **Monitor**:  
  `salary = total_hours * 7,197` (no deductions applied)

---

## 🛠️ How to Compile and Run (on macOS)

```bash
clang++ Proyecto_final.cpp -o nomina
./nomina
```
Or with g++ if installed:
```bash
g++ Proyecto_final.cpp -o nomina
./nomina
```

### 📌 Considerations

- Duplicate employees are not allowed.
- When an employee is deleted, the array is reorganized to preserve structure,
- Salary is calculated manually through menu options (6, 7, and 8).
- The system uses static arrays and simple structs.
- No pointers or references are used, in accordance with the course's scope.
- The `cantidad_empleados` variable is managed globally for simplicity.

---

### 📚 Credits

- **Proyect developed by**: Juan Camilo Carvajal Rodríguez
- **Course**: Introduction to Programming 
- **University**: Pontificia Universidad Javeriana  
- **Professor**: Jose Hernando Hurtado Rojas
