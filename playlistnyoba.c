#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur untuk merepresentasikan lagu dalam playlist
typedef struct Song {
    char judul[100];
    char artis[100];
    struct Song* next;
} Song;

// Struktur untuk merepresentasikan playlist
typedef struct Playlist {
    Song* head;
    Song* tail;
} Playlist;

// Fungsi untuk membuat lagu baru
Song* createSong(const char* judul, const char* artis) {
    Song* newSong = (Song*)malloc(sizeof(Song));
    strcpy(newSong->judul, judul);
    strcpy(newSong->artis, artis);
    newSong->next = NULL;
    return newSong;
}

// Fungsi untuk membuat playlist baru
Playlist* createPlaylist() {
    Playlist* newPlaylist = (Playlist*)malloc(sizeof(Playlist));
    newPlaylist->head = NULL;
    newPlaylist->tail = NULL;
    return newPlaylist;
}

// Fungsi untuk menambahkan lagu ke playlist
void addSong(Playlist* playlist, const char* judul, const char* artis) {
    Song* newSong = createSong(judul, artis);
    if (playlist->head == NULL) {
        playlist->head = newSong;
        playlist->tail = newSong;
    } else {
        playlist->tail->next = newSong;
        playlist->tail = newSong;
    }
}

// Fungsi untuk mencetak playlist
void printPlaylist(Playlist* playlist) {
    Song* current = playlist->head;
    int index = 1;
    while (current != NULL) {
        printf("%d. %s - %s\n", index, current->judul, current->artis);
        current = current->next;
        index++;
    }
}

// Fungsi untuk menghapus lagu dari playlist
void removeSong(Playlist* playlist, const char* judul) {
    Song* current = playlist->head;
    Song* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            if (current == playlist->head) {
                playlist->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == playlist->tail) {
                playlist->tail = previous;
            }

            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }
}

int main() {
    Playlist* myPlaylist = createPlaylist();

    int choice;
    char nama[25];
    char judul[100];
    char artis[100];
	
	printf("\n");
    printf("=====================================================\n");
    printf("||     Selamat Datang di PlayList Lagu XPOTIPY     ||\n");
    printf("=====================================================\n");
    printf("\n");
    
    printf ("Hellow, Mari kita kenalan...\n");
    printf ("Perkenalkan nama aku XPOTIPY >_<\n");
    printf ("Nama kamu siapa ?\n\n");
    printf ("Ketik nama kamu disini : ");
    scanf ("%s",&nama);
    printf("=====================================================\n");
    printf("||                      Hii %s                  ||\n",&nama);
    printf("=====================================================\n\n");
    printf ("Mari Buat Playlist lagu kamu bersama XPOTIPY >_<\n\n");
    
    while (1) {
    printf("\n=====================================================\n");
    printf("||                  MENU XPOTIPY                   ||\n");
    printf("=====================================================\n");
    printf("1. Tambah Lagu\n");
    printf("2. Hapus Lagu\n");
    printf("3. Tampilkan Playlist Saat Ini\n");
    printf("4. Keluar\n");
    printf("\nPilih operasi (1/2/3/4): ");
    scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nMasukkan judul lagu: ");
                scanf(" %[^\n]", judul);
                printf("Masukkan nama artis: ");
                scanf(" %[^\n]", artis);
                addSong(myPlaylist, judul, artis);
                break;
            case 2:
                printf("\nMasukkan judul lagu yang akan dihapus: ");
                scanf(" %[^\n]", judul);
                removeSong(myPlaylist, judul);
                break;
            case 3:
                printf("\nPlaylist Anda saat ini:\n");
                printPlaylist(myPlaylist);
                break;
            case 4:
                exit(0);
            default:
                printf("Pilihan tidak valid, mohon coba lagi... (-_-)\n");
        }
    }
	
    return 0;
}

