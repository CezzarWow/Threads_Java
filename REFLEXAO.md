# Threads_Java

### Análise das Execuções

**1. Qual foi a diferença na execução da `thread-create.c`?**  
- A execução é contínua e nunca termina sozinha. As threads imprimem caracteres de forma concorrente e a saída é misturada sem ordem previsível. É necessário usar CTRL+C ou kill para interromper.

**2. Como foi a forma de encerramento utilizada no programa `thread-create2.c`?**  
- O programa termina automaticamente. Cada thread imprime a quantidade de caracteres definida e o `pthread_join` garante que todas finalizem antes do encerramento do programa.