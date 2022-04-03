#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "minimap.h"
#include <math.h>

void initmap(minimap *m)
{
    m->position_mini.x=250;
    m->position_mini.y=0;
    m->sprite=IMG_Load("bk1 mini.png");
    m->sprite2=IMG_Load("bk2 mini.png");
    m->pM.sprite = IMG_Load("hannabel mini.png");
    m->pM.position_perso.x = 250;
    m->pM.position_perso.y = 120;
}

void afficherminimap (minimap m, SDL_Surface * screen,int niveau)
{        
    if (niveau==1)
    SDL_BlitSurface(m.sprite, NULL, screen, &m.position_mini);
    else if ( niveau==2)
    SDL_BlitSurface(m.sprite2,NULL,screen,&m.position_mini);
    
    SDL_BlitSurface(m.pM.sprite, NULL, screen, &m.pM.position_perso);
}

void free_minimap (minimap *m)
{
    SDL_FreeSurface(m->sprite);
    SDL_FreeSurface(m->pM.sprite);
}

void initialiser_temps(temps *t)
{
    t->texte = NULL;
    t->position.x=600; // l blasa eli bch yodhher feha
    t->position.y=15;   // l blasa eli bch yodhher feha
    t->police = TTF_OpenFont("avocado.ttf", 15); // police eli bch testa3emlou
    strcpy( t->entree,""); // awel text bch yodhher
    (t->secondesEcoulees)=0;
    time(&(t->t1));		//temps du debut
}


void initialiser_score(score *s)
{
    s->texte = NULL;
    s->position.x=300; // l blasa eli bch yodhher feha
    s->position.y=15;   // l blasa eli bch yodhher feha
    s->police = TTF_OpenFont("avocado.ttf", 15); // police eli bch testa3emlou : esem l fichier - taille l ktiba
    strcpy( s->msg_score,"Score:0"); // awel text bch yodhher
    s->s=0;
}

void afficher_temps(temps *t, SDL_Surface *screen)
{	
    SDL_Color couleurnoir= {0, 0,0};

    time(&(t->t2));// temps actuel

    t->secondesEcoulees = t->t2 - t->t1;

    t->min=((t->secondesEcoulees/60)%60);
    t->sec= ((t->secondesEcoulees)%60);
    sprintf(t->entree,"%02d:%02d",t->min,t->sec);
    
    t->texte = TTF_RenderText_Blended(t->police,t->entree, couleurnoir);

    SDL_BlitSurface(t->texte, NULL, screen, &(t->position)); /* Blit du texte */
}

void afficher_score(score *s, SDL_Surface *screen)
{	
    SDL_Color couleurnoir= {0, 0,0};
    
    sprintf(s->msg_score, "score: %d",s->s);
     s->texte = TTF_RenderText_Blended(s->police,s->msg_score, couleurnoir);

    SDL_BlitSurface(s->texte, NULL, screen, &(s->position)); /* Blit du texte */
}

void free_score(score *s,SDL_Surface *screen)
{
    SDL_FreeSurface(s->texte);
    TTF_CloseFont(s->police);
}

void free_temps(temps *t,SDL_Surface *screen)
{
    SDL_FreeSurface(t->texte);
    TTF_CloseFont(t->police);
}

void sauvegarder( int score, char nomjoueur[], char nomfichier[])
{  
    FILE* f=NULL;
    f= fopen(nomfichier , "a" );
    if (f==NULL)
        printf("il ya un erreur");
    else
    {
        fprintf(f,"%d,%s\n",score,nomjoueur);
        fclose(f);
    } 
}

void MAJMinimap(SDL_Rect posJoueur , minimap * m, float redimensionnementx , float redimensionnementy)
{

m->pM.position_perso.x= (posJoueur.x * redimensionnementx) + 250; // position initial (250) + 9adeh t7arek * dimensionnement

m->pM.position_perso.y=  posJoueur.y*redimensionnementy - 10;
}





