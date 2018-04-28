#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
};

struct s_stack {
    struct s_node   *node;
    struct s_stack *next;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *getTreeOfLife(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
/*
for (int i = 0; root->children[i]; i++){
        if (*found == 2)
            return root;
        if (!strcmp(root->children[i]->name, firstSpecies))
            ++*found;
        if (!strcmp(root->children[i]->name, secondSpecies))
            ++*found;
        if (*found > 0)
            printf("found: %d\n", *found);
    }
    for (int i = 0; root->children[i]; i++){
        if (findParent_(root->children[i], firstSpecies, secondSpecies, found))
            return root;
    }

  for (int i = 0; root->children[i]; i++){
            if (findParent_(root, firstSpecies, secondSpecies, found))
                return root;
            if (*found == 2)
                return root;
            if (!strcmp(root->children[i]->name, firstSpecies))
                ++*found;
            else if (!strcmp(root->children[i]->name, secondSpecies))
                ++*found;
//            if (*found > 0)
//                printf("found: %d\n", *found);
        }*/