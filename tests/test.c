#include "../src/cf.h"
          
int main(int argc, const char* argv[]) {
  const char** test_files = malloc(3 * sizeof(const char*));
  test_files[0] = "tests/res/test.png";
  test_files[1] = "tests/res/test2.png";
  test_files[2] = "tests/res/test3.png";
  cfwrite("build/test.cf", 3, test_files);
  free(test_files);
  
  struct cf_tree tree;
  cfread(&tree, "build/test.cf");
  struct cf_entry* entry = cffind(&tree, "tests/res/test2.png");
  unsigned char* data = cfdata(&tree, entry);
  FILE* fh = fopen("build/out.png", "w");
  fwrite(data, entry->f_sz * sizeof(unsigned char), 1, fh);
  fclose(fh);
  free(data);
  cffree(&tree);
  return 0;
}