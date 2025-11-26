#include <pthread.h>
#include <stdio.h>

/* Parâmetros para cada thread */
struct char_print_parms
{
    char character;  // Caractere a ser impresso
    int count;       // Número de vezes que será impresso
};

/* Função que imprime 'count' vezes o caractere fornecido */
void* char_print(void* parameters)
{
    struct char_print_parms* p = (struct char_print_parms*) parameters;

    for (int i = 0; i < p->count; ++i)
        fputc(p->character, stderr);

    return NULL;
}

int main()
{
    pthread_t t1, t2, t3, t4;

    struct char_print_parms args1;
    struct char_print_parms args2;
    struct char_print_parms args3;
    struct char_print_parms args4;

    /* Configurações das threads */
    args1.character = 'x';
    args1.count = 20000;

    args2.character = 'o';
    args2.count = 15000;

    args3.character = 'y';
    args3.count = 10000;

    args4.character = 'z';
    args4.count = 5000;

    /* Criação das threads */
    pthread_create(&t1, NULL, &char_print, &args1);
    pthread_create(&t2, NULL, &char_print, &args2);
    pthread_create(&t3, NULL, &char_print, &args3);
    pthread_create(&t4, NULL, &char_print, &args4);

    /* Aguarda todas terminarem */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    return 0;
}
