/*
** graph.c for fdfsdfs in /home/ghais/Documents/Projets/my_irc-bensaf_g
**
** Made by bensafia ghais
** Login   <ghais@epitech.net>
**
** Started on  Fri Apr 26 14:46:54 2013 bensafia ghais
** Last update Sun Apr 28 22:41:01 2013 bensafia ghais
*/

#include	"../headers/client.h"

gboolean	actualise_chat(gpointer data)
{
  GtkTextBuffer *text_buffer;
  GtkTextIter   end;
  t_glo		*glo;

  glo = (t_glo*)data;
  if (glo->haveToRead == 1)
    {
      text_buffer = 0;
      text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(glo->text_view));
      gtk_text_buffer_get_end_iter(text_buffer,&end);
      gtk_text_buffer_insert(text_buffer, &end,
			     g_locale_to_utf8(glo->str, -1, NULL, NULL, NULL),
 -1);
      gtk_text_buffer_insert(text_buffer, &end,
			     g_locale_to_utf8("\n", -1, NULL, NULL, NULL), -1);
      glo->haveToRead = 0;
    }
  return (TRUE);
}

void            recup_texte(GtkWidget *pEntry, t_glo *glo)
{
  const gchar   *buf;

  buf = gtk_entry_get_text(GTK_ENTRY(pEntry));
  strcat((char*)buf, "\n");
  check_command((char*)buf, glo);
  gtk_entry_set_text(GTK_ENTRY(pEntry) , "");
}

static void	OnDestroy(GtkWidget *lol, t_glo *glo)
{
  lol = lol;
  glo->quit = 1;
  glo->cli->isRunning = 1;
  gtk_main_quit();
}

void            init_graph(t_glo *glo)
{
  GtkWidget     *window;
  GtkWidget     *bar;
  GtkWidget     *box;
  GtkWidget     *pEntry;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(window), 840, 600);
  gtk_window_set_title(GTK_WINDOW(window), "IRC");
  bar = gtk_scrolled_window_new(NULL, NULL);
  box = gtk_vbox_new(FALSE, 5);
  gtk_container_add(GTK_CONTAINER(window), box);
  pEntry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(box), bar, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(box), pEntry, TRUE, TRUE, 0);
  glo->text_view = gtk_text_view_new();
  gtk_text_view_set_editable(GTK_TEXT_VIEW(glo->text_view), FALSE);
  gtk_scrolled_window_add_with_viewport
    (GTK_SCROLLED_WINDOW(bar),glo->text_view);
  g_signal_connect(G_OBJECT(pEntry) ,"activate",G_CALLBACK(recup_texte), (glo));
  g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(OnDestroy), glo);
  g_timeout_add(100, actualise_chat, (gpointer)glo);
  gtk_widget_show_all(window);
}
