#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "printf/ft_printf.h"

// NOTES :
// PENSER A TRAITER LES > INT
//
// 
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////

typedef struct s_node
{
	int	content;
	int cost;
	int current_pos;
	bool above_median;
	bool cheapest;
	struct s_node *target_node;
	struct s_node *previous;
	struct s_node *next;
}	t_node;


// MOUVEMENTS //////////////////////////////
// push.c Ca push 
bool	ft_push(t_node **src, t_node **dst);
bool	ft_push_a(t_node **s_a, t_node **s_b, bool checker);
bool	ft_push_b(t_node **s_a, t_node **s_b, bool checker);

// reverse_rotate.c Ca rotate mais a l'envers
bool	ft_reverse_rotate(t_node **stack);
bool	ft_rr_a(t_node **s_a, bool checker);
bool	ft_rr_b(t_node **s_b, bool checker);
bool	ft_rrr(t_node **s_a, t_node **s_b, bool checker);
// rotate.c Ca rotate
bool	ft_rotate(t_node **stack);
bool	ft_rotate_a(t_node **a, bool checker);
bool	ft_rotate_b(t_node **b, bool checker);
bool	ft_rotate_both(t_node **a, t_node **b, bool checker);

// swap.c Ca swap 
bool	ft_swap(t_node **stack);
bool	ft_swap_a(t_node **a, bool checker);
bool	ft_swap_b(t_node **b, bool checker);
bool	ft_swap_both(t_node **a, t_node **b, bool checker);

// COUTS ET POSITIONS //////////////////////////////
// position.c Gestion des positions Current + Target
bool	ft_affect_current(t_node *stack);
bool	ft_affect_median(t_node *stack);
// cost.c Gere ce qui est associe au cout
bool	ft_find_target_node(t_node *active, t_node *passive);
bool	ft_affect_cost(t_node *active, t_node *passive);
bool	ft_find_cheapest(t_node *stack);


// ALGO ET TRI  //////////////////////////////
// sorting.c Gestion du tri
bool	ft_mini_sort(t_node **s_a);
bool	ft_sorting(t_node **s_a,t_node **s_b);

// PARSING //////////////////////////////
// parsing.c Gestion du parsing
int		ft_check_digit(char *str, bool space);
bool	ft_check_double(t_node *stack);
int		ft_space_found(char *str);
int		ft_stack_sorted(t_node *stack);
bool	ft_split_init(char *str, t_node **s_a);
bool	ft_parsing(char **argv, t_node **s_a);

// UTILITAIRES //////////////////////////////
// init.c Cree et refresh les nodes
t_node *ft_node_init (int value);
void ft_node_addback (int content, t_node **stack);
bool ft_set_nodes_a(t_node *s_a, t_node *s_b);
bool ft_set_nodes_b(t_node *s_b, t_node *s_a);

// free.c Adieu les leaks
int		ft_free_node(t_node *node);
int		ft_free_all(t_node *s_a, t_node *s_b);

// output_utils.c Gestion des outputs
int		ft_write_digit(char nb);
int		ft_write(char *str);

//error_utils.c Gestion des erreurs
int		ft_error_message(void);
void	ft_abort_array(char **array);

// number_utils.c Gestion des conversions int et char
bool	ft_atoi_checked(long nb);
long	ft_atol(const char *nptr);

// node_utils.c Gestion des noeuds
t_node	*ft_node_init (int value);
t_node	*ft_node_findlast (t_node *list);
int		ft_stack_len(t_node *stack);
t_node	*ft_find_smallest(t_node *stack);
t_node	*ft_find_biggest(t_node *stack);

// sorting_utils.c Gestion des elements de tri
bool	ft_set_nodes(t_node *active, t_node *passive);
bool	ft_move_sort(t_node *active, t_node *passive);
bool	ft_final_sort(t_node *s_a);

// split.c Bah split
size_t	ft_checkcheck_split(char const *s, char c);
char	*ft_splitcpy(char const *s, size_t min, size_t max);
void	ft_clearall(size_t	nb, char **pps);
int		ft_cpycpy(char *s, char c, char **pps);
char	**ft_split(char *s, char c);

// extras.c Ptites choses pour tester plus simplement
int		ft_strcmp(char *s1, char *s2);
void	ft_print_stack_content(t_node *stack, char *content);

// MAIN //////////////////////////////
// main.c ...
int		main (int argc, char **argv);
////////////////////////////////////////////////////////////


#endif