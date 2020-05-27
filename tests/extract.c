#include "../src/bcf.h"
          
int main(int argc, const char* argv[]) {
  struct bcf_tree tree;
  bcfread(&tree, "tests/test.bcf");
  
  struct bcf_tree_entry* e = NULL;
  for (int i = 0; i < tree.n_entries; ++i) {
    e = &tree.entries[i];
    char buf[255];
    sprintf(buf, ".%s", strrchr(e->fp, '/'));
    
    unsigned char* data = bcfdata(&tree, &e->entry);
    FILE* tmp = fopen(buf, "w");
    fwrite(data, e->entry.f_sz * sizeof(unsigned char), 1, tmp);
    fclose(tmp);
    free(data);
  }
  bcffree(&tree);
  return 0;
}
