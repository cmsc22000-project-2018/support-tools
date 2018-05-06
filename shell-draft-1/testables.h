const trie_t t1 = {"t1"};
const trie_t t2 = {"t2"};
const trie_t t3 = {"t3"};
const trie_t t4 = {"t4"};

const trie_t* tries[] = {&t1,&t2,&t3,&t4};

const int num_tries = 4;

/*

typedef struct trie_t{
  struct trie_t* children[256];
  int is_word;
  struct trie_t* parent;
  char current;
} trie_t;

*/
