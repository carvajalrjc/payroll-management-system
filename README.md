# Sistema de Gestión de Nómina en C++

Este proyecto es una aplicación de consola escrita en **C++** que permite gestionar la nómina de una empresa. Fue desarrollado como proyecto final para el curso **Introducción a la Programación** en la **Pontificia Universidad Javeriana**.

## 🚀 Funcionalidades

El sistema permite manejar tres tipos de empleados: **Empleados Administrativos**, **Profesores** y **Monitores**, con características y reglas de salario específicas para cada uno.

### 📋 Menú de opciones:

1. Cargar empleados desde un archivo `Nomina.txt`
2. Agregar un nuevo empleado
3. Eliminar un empleado por cédula
4. Añadir asignatura a un profesor
5. Añadir asignatura a un monitor
6. Calcular salario de un empleado
7. Calcular salario de un profesor
8. Calcular salario de un monitor
9. Generar el reporte de nómina en `Reporte.txt`
0. Salir

---

## 🧠 Estructura del proyecto

El sistema se basa en estructuras (`struct`) para organizar los datos:

- `Empleado`: nombre, apellido, cédula, tipo de cargo, salario
- `Cargo`: puesto, escalafón (si aplica), lista de asignaturas
- `Asignatura`: nombre y número de horas

---

## 💸 Reglas de cálculo de salario

- **Empleado**:  
  `salario = salarios_mínimos * 1.000.000 * 0.75` (descuento de ley)

- **Profesor**:  
  `salario = escalafón * salario_mínimo * (total_horas * 0.75)`  
  Escalafones:
    - Catedra → 0.5  
    - Instructor → 1  
    - Asistente → 1.5  
    - Asociado → 2  
    - Titular → 2.5  

- **Monitor**:  
  `salario = total_horas * 7.197` (no hay descuentos)

---

## 🛠️ Cómo compilar y ejecutar (en macOS)

```bash
clang++ Proyecto_final.cpp -o nomina
./nomina
```
O con g++ si lo tienes 
```bash
g++ Proyecto_final.cpp -o nomina
./nomina
```

### 📌 Consideraciones

- No se permiten empleados duplicados.
- Al eliminar un empleado, se reacomoda el arreglo para mantener la integridad de la lista.
- El cálculo del salario se realiza manualmente a través del menú (opciones 6, 7 y 8).
- El sistema utiliza arreglos estáticos y estructuras (`struct`).
- No se usaron punteros ni referencias, de acuerdo con los temas cubiertos en el curso.
- La variable `cantidad_empleados` se maneja como global para simplificar el flujo de datos.

---

### 📚 Créditos

- **Proyecto desarrollado por**: Juan Camilo Carvajal Rodríguez
- **Curso**: Introducción a la Programación  
- **Universidad**: Pontificia Universidad Javeriana  
- **Profesor**: Jose Hernando Hurtado Rojas
