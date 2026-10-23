/*
  Студент: Шпаков Максим Денисович
  Группа: ПИ 1-1
  Номер в списке: 31
  Вариант: 9
  Назначение: Консольная программа на языке C для ввода, валидации и статистического анализа одномерного массива целых чисел. Дополнительно программа находит значение (или несколько значений), которое встречается в массиве чаще остальных.
*/


#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int array[], int size);
void printArray(const int array[], int size);
int findMin(const int array[], int size);
int findMax(const int array[], int size);
long long calculateSum(const int array[], int size);
double calculateAverage(const int array[], int size);
void performIndividualTask(const int array[], int size);
int findFirstIndex(const int array[], int size, int value);
void printSignCounts(const int array[], int size);
void printParityCounts(const int array[], int size);
void printElementsInRange(const int array[], int size, int a, int b);

int main(void)
{
    int array[MAX_SIZE];
    int size;

    printf("Введите размер массива от 1 до %d: ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE)
    {
        printf("Ошибка: недопустимый размер массива.\n");
        return 1;
    }

    inputArray(array, size);
    printArray(array, size);

    /* Находим мин., макс. и их 1 инд. */
    int minVal = findMin(array, size);
    int minIdx = findFirstIndex(array, size, minVal);
    printf("Минимальный элемент: %d (первый индекс: %d)\n", minVal, minIdx);

    int maxVal = findMax(array, size);
    int maxIdx = findFirstIndex(array, size, maxVal);
    printf("Максимальный элемент: %d (первый индекс: %d)\n", maxVal, maxIdx);

    /* Сум. и ср.ариф */
    long long sum = calculateSum(array, size);
    double avg = calculateAverage(array, size);
    printf("Сумма элементов: %lld\n", sum);
    printf("Среднее арифметическое: %.2f\n", avg);

    /* Подсчёт полож/отриц/нул и чёт/нечёт*/
    printSignCounts(array, size);
    printParityCounts(array, size);

    /* Диапазон [a, b] */
    int a, b;
    printf("Введите границы диапазона a и b: ");
    if (scanf("%d %d", &a, &b) != 2)
    {
        printf("Ошибка: некорректный ввод границ.\n");
        return 1;
    }
    printElementsInRange(array, size, a, b);

    /*(Вариант 9)*/
    performIndividualTask(array, size);

    return 0;
}

/* Ввод эл. мас. */
void inputArray(int array[], int size)
{
    printf("Введите %d целых чисел: ", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
}

/* Вывод масс в 1 стр. */
void printArray(const int array[], int size)
{
    printf("Исходный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/* Поиск мин. эл. */
int findMin(const int array[], int size)
{
    int min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}

/* Поиск макс. эл. */
int findMax(const int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

/* Поиск 1 инд. числа */
int findFirstIndex(const int array[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == value)
        {
            return i;
        }
    }
    return 0;
}

/* Вычис. сум. эл.*/
long long calculateSum(const int array[], int size)
{
    long long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum = sum + array[i];
    }
    return sum;
}

/* Вычис. ср. ариф.*/
double calculateAverage(const int array[], int size)
{
    long long sum = calculateSum(array, size);
    return (double)sum / size;
}

/* Подсчёт полож., отриц. и нул. эл.*/
void printSignCounts(const int array[], int size)
{
    int pos = 0;
    int neg = 0;
    int zero = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] > 0)
        {
            pos++;
        }
        else if (array[i] < 0)
        {
            neg++;
        }
        else
        {
            zero++;
        }
    }
    printf("Положительных: %d, отрицательных: %d, нулевых: %d\n", pos, neg, zero);
}

/* Подсчёт чёт. и нечёт. эл.*/
void printParityCounts(const int array[], int size)
{
    int even = 0;
    int odd = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("Чётных: %d, нечётных: %d\n", even, odd);
}

/* Вывод эл. из диап. [a, b] */
void printElementsInRange(const int array[], int size, int a, int b)
{
    /* Если a > b, меняем их местами */
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    printf("Элементы в диапазоне [%d, %d]: ", a, b);
    int found = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] >= a && array[i] <= b)
        {
            printf("%d ", array[i]);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("нет таких элементов");
    }
    printf("\n");
}

/* Вариант 9 (Наиболее частый элемент) */
void performIndividualTask(const int array[], int size)
{
    int maxCount = 0;

    /* 1. Счет самого част. эл. */
    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[j] == array[i])
            {
                count++;
            }
        }
        if (count > maxCount)
        {
            maxCount = count;
        }
    }

    /* 2. Вывод всех эл., которые в "maxCount" раз (без повт.) */
    printf("Наиболее частый элемент (встречается %d раз): ", maxCount);
    for (int i = 0; i < size; i++)
    {
        /* Пров. вывода (было это числ. или нет) */
        int alreadyPrinted = 0;
        for (int k = 0; k < i; k++)
        {
            if (array[k] == array[i])
            {
                alreadyPrinted = 1;
                break;
            }
        }

        /* Если числ 1 , то счит. его кол-во. в мас. */
        if (alreadyPrinted == 0)
        {
            int count = 0;
            for (int j = 0; j < size; j++)
            {
                if (array[j] == array[i])
                {
                    count++;
                }
            }

            if (count == maxCount)
            {
                printf("%d ", array[i]);
            }
        }
    }
    printf("\n");
}
