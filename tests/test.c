#include "../src/cf.h"

int main(int argc, const char* argv[]) {
  cfwrite("build/test2.cf", 15,
          "/Users/roryb/Pictures/test/brick.png",
          "/Users/roryb/Pictures/test/concrete.png",
          "/Users/roryb/Pictures/test/dark.png",
          "/Users/roryb/Pictures/test/fire.png",
          "/Users/roryb/Pictures/test/gold.png",
          "/Users/roryb/Pictures/test/grass.png",
          "/Users/roryb/Pictures/test/purple.png",
          "/Users/roryb/Pictures/test/sky.png",
          "/Users/roryb/Pictures/test/skybox.png",
          "/Users/roryb/Pictures/test/test.png",
          "/Users/roryb/Pictures/test/test2.png",
          "/Users/roryb/Pictures/test/test3.png",
          "/Users/roryb/Pictures/test/test_atlas.png",
          "/Users/roryb/Pictures/test/water.png",
          "/Users/roryb/Pictures/test/wood.png");
  
  struct cf_tree tree;
  cfread(&tree, "build/test2.cf");
  struct cf_entry* entry = cffind(&tree, "/Users/roryb/Pictures/test/sky.png");
  unsigned char* data = cfdata(&tree, entry);
  FILE* fh = fopen("build/sky.png", "w");
  fwrite(data, entry->f_sz * sizeof(unsigned char), 1, fh);
  fclose(fh);
  free(data);
  cffree(&tree);
  return 0;
}