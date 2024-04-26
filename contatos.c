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
