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
        break; 
        
        // запомнить поинт
        default: 
        gameStatus = CONTINUE; // игрок должен продолжать бросать кубики
        myPoint = sum; // запомнить поинт
        printf( "Point is: %d\n", myPoint );
        break; // не обязательно
    } // конец switch

    // пока игра не завершится
    while( CONTINUE == gameStatus ) { // продолжать бросать кубики
        sum = rollDice();             // бросить кубики

        // определить состояние игры
        if( sum == myPoint ) { // победа при выпадении поинта
            gameStatus = WON;  // игра завершылась победой
        } // конец if
        else {
            if( 7 == sum ) {       // проигрыш при выпадении 7
                gameStatus = LOST; // игра завершилась проигрышем
            } // конец if
        } // конец else
    } // конец while

    // вывести сообщение о победе или выигрыше
    if( WON == gameStatus ) { // игрок выиграл?
        puts( "Player wins" );
    } // конец if
    else {
        puts( "Player loses");
    } // конец else
} // конец main

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