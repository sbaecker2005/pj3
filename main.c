#include "contatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deletarContatos(Agenda *agenda);

int main() {
  Agenda agenda;
  inicializarAgenda(&agenda);
  carregarAgenda(&agenda);

  int opcao;
  do {
    printf("\nMenu:\n");
    printf("1. Adicionar Contato\n");
    printf("2. Listar Contatos\n");
    printf("3. Deletar Contato\n");
    printf("4. Salvar Agenda\n");
    printf("5. Carregar Agenda\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBuffer();

    switch (opcao) {
    case 1:
      adicionarContato(&agenda);
      break;
    case 2:
      listarContatos(&agenda);
      break;
    case 3:
      deletarContatos(&agenda);
      break;
    case 4:
      salvarAgenda(&agenda);
      break;
    case 5:
      carregarAgenda(&agenda);
      break;
    case 6:
      printf("Saindo...\n");
      break;
    default:
      printf("Opcao invalida!\n");
    }
  } while (opcao != 6);

  return 0;
}
