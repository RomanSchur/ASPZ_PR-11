#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
volatile sig_atomic_t timeout_occurred = 0;

void check(int sig) {
    timeout_occurred = 1;
}

int main() {
    int timeout_seconds = 5;
    int input;

    printf("Будь ласка, введіть ціле число протягом 5 секунд: \n");

    signal(SIGALRM, check);

    alarm(timeout_seconds);

    scanf("%d", &input);

    alarm(0);

    if (timeout_occurred) {
        printf("Час вийшов! Введення не було отримано вчасно.\n");
    } else {
        printf("Введення успішне: %d\n", input);
    }

    return 0;
}