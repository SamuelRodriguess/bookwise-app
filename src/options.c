char options()
{
    char opcao;
    printf("\n\n\n");
    printf(" (C)adastrar.\n");
    printf(" (M)ostrar.\n");
    printf(" C(A)arregar.\n");
    printf(" (E)ditar \n");
    printf(" (T)erminar.\n");
    fflush(stdin);
    scanf(" %c", &opcao);
    return opcao;
}