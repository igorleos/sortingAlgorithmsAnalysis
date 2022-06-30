#!/bin/bash
function compile_headers {
    gcc -Wall -Wextra -std=c11 -c Analytics.c -g

    gcc -Wall -Wextra -std=c11 -c VectorDefinitions.c -g

    gcc -Wall -Wextra -std=c11 -c BubbleSort.c -g

    gcc -Wall -Wextra -std=c11 -c HeapSort.c -g

    gcc -Wall -Wextra -std=c11 -c InsertionSort.c -g

    gcc -Wall -Wextra -std=c11 -c MergeSort.c -g

    gcc -Wall -Wextra -std=c11 -c QuickSort.c -g

    gcc -Wall -Wextra -std=c11 -c SelectionSort.c -g

    gcc -Wall -Wextra -std=c11 -c ShellSort.c -g

    gcc -Wall -Wextra -std=c11 -c VectorDefinitions.c -g

    gcc -Wall -Wextra -std=c11 -c SelectionSort.c -g


    #Para testar um arquivo utilize um metodo main nesse arquivo, e deixe esse arquivo por ultimo na proxima linha
    #(mantenha a ordem, mude apenas o arquivo que ira testar)

    gcc Analytics.o VectorDefinitions.o HeapSort.o  MergeSort.o QuickSort.o SelectionSort.o ShellSort.o BubbleSort.o InsertionSort.o -g
    
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        ./a.out
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        ./a.out
    elif [[ "$OSTYPE" == "cygwin" ]]; then
        ./a.exe
    elif [[ "$OSTYPE" == "msys" ]]; then
        ./a.exe
    else
            # Unknown.
    fi
}
#Para executar digite no terminal:
#source compilar.sh
#compile_headers





