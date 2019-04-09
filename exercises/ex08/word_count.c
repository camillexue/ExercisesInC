/* Simple example using Glib.

From http://www.ibm.com/developerworks/linux/tutorials/l-glib/

*/

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>

void print_hash(gpointer key, gpointer value, gpointer user_data) {
  char *skey = key;
  printf("%s: %i\n", skey, GPOINTER_TO_INT(value));
}

int main(int argc, char** argv) {
    gchar *contents;
    gsize len;
    GError *error = NULL;

    // get content from file
    if (!g_file_get_contents ("iliad.txt", &contents, &len, &error)) {
      g_error ("Error: %s", error->message);
    }

    gchar **words = g_strsplit_set(g_strcompress(contents), " .,/", -1);

    // hash table of word counts
    GHashTable* word_counts = g_hash_table_new(g_str_hash, g_str_equal);

    for(gchar **word_ptr=words; *word_ptr; word_ptr++) {
      gchar *word = *word_ptr;
      // check if it's alrady in hash table, add if it's not in
      if(g_hash_table_lookup(word_counts, word) == NULL) {
        g_hash_table_insert(word_counts, g_strdup(word), GINT_TO_POINTER(1));
      }
      else {
        g_hash_table_insert(word_counts, g_strdup(word), g_hash_table_lookup(word_counts, word)+1);
      }
    }
    // print hash table of word counts
    g_hash_table_foreach(word_counts, print_hash, NULL);
    return 0;
}
