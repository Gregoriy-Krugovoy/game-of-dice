// Имитация игры в кости

#include <stdio.h> // input / output
#include <stdlib.h> // rand / srand
#include <time.h> // содержит прототип функции time

enum Status { CONTINUE, WON, LOST }; // перечисление констант, передставляющих состояние игры

int rollDice( void ); // прототип функции

int main( void )
{
    int sum; // сумма выпавшых очков
    int myPoint; // игрок должен сделать этот пойнт, чтобы выиграть

    enum Status gameStatus; // мог содержать CONTINUE, WON или LOST

    srand( time( NULL ) ); // рандомизировать генератор случайных чисел текущим временем

    sum = rollDice(); // первый бросок кубиков

    // определить состояние игры на основе суммы
    switch( sum ) {
        
        // выигрыш в первом броске
        case 7: // 7 - победа
        case 11: // 11 - победа
        gameStatus = WON; // игра завершилась победой
        break;

        // проигрыш в первом броске
        case 2: // 2 - проигрыш
        case 3: // 3 - проигрыш
        case 12: // 12 - проигрыш
        gameStatus = LOST; // игра завершилась проигрышем

    }

}

int rollDice( void ) // имитирует бросок кубиков, вычисляет сумму и выводит ее 
    {
        int die1; // первый кубик
        int die2; // второй кубик
        int workSum; // сумма

        die1 = 1 + ( rand() % 6 ); // получить первое случайное значение
        die2 = 1 + ( rand() % 6 ); // получить второе число
        workSum = die1 + die2;

        printf( "    Player rolled %d + %d = %d", die1, die2, workSum ); // вывести результат бросков
        
        return workSum;
    } // конец функции rollDice