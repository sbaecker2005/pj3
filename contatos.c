
#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>





































void listarContatos() {
  printf("Listando contatos da sua agenda:\n");
  
 FILE *arquivo = fopen("agenda.bin", "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo para listar os contatos!\n");
    return;
  }

  Contato contato;
  while (fscanf(arquivo, "%49s %49s %49s %11s", contato.nome, contato.sobrenome,
                contato.email, contato.telefone) == 4) {
    printf("%s %s, %s, %s\n", contato.nome, contato.sobrenome, contato.email,
           contato.telefone);
  }

  fclose(arquivo);
}

void deletarContatos(Agenda *agenda) {
  FILE *temp = fopen("temp.bin", "w");
  if (temp == NULL) {
    printf("Erro ao criar arquivo temporario!\n");
    return;
  }

  char telefone[12];
  printf("Telefone do contato para deletar: ");
  scanf("%11s", telefone);
  limparBuffer();


  int encontrado = 0;
  for (int i = 0; i < agenda->numContatos; i++) {
          if (strcmp(agenda->contatos[i].telefone, telefone) != 0) {
              fprintf(temp, "%s %s %s %s\n", agenda->contatos[i].nome,
                      agenda->contatos[i].sobrenome, agenda->contatos[i].email,
                      agenda->contatos[i].telefone);

          } else {
          encontrado = 1;
      }
  }
  fclose(temp);
  if (!encontrado) {
    printf("Contato nao encontrado!\n");
    remove("temp.bin");
  } else {
    remove("agenda.bin");
    rename("temp.bin", "agenda.bin");
    printf("Contato deletado com sucesso!\n");
  }
}
