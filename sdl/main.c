#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

void pause();

int main(int argc, char *argv[])
{
    SDL_Surface *ecran = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) == -1) // D�marrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // �criture de l'erreur
        exit(EXIT_FAILURE); // On quitte le programme
    }
    else{
            // Le pointeur qui va stocker la surface de l'�cran

        SDL_Init(SDL_INIT_VIDEO);
        ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE); // On tente d'ouvrir une fen�tre

            if (ecran == NULL) // Si l'ouverture a �chou�, on le note et on arr�te
            {
                fprintf(stderr, "Impossible de charger le mode vid�o : %s\n", SDL_GetError());
                exit(EXIT_FAILURE);
            }

        SDL_WM_SetCaption("Labyrinthe", NULL);
        pause();
    }

    SDL_Quit();

    return EXIT_SUCCESS;


}

void pause()
{
    int continuer = 1;
    SDL_Event event;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch(event.type)
        {
            case SDL_QUIT:
                continuer = 0;
        }
    }
}
