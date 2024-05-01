#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void error(char *error) {
    fprintf(stderr,error);
    exit(EXIT_FAILURE);
}

int system(const char *command);

int main(int argc, char *argv[]) {
    char radice[1000]="";
    char *radiceTemp=radice;
    printf("Inserisci la locazione della cartella da aprire in VSCode: ");
    scanf("%[^\n]",radice);
    if (strlen(radice)<7 || radice[0]!='/') error("Radice non corretta\n");
    FILE *fp=fopen("script.c","w");
    fprintf(fp,"#include <stdio.h>\n#include <stdlib.h>\n#include <string.h>\n\nint system(const char *command);\n\nint main(void) {\nsystem(\"code %s\");\nreturn 0;\n}\n",radice);
    fclose(fp);
    system("gcc script.c -o codeBello.out");
    system("rm -f script.c");
    return 0;
}