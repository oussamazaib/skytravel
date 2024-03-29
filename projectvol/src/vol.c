#include <stdio.h>
#include <string.h>
#include "vol.h"
#include <gtk/gtk.h>

enum
{
	VILLE_DEPART,
	VILLE_ARRIVEE,
	DUREE_VOL,
        DATE_DEPART,
	CLASSE,
	NBRE_VOYAGEURS,
	PRIX_VOL,
	ID_VOL,
	COLUMNS

};

void ajouter_vol(Vol p)
{
	FILE *f;
	f=fopen("/home/oussama/Downloads/projectvol/uservol.txt","a+");
	if(f!=NULL)
	{
	fprintf(f,"%s %s %d/%d/%d %s %s %s %s %s  \n", p.Ville_depart,p.Ville_arrivee,p.Jour,p.Mois,p.Annee,p.Duree_vol, p.Classe, p.Nbre_voyageurs, p.Prix_vol, p.Id_vol);
	fclose(f);
	}
}
void afficher_vol(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;

	GtkListStore *store;

	char Ville_depart[40];
	char Ville_arrivee[40];
	char Date_depart[40];
	char Duree_vol[40];
	char Classe[40];
	char Nbre_voyageurs[40];
	char Prix_vol[40];
	char Id_vol[40];
	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Ville_depart", renderer, "text", VILLE_DEPART, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Ville_arrivee", renderer, "text", VILLE_ARRIVEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Date_depart", renderer, "text", DATE_DEPART, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Duree_vol", renderer, "text", DUREE_VOL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Classe", renderer, "text", CLASSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Nbre_voyageurs", renderer, "text", NBRE_VOYAGEURS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Prix_vol", renderer, "text", PRIX_VOL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Id_vol", renderer, "text", ID_VOL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
                

		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
		f = fopen("/home/oussama/Downloads/projectvol/uservol.txt", "r");
		if(f==NULL)
		{
			return;
		}
		else
		{ f = fopen("/home/oussama/Downloads/projectvol/uservol.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %s \n", Ville_depart, Ville_arrivee, Date_depart, Duree_vol, Classe, Nbre_voyageurs, Prix_vol, Id_vol)!= EOF)
		{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, VILLE_DEPART, Ville_depart, VILLE_ARRIVEE, Ville_arrivee, DATE_DEPART, Date_depart,DUREE_VOL, Duree_vol,CLASSE, Classe,NBRE_VOYAGEURS, Nbre_voyageurs,PRIX_VOL, Prix_vol,ID_VOL, Id_vol, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store)); 
		g_object_unref(store);
		}
		
}
void modifier(Vol p, Vol m)
{ 	
	char Ville_departx[40], Ville_arriveex[40], Duree_volx[40], Classex[40], Nbre_voyageursx[40], Prix_volx[40], Id_volx[40];
int Jourx,Moisx,Anneex;
	FILE *f ;
	FILE *ftempvol;
	f=fopen("/home/oussama/Downloads/projectvol/uservol.txt","r");
	ftempvol=fopen("/home/oussama/Downloads/projectvol/tempvol.txt","a+");
if (f !=NULL)
{
	while(fscanf(f,"%s %s %d %d %d %s %s %s %s %s\n",p.Ville_depart, p.Ville_arrivee, p.Jour, p.Mois, p.Annee, p.Duree_vol, p.Classe, p.Nbre_voyageurs, p.Prix_vol, p.Id_vol)!=EOF)
{
		if((strcmp(p.Ville_depart,m.Ville_depart)==0) )
{
fprintf(ftempvol,"%s %s %d %d %d %s %s %s %s %s \n",m.Ville_depart, m.Ville_arrivee, m.Jour, m.Mois, m.Annee, m.Duree_vol, m.Classe, m.Nbre_voyageurs, m.Prix_vol, m.Id_vol);
}
else 
{
fprintf(ftempvol,"%s %s %d %d %d %s %s %s %s %s\n",p.Ville_depart, p.Ville_arrivee, p.Jour, p.Mois, p.Annee, p.Duree_vol, p.Classe, p.Nbre_voyageurs, p.Prix_vol, p.Id_vol);
}
}
fclose(f);
fclose(ftempvol);
remove ("/home/oussama/Downloads/projectvol/uservol.txt");
rename("/home/oussama/Downloads/projectvol/tempvol.txt","/home/oussama/Downloads/projectvol/uservol.txt");
}                  

}		
}



enum
{
	VILLE,
	HOTEL,
	JOUR,
        MOIS,
	ANNEE,
	GAMME,
	ID_HOTEL,
	TARIF,
	COLUMNS1

};



void afficher_hotel(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;

	GtkListStore *store;

	char ville[40];
	char hotel[40];
	char jour[40];
	char mois[40];
	char annee[40];
	char gamme[40];
	char id_hotel[40];
	char tarif[40];
	

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("ville", renderer, "text", VILLE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("hotel", renderer, "text", HOTEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text", ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("gamme", renderer, "text", GAMME, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("id_hotel", renderer, "text", ID_HOTEL, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("tarif", renderer, "text", TARIF, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
                

		store=gtk_list_store_new (COLUMNS1, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	f = fopen("/home/oussama/Downloads/projectvol/hotel.txt", "r");
		if(f==NULL)
		{
			return;
		}
		else
		{
		 f = fopen("/home/oussama/Downloads/projectvol/hotel.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s %s \n", ville, hotel, jour, mois, annee, gamme, id_hotel, tarif)!= EOF)
		{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, VILLE, ville, HOTEL, hotel, JOUR, jour,MOIS, mois,ANNEE, annee,GAMME, gamme,id_hotel, id_hotel,TARIF, tarif, -1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store)); 
		g_object_unref(store);
		}
		
}
}
		





























