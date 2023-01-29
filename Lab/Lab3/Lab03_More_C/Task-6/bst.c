#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node
{
   int ID;
   char *name;
   struct tree_node *left;
   struct tree_node *right;
} node_t;

void print_bst(node_t *node)
{
   if (node == NULL)
   {
      printf("Tree is empty!\n");
      return;
   }

   if (node != NULL)
      printf("%d %s: \t", node->ID, node->name);
   if (node->left != NULL)
      printf("L%d,", node->left->ID);
   if (node->right != NULL)
      printf("R%d", node->right->ID);
   printf("\n");

   if (node->left != NULL)
      print_bst(node->left);
   if (node->right != NULL)
      print_bst(node->right);
}

void delete_tree(node_t **node)
{
   if (*node != NULL)
   {
      delete_tree(&(*node)->left);
      delete_tree(&(*node)->right);
      free((*node)->name);
      free(*node);
      *node = NULL;
   }
   return;
}

void insert(node_t **node, int ID, char *name)
{
   if (*node == NULL)
   {
      *node = (node_t *)malloc(sizeof(node_t));
      (*node)->ID = ID;
      (*node)->name = (char *)malloc(strlen(name) + 1);
      strcpy((*node)->name, name);
      (*node)->left = NULL;
      (*node)->right = NULL;
   }
   else
   {
      if (ID < (*node)->ID)
         insert(&(*node)->left, ID, name);
      else if (ID > (*node)->ID)
         insert(&(*node)->right, ID, name);
      else
         printf("ERROR: ID %d already exists in the tree!\n", ID);
   }

   return;
}

void search(node_t *node, int ID)
{
   if (node == NULL)
   {
      printf("Plant with ID %d does not exist!\n", ID);
      return;
   }

   if (ID < node->ID)
      search(node->left, ID);
   else if (ID > node->ID)
      search(node->right, ID);
   else
      printf("Plant with ID %d has name %s in the tree.\n", ID, node->name);

   return;
}

int main(int argc, char const *argv[])
{
   node_t *root = NULL; // empty tree
   printf("Inserting nodes to the binary tree.\n");

   insert(&root, 445, "sequoia");

   insert(&root, 162, "fir");
   insert(&root, 612, "baobab");
   insert(&root, 845, "spruce");
   insert(&root, 862, "rose");
   insert(&root, 168, "banana");
   insert(&root, 225, "orchid");
   insert(&root, 582, "chamomile");

   printf("Printing nodes of the tree.\n");
   print_bst(root);

   search(root, 168);
   search(root, 467);

   printf("Deleting tree.\n");
   delete_tree(&root);

   print_bst(root);
   return 0;
}
