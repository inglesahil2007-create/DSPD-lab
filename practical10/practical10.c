#include <stdio.h>

int main() {
    char inname[100], outname[100];
    FILE *in, *out;
    int c;

    printf("Input file: ");
    scanf("%s", inname);

    printf("Output file: ");
    scanf("%s", outname);

    in = fopen(inname, "r");
    out = fopen(outname, "w");
    if(in == NULL) {
        printf("Cant open file ! ");
        return 0;
    }

    while ((c = fgetc(in)) != EOF) {
        fputc(c, out);
    }
printf("file copied successfully!!!");
    fclose(in);
    fclose(out);

    return 0;
}
