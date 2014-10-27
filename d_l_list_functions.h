enum constants {
    OK,         ///< Success
    ERR_MEM,    ///< Impossible to allocate memory
    EMPTY,      ///< List is empty.
    NOT_EMPTY,  ///< All other states.
    EMPTY_LINK, ///< Right or left border is achieved
    ERR_ACCESS, ///< Impossible to rewrite first and last elements.
    SPOILT      ///< List is not able to work.
};

typedef double data_t;

struct element {    ///< Structure of element
    data_t data;    ///< Content
    element* nxt;   ///< Pointer to the next element
    element* prvs;  ///< Pointer to the prior element
};

struct List {
    element* ptr;       ///< pointer to the current element
    element* first;     ///< pointer to the first element of the list
    element* last;      ///< pointer to the last element of the list
};

//============================================================================
/*! \fn    int list_ctor (List* L);
    \brief Constructor of doubly-linked list
*/
//============================================================================
int list_ctor (List* L);
//============================================================================

//============================================================================
/*! \fn    int inp_nxt (List* L, data_t data);
    \brief Insert new element right
*/
//============================================================================
int inp_nxt (List* L, data_t data);
//============================================================================

//============================================================================
/*! \fn    int inp_prvs (List* L, data_t data);
    \brief Insert new element left
*/
//============================================================================
int inp_prvs (List* L, data_t data);
//============================================================================

//============================================================================
/*! \fn    int extract (List* L, data_t* value);
    \brief Extract current element
*/
//============================================================================
int extract (List* L, data_t* value);
//============================================================================

//============================================================================
/*! \fn    int shft_ptr_nxt (List* L);
    \brief Shift pointer to the next element
*/
//============================================================================
int shft_ptr_nxt (List* L);
//============================================================================

//============================================================================
/*! \fn    int shft_ptr_prvs (List* L);
    \brief Shift pointer to the previous element
*/
//============================================================================
int shft_ptr_prvs (List* L);
//============================================================================
//============================================================================
/*! \fn    int shft_to_first (List* L);
    \brief Shift pointer to the beginning
*/
//============================================================================
int shft_to_first (List* L);
//============================================================================
//============================================================================
/*! \fn    int shft_to_last (List* L);
    \brief Shift pointer to the end
*/
//============================================================================
int shft_to_last (List* L);
//============================================================================
//============================================================================
/*! \fn    int check_empty (List* L);
    \brief Check if list is empty
*/
//============================================================================
int check_empty (List* L);
//============================================================================
//============================================================================
/*! \fn    void list_dtor (List* L);
    \brief Destructor of doubly-linked list
*/
//============================================================================
void list_dtor (List* L);
//============================================================================
