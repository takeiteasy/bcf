//
//  cf.h
//  cf
//
//  Created by Rory B. Bellows on 25/05/2020.
//  Copyright © 2020 Rory B. Bellows. All rights reserved.
//

#ifndef CF_H
#define CF_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>
#include <stdarg.h>

#define CF_MAGIC 0x4346

struct cf_header {
  short magic;
  int n_files;
};

struct cf_entry {
  long long name_sz, f_sz, f_off;
  unsigned int hash;
};

struct cf_tree_entry {
  struct cf_entry entry;
  char* fp;
};

struct cf_tree {
  struct cf_tree_entry* entries;
  int n_entries;
  long long fsize;
  FILE* fh;
};

void cfwrite(const char* path, int n, ...);
void cfread(struct cf_tree* tree, const char* path);
struct cf_entry* cffind(struct cf_tree* tree, const char* path);
unsigned char* cfdata(struct cf_tree* tree, struct cf_entry* entry);
void cffree(struct cf_tree* tree);

#endif // CF_H