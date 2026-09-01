# Análisis de Algoritmos de Ordenamiento y Estructuras de Datos DAVID MONCADA - CAMILO RODRIGUEZ

Este proyecto implementa, audita y compara empíricamente el rendimiento de tres algoritmos fundamentales de ordenamiento e indexación: **QuickSort**, **HeapSort** y **Árbol AVL**. El sistema está diseñado en C++ moderno y evalúa el comportamiento de estas estructuras sometiéndolas a un conjunto de datos masivo de 100,000 palabras aleatorias.

El objetivo principal es analizar el balance entre el tiempo de ejecución (velocidad) y la complejidad espacial (consumo de memoria RAM) trabajando con memoria dinámica y estructuras *In-Place*.

---

## 🚀 Características Principales

*   **Generación de Dataset Aleatorio:** Selecciona y mezcla 100,000 palabras desde un diccionario base para garantizar un escenario de prueba justo y evitar sesgos de orden previo.
*   **Aislamiento de Pruebas:** Clona los datos en memoria RAM para cada algoritmo, asegurando que todos compitan bajo exactamente las mismas condiciones.
*   **Módulo de Auditoría (Metrics):** Mide el tiempo de ejecución en microsegundos usando `std::chrono` y estima el consumo de memoria en MiB (Mebibytes) basado en la arquitectura de cada estructura.
*   **Verificación Automática:** Incluye un validador iterativo que certifica matemáticamente que el arreglo final cumpla con un ordenamiento alfabético estricto.

---

## 🏗️ Arquitectura del Sistema

El proyecto sigue el Principio de Responsabilidad Única, separando la lógica en módulos específicos (`.h` y `.cpp`):

*   `DatasetManager`: Encargado de la lectura de archivos I/O y la aleatorización (shuffle) de los datos.
*   `QuickSort`: Implementación del algoritmo *Divide y Vencerás* con particionamiento recursivo *In-Place*.
*   `HeapSort`: Implementación iterativa mediante la construcción de un montículo máximo (*Max-Heap*).
*   `AVLTree`: Implementación de un Árbol Binario de Búsqueda auto-balanceable mediante rotaciones simples y dobles, con extracción de datos *In-Order*.
*   `Metrics`: Módulo de evaluación independiente que calcula tiempos, consumo espacial y valida la integridad del ordenamiento.
*   `main.cpp`: Orquestador principal que coordina el flujo de datos y la presentación de resultados.

---

## 📊 Complejidad Teórica Analizada

A continuación se presenta la tabla de complejidades Big O que el programa busca demostrar empíricamente:

| Algoritmo | Complejidad Temporal (Promedio) | Complejidad Temporal (Peor Caso) | Complejidad Espacial |
| :--- | :--- | :--- | :--- |
| **QuickSort** | $O(N \log N)$ | $O(N^2)$ | $O(\log N)$ |
| **HeapSort** | $O(N \log N)$ | $O(N \log N)$ | $O(1)$ |
| **Árbol AVL** | $O(N \log N)$ | $O(N \log N)$ | $O(N)$ |

---

## ⚙️ Requisitos e Instalación

1.  **Entorno de desarrollo:** Recomendado CLion (JetBrains) o cualquier IDE compatible con CMake.
2.  **Compilador:** Soporte para el estándar C++14 o superior.
3.  **Archivo de datos:** Es estrictamente necesario que el archivo fuente `words_alpha.txt` esté ubicado en el directorio de trabajo (o en la raíz del proyecto) antes de la ejecución.

## 🏃‍♂️ Instrucciones de Uso

1.  Clona o descarga este proyecto en tu máquina local.
2.  Abre el proyecto en tu IDE y permite que CMake cargue la configuración automáticamente desde `CMakeLists.txt`.
3.  Asegúrate de que el directorio de trabajo (Working Directory) en tu configuración de ejecución apunte a la carpeta donde reside el archivo `words_alpha.txt`.
4.  Compila y ejecuta el proyecto. El sistema generará el archivo `dataset.txt` y mostrará los resultados en la consola estándar.

---
*Desarrollado para la práctica de Estructuras de Datos y Algoritmos.*
