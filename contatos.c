#include "tarefas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarContato(Agenda *agenda) {
  if (agenda->numContatos >= MAX_CONTATOS) {
    printf("Agenda cheia, impossivel adicionar mais contatos!\n");
    return;
  }

  Contato novoContato;

  printf("Nome: ");
  scanf("%49s", novoContato.nome);
  limparBuffer();

  printf("Sobrenome: ");
  scanf("%49s", novoContato.sobrenome);
  limparBuffer();

  printf("Email: ");
  scanf("%49s", novoContato.email);
  limparBuffer();

  printf("Telefone: ");
  scanf("%11s", novoContato.telefone);
  limparBuffer();

  agenda->contatos[agenda->numContatos++] = novoContato;

  printf("Contato adicionado com sucesso!\n");
}

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
    char telefone[12];
    printf("Telefone do contato para deletar: ");
    scanf("%11s", telefone);
    limparBuffer();


    int encontrado = 0;
    for (int i = 0; i < agenda->numContatos; i++) {
        if (strcmp(agenda->contatos[i].telefone, telefone) == 0) {
            encontrado = 1;
            agenda->numContatos--;
            agenda->contatos[i] = agenda->contatos[agenda->numContatos];
        }
    }
    if (!encontrado) {
        printf("Contato nao encontrado!\n");
    } else {
        remove("agenda.bin");
        printf("Contato deletado com sucesso!\n");
    }
}
