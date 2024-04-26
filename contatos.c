#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
