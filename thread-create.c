#include <pthread.h>
#include <stdio.h>

/* Imprime repetidamente o caractere passado */
void* print_char(void* arg)
{
    char c = *(char*)arg;

    while (1)
        fputc(c, stderr);

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3;

    char a = 'x';
    char b = 'y';
    char c = 'z';

    pthread_create(&t1, NULL, print_char, &a);
    pthread_create(&t2, NULL, print_char, &b);
    pthread_create(&t3, NULL, print_char, &c);

    // Thread principal imprime 'o'
    while (1)
        fputc('o', stderr);

    return 0;
}
