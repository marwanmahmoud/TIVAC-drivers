#include "Uart.h"

int main ()
{

UART_Init(UART00,UART_BAUD_9600);
print_string(UART00,"Mostafa");
}