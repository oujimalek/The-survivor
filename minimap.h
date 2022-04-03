#ifndef __MINIMAP_H // bch net2akd kawnou lfichier heka deja included or define
#define __MINIMAP_H // ithekn mehouch define ywali ymarki rouhou define
#include <SDL/SDL.h> // nencludi l bib sdl bch najm nesta3ml les fnct mteiihom
#include <SDL/SDL_ttf.h> // " l bib sdl_ttf.h bch najm nestaaml les fnct enou nsob l polise taa lktiba l couleur ext ..
#include <time.h> // bch nesta3ml ay mawthou3 3andou 3ale9a b tmps

typedef struct
{
    SDL_Rect position_perso; // L mostatil eli bch yodhher fih l joueur/enemy
    SDL_Surface* sprite; // L taswira eli bch todhher fl mostatil eli lfou9
} Personne; // joueur or enemy

typedef struct
{
    SDL_Rect position_mini; // kima l personne
    SDL_Surface* sprite; // kif kif xD(bk1 mini)
    SDL_Surface* sprite2;//bk2 mini
    Personne pM; // déclaration ta3 l perssone lfel minimap
} minimap; // bch tlemhom l 2

typedef struct temps {
    SDL_Surface* texte; // l txt eli bch yetekteb 3l ecran
    SDL_Rect position; // position t3 l ktiba

    TTF_Font* police; // police t3 l ktiba
    
    char entree[7]; // 3 characters l minute, 2 characters second, 1 character seperator, 1 character backslash 0 (\0) (string terminator)
    int secondesEcoulees; // 9adeh mn second t3adet mn t1 --> t2

    time_t t1, t2; // T1: wa9et l bdet fih l jeu
    		   // T2: wa9et t3 tawa
    int min, sec; 
} temps;

typedef struct score {
    SDL_Surface* texte; // l txt eli bch yetekteb 3l ecran
    SDL_Rect position; // position t3 l ktiba

    TTF_Font* police; // police t3 l ktiba
    
    int s ;
    char msg_score[13];
    } score ;

void initmap(minimap* m); // pour initialiser l minimap 
void afficherminimap(minimap m, SDL_Surface* screen,int niveau); //l affichage de minimap 
void free_minimap(minimap* m); //pour libérer l'espace mémoire
void sauvegarder( int score, char nomjoueur[], char nomfichier[]);
void MAJMinimap(SDL_Rect posJoueur , minimap * m, float redimensionnementx , float redimentionnementy);

void initialiser_temps(temps* t);// initialisation de temps
void afficher_temps(temps* t, SDL_Surface* ecran);//?2
void free_temps(temps* t, SDL_Surface* ecran);// libérer l'éspace mémoire


void initialiser_score(score* s);
void afficher_score(score* s, SDL_Surface* ecran);
void free_score(score* s, SDL_Surface* ecran);
#endif
