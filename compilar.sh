#!/bin/bash
function compile_headers {
    gcc -Wall -Wextra -std=c11 -c VectorDefinitions.c -g

    gcc -Wall -Wextra -std=c11 -c Analytics.c -g



    gcc -Wall -Wextra -std=c11 -c BubbleSort.c -g

    gcc -Wall -Wextra -std=c11 -c HeapSort.c -g

    gcc -Wall -Wextra -std=c11 -c InsertionSort.c -g

    gcc -Wall -Wextra -std=c11 -c MergeSort.c -g

    gcc -Wall -Wextra -std=c11 -c QuickSort.c -g

    gcc -Wall -Wextra -std=c11 -c SelectionSort.c -g

    gcc -Wall -Wextra -std=c11 -c ShellSort.c -g

    gcc -Wall -Wextra -std=c11 -c VectorDefinitions.c -g

    gcc -Wall -Wextra -std=c11 -c SelectionSort.c -g

    gcc -Wall -Wextra -std=c11 -c Menu.c -g

    gcc -Wall -Wextra -std=c11 -c Main.c -g

    gcc Analytics.o VectorDefinitions.o HeapSort.o  MergeSort.o QuickSort.o  ShellSort.o BubbleSort.o InsertionSort.o SelectionSort.o Menu.o Main.o -g
    
    # if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    #     ./a.out
    # elif [[ "$OSTYPE" == "darwin"* ]]; then
    #     ./a.out
    # elif [[ "$OSTYPE" == "cygwin" ]]; then
        ./a.exe
    # elif [[ "$OSTYPE" == "msys" ]]; then
        # ./a.exe
    # else
    #   echo "Sistema nao indentificado, rode manualmente o executavel 'a.out/a.exe'"
    # fi

}
#Para executar digite no terminal:
#source compilar.sh
#compile_headers





