# Retro_MFA

## Principe du rush

Le principe de ce rush est de retro ingenieurer des fichier MFA dans l'objectif de recuperer et d'afficher les images encapsuler dans le fichier.

## Ques qu'un fichier mfa?

https://filext.com/file-extension/MFA
https://clickwiki.github.io/file-extensions/MFA/
https://mfa.ilikefemboys.com/

## strategie pour trouver les image:

Comme indiqué dans la decription de la structure, la section CImageBank  contient sur les 4 premier bytes un header ayant pour valeur  "AGMI". En lisant le fichier byte par byte avec le syscall read et un buffer de size 1, a chaque fois que le caractere 'A' est trouvé, untiliser une focntion de comparaison sur 3. byte et verrifier la correspondance de notre buffer et de la valeur "GMI" 'A' ayant deja ete lu. Si la fonction de comparairson est frutueuse, alors le debut de notre section CImageBank est egal au nombre de b_read - 4 

``` c

int get_agmi_flags(int fd)
{
    int b_read;
    char buffer[1];
    char b2[3];

    if(fd < 0)
        return (-1);
    b_read = 0;
    while (1)
    {
        b_read += read(fd, buffer, 1);
        if(buffer[0] == 'A')
        {
            
            b_read += read(fd, b2, 3);
            if(!strncmp("GMI", b2, 3))
                return (b_read - 4);
        }
    }
    return (0);
}
```

![Texte alternatif](/sreen/cbank_struct.png "Titre de l'image").