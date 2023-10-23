typedef struct s_d_cell {
    int value;
    struct s_d_cell *next_0;
    struct s_d_cell *next_1;
} t_d_cell;

// Structure de la liste à deux niveaux
typedef struct s_d_list {
    t_d_cell *head_0;
    t_d_cell *head_1;
} t_d_list;


