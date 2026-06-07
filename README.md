# Retro_MFA

## Principe du rush

Le principe de ce rush est de faire de la rétro-ingénierie sur des fichiers MFA afin de récupérer et d'afficher les images qu'ils contiennent.

No ia!
## Ques qu'un fichier mfa?

https://filext.com/file-extension/MFA \
https://clickwiki.github.io/file-extensions/MFA/ \
https://mfa.ilikefemboys.com/

## strategie pour trouver les image:

Comme indiqué dans la description de la structure, la section CImageBank contient, sur ses 4 premiers octets, un en-tête ayant pour valeur "AGMI". En lisant le fichier octet par octet avec le syscall read et un buffer de taille 1, à chaque fois que le caractère 'A' est trouvé, utiliser une fonction de comparaison sur les 3 octets suivants afin de vérifier la correspondance entre notre buffer et la valeur "GMI", le 'A' ayant déjà été lu. Si la fonction de comparaison est fructueuse, alors le début de notre section CImageBank est égal à b_read - 4.

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

![image](/screen/cbank_struct.png).

Ce qu'il faut faire maintenant, c'est se rendre à la section count de la structure CImageBank. La valeur count nous donnera la taille du tableau contenant les images au format RGB, que nous pourrons ensuite extraire.

Le problème est que nous avons besoin de connaître au préalable la taille de la section LOGPALETTE, située avant le champ count. Cette taille est variable et propre au fichier MFA analysé.

## L'exploration s'arrete ici...

L'exploration s'arrête ici.

Ce qu'il aurait fallu faire pour mener ce projet à son terme :

* Ignorer la section LOGPALETTE.
* Déterminer la taille du tableau d'images brutes à l'aide du champ count (uint32_t).
* Extraire ce tableau.
* Afficher les images à l'aide d'une bibliothèque externe, telle que MiniLibX.

Mon partenaire, assigné automatiquement, ne s'est pas présenté au rush. Le projet n'aurait donc pas pu être présenté.

Néanmoins, j'ai pu, de mon côté, découvrir et approfondir mes connaissances sur le format MFA ainsi que sur les techniques d'extraction de données à partir d'un fichier binaire brut.

Une notion fondamentale que ce projet m'a rappelée est que la fonction bas niveau :
```c
ssize_t read(int fd, void *buf, size_t nbyte);
```
prend en second paramètre un pointeur de type void *. Cela permet donc d'écrire directement dans une variable typée plutôt que d'effectuer une conversion manuelle des octets lus.

Par exemple :

```c
uint16_t v;
read(fd, &v, sizeof(uint16_t));
```

permet de récupérer directement une valeur depuis le fichier binaire.

Attention cependant à l'endianness, qui peut modifier l'interprétation des données selon l'architecture de la machine et le format du fichier analysé.