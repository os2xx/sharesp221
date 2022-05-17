#define SIMPLEFS_MAGIC 0x10032013
#define SIMPLEFS_DEFAULT_BLOCK_SIZE 4096
#define SIMPLEFS_FILENAME_MAXLEN 255

const int SIMPLEFS_ROOTDIR_INODE_NUMBER = 1;
const int SIMPLEFS_ROOTDIR_DATABLOCK_NUMBER = 2;

struct simplefs_dir_record {
    char filename[SIMPLEFS_FILENAME_MAXLEN];
    uint64_t inode_no;
};

struct simplefs_inode {
    mode_t mode;
    uint64_t inode_no;
    uint64_t data_block_number;

    union {
        uint64_t file_size;
        uint64_t dir_children_count;
    };
};

struct simplefs_super_block {
    uint64_t version;
    uint64_t magic;
    uint64_t block_size;
    uint64_t inodes_count;
    uint64_t free_blocks;

    struct simplefs_inode root_inode;

    char padding[SIMPLEFS_DEFAULT_BLOCK_SIZE - (4 * sizeof(uint64_t))];
};
