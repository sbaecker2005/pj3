void limparBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}
