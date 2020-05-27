//
//  bcf.h
//  bcf
//
//  Created by Rory B. Bellows on 25/05/2020.
//  Copyright © 2020 Rory B. Bellows. All rights reserved.
//

#ifndef BCF_H
#define BCF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define BCF_MAGIC 0x4346

struct bcf_header {
  int magic, n_files;
};

struct bcf_entry {
  long long name_sz, f_sz, f_off;
  unsigned long long hash;
};

struct bcf_tree_entry {
  struct bcf_entry entry;
  char* fp;
};

struct bcf_tree {
  struct bcf_tree_entry* entries;
  int n_entries;
  long long fsize;
  FILE* fh;
};

void bcfwrite(const char* path, int n, const char** files);
void bcfread(struct bcf_tree* tree, const char* path);
struct bcf_entry* bcffind(struct bcf_tree* tree, const char* path);
unsigned char* bcfdata(struct bcf_tree* tree, struct bcf_entry* entry);
void bcffree(struct bcf_tree* tree);

#endif // BCF_H
