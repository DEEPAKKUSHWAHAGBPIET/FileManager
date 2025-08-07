#ifndef LRU_CACHE
#define LRU_CACHE

#define CACHE_SIZE 5
#define KEY_SIZE 32
#define DATA_SIZE 256

// typedef struct cache_node {
//     char key[KEY_SIZE];
//     char data[DATA_SIZE];
//     struct cache_node *prev;
//     struct cache_node *next;
// }cache_node_t;

// typedef struct lru_cache {
//     cache_node_t *head; //MRU
//     cache_node_t *tail; //LRU
//     cache_node_t *nodes[CACHE_SIZE];
//     int count;
//     int capacity;
// }lru_cache_t;
typedef struct cached_file {
    char filename[256];
    buffer_t *buffer;
    size_t file_size;
    time_t last_accessed;
    struct cached_file *next;
    struct cached_file *lru_next;
    struct cached_file *lru_prev;
}cached_file_t;

typedef struct file_cache {
    buffer_pool_t *buffer_pool;
    cached_file_t *files[CACHE_SIZE];
    int cached_files_count;
    cached_file_t *cache_head;
    cached_file_t *cache_tail;
}file_cache_t;

unsigned int hash(const char *key);
//lru_cache_t* create_lru_cache();
void move_to_front(file_cache_t* cache, cached_file_t* node);
void add_to_front(file_cache_t* cache, cached_file_t *newNode);
void lru_file_remove(file_cache_t *cache);
void print_lru_status(file_cache_t *cache);
// char* cache_get(lru_cache_t *cache, const char *key);
// void cache_put(lru_cache_t *cache, const char *key, const char *data);

#endif