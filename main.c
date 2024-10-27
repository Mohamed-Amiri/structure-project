#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// D�finition de la structure Adresse
struct Adresse {
    char rue[100];
    char ville[100];
    int code_postal;
};


struct Personne {
    char nom[100];
    int age;
    struct Adresse adresse;
};

// Prototypes des fonctions
void creer_personne(struct Personne personnes[], int *nombre_personnes);
void lire_personnes(const struct Personne personnes[], int nombre_personnes);
void mettre_a_jour_personne(struct Personne personnes[], int nombre_personnes);
void supprimer_personne(struct Personne personnes[], int *nombre_personnes);

int main() {
    struct Personne personnes[100];
    int nombre_personnes = 0;
    int choix;


    do {
        printf("\nMenu :\n");
        printf("1. Cr�er une personne\n");
        printf("2. Lire les informations des personnes\n");
        printf("3. Mettre � jour une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar();

        switch (choix) {
            case 1:
                creer_personne(personnes, &nombre_personnes);
                break;
            case 2:
                lire_personnes(personnes, nombre_personnes);
                break;
            case 3:
                mettre_a_jour_personne(personnes, nombre_personnes);
                break;
            case 4:
                supprimer_personne(personnes, &nombre_personnes);
                break;
            case 5:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez r�essayer.\n");
        }
    } while (choix != 5);

    return 0;
}

// Fonction pour cr�er une personne
void creer_personne(struct Personne personnes[], int *nombre_personnes) {
    struct Personne p;
    printf("\nEntrez le nom : ");
    fgets(p.nom, 100, stdin);
    p.nom[strcspn(p.nom, "\n")] = 0;

    printf("Entrez l'�ge : ");
    scanf("%d", &p.age);
    getchar();

    printf("Entrez la rue : ");
    fgets(p.adresse.rue, 100, stdin);
    p.adresse.rue[strcspn(p.adresse.rue, "\n")] = 0;

    printf("Entrez la ville : ");
    fgets(p.adresse.ville, 100, stdin);
    p.adresse.ville[strcspn(p.adresse.ville, "\n")] = 0;

    printf("Entrez le code postal : ");
    scanf("%d", &p.adresse.code_postal);
    getchar();  // Consomme le retour � la ligne

    personnes[*nombre_personnes] = p;
    (*nombre_personnes)++;
    printf("Personne ajout�e avec succ�s.\n");
}

// Fonction lire et afficher les informations
void lire_personnes(const struct Personne personnes[], int nombre_personnes) {
    if (nombre_personnes == 0) {
        printf("\nAucune personne enregistr�e.\n");
        return;
    }
    printf("\nListe des personnes :\n");
    for (int i = 0; i < nombre_personnes; i++) {
        printf("\nPersonne %d\n", i + 1);
        printf("Nom : %s\n", personnes[i].nom);
        printf("�ge : %d\n", personnes[i].age);
        printf("Adresse : %s, %s, %d\n", personnes[i].adresse.rue, personnes[i].adresse.ville, personnes[i].adresse.code_postal);
    }
}

// Fonction  mettre � jour
void mettre_a_jour_personne(struct Personne personnes[], int nombre_personnes) {
    int index;
    printf("\nEntrez le num�ro de la personne � mettre � jour (1 � %d) : ", nombre_personnes);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > nombre_personnes) {
        printf("Num�ro invalide.\n");
        return;
    }

    index--;
    printf("Mise � jour de la personne %d :\n", index + 1);

    printf("Entrez le nouveau nom : ");
    fgets(personnes[index].nom, 100, stdin);
    personnes[index].nom[strcspn(personnes[index].nom, "\n")] = 0;

    printf("Entrez le nouvel �ge : ");
    scanf("%d", &personnes[index].age);
    getchar();

    printf("Entrez la nouvelle rue : ");
    fgets(personnes[index].adresse.rue, 100, stdin);
    personnes[index].adresse.rue[strcspn(personnes[index].adresse.rue, "\n")] = 0;

    printf("Entrez la nouvelle ville : ");
    fgets(personnes[index].adresse.ville, 100, stdin);
    personnes[index].adresse.ville[strcspn(personnes[index].adresse.ville, "\n")] = 0;

    printf("Entrez le nouveau code postal : ");
    scanf("%d", &personnes[index].adresse.code_postal);
    getchar();

    printf("Informations de la personne mises � jour.\n");
}

// Fonction pour supprimer une personne
void supprimer_personne(struct Personne personnes[], int *nombre_personnes) {
    int index;
    printf("\nEntrez le num�ro de la personne � supprimer (1 � %d) : ", *nombre_personnes);
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *nombre_personnes) {
        printf("Num�ro invalide.\n");
        return;
    }

    index--;

    // D�cale les personnes pour combler l'emplacement supprim�
    for (int i = index; i < *nombre_personnes - 1; i++) {
        personnes[i] = personnes[i + 1];
    }
    (*nombre_personnes)--;

    printf("Personne supprim�e avec succ�s.\n");
}
