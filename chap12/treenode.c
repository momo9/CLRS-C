#include <stdio.h>
#include <stdlib.h>
#include "treenode.h"
#include "stack.h"

static void valcpy(KeyType *dst, KeyType *src) {
  *dst = *src;
}

static int valcmp(KeyType *k1, KeyType *k2) {
  if (*k1 < *k2) {
    return -1;
  }
  if (*k1 > *k2) {
    return 1;
  }
  return 0;
}

static void intput(TreeNode *ptree) {
  printf("%d ", *ptree->ptrkey);
}

static void allput(TreeNode *ptree) {
  printf("Node: ");
  printf((ptree == NULL) ? "%s\n" : "%d\n", 
        (ptree == NULL) ? "NULL" : *ptree->ptrkey);
  printf("------------------\n");
  printf("Par: ");
  printf((ptree->par == NULL) ? "%s\n" : "%d\n", 
        (ptree->par == NULL) ? "NULL" : *ptree->par->ptrkey);
  printf("Left: ");
  printf((ptree->left == NULL) ? "%s\n" : "%d\n", 
        (ptree->left == NULL) ? "NULL" : *ptree->left->ptrkey);
  printf("Right: ");
  printf((ptree->right == NULL) ? "%s\n" : "%d\n", 
        (ptree->right == NULL) ? "NULL" : *ptree->right->ptrkey);
  printf("\n");
}

static void (*keycpy)(void *dst, void *src) = valcpy;
static int  (*keycmp)(void *k1 , void *k2 ) = valcmp;
static void (*keyput)(void *ptree) = intput;

TreeNode *addnode(TreeNode *proot, KeyType *ptrkey) {
  if (proot == NULL) {
    // add a new node
    proot = malloc(sizeof(TreeNode));
    proot->par = NULL;
    proot->left = NULL;
    proot->right = NULL;
    proot->ptrkey = malloc(sizeof(KeyType));
    keycpy(proot->ptrkey, ptrkey);
    return proot;
  }

  if (keycmp(ptrkey, proot->ptrkey) < 0) {
    // less than key, left side
    proot->left = addnode(proot->left, ptrkey);
    proot->left->par = proot;
    return proot;
  }

  // more than key, right side
  proot->right = addnode(proot->right, ptrkey);
  proot->right->par = proot;
  return proot;
}

void puttree(TreeNode *proot) {
  if (proot != NULL) {
    puttree(proot->left);
    keyput(proot);
    puttree(proot->right);
  }
}

TreeNode *freenode(TreeNode *proot) {
  if (proot != NULL) {
    proot->left = freenode(proot->left);
    proot->right = freenode(proot->right);
    //keyput(proot);
    free(proot->ptrkey);
    free(proot);
  }
  return NULL;
}

void puttree_stack(TreeNode *proot) {
  while (proot != NULL || !stackempty()) {
    // reach the most left
    while (proot != NULL) {
      push(proot);
      proot = proot->left;
    }
    proot = pop();
    keyput(proot);
    proot = proot->right;
  }
}

void puttree_nostack(TreeNode *proot) {
  TreeNode *pleft = NULL;
  while (1) {
    // get most left
    while (proot->left != pleft) {
      proot = proot->left;
    }
    // put
    keyput(proot);
    //fflush(stdout);
    // get right + backtrace
    if (proot->right != NULL) {
      proot = proot->right;
      pleft = NULL;
      continue;
    }
    // backtrace
    while (proot->par != NULL && proot->par->right == proot) {
      proot = proot->par;
    }
    if (proot->par == NULL) {
      break;
    }
    // block the left route
    proot = proot->par;
    pleft = proot->left;
  }
}

void treemin(TreeNode *p, KeyType *k) {
  static KeyType keybuf;

  if (p->left != NULL) {
    treemin(p->left, NULL);
  } else {
    keycpy(&keybuf, p->ptrkey);
  }

  if (k != NULL) {
    keycpy(k, &keybuf);
  }
}
void treemax(TreeNode *p, KeyType *k) {
  static KeyType keybuf;

  if (p->right != NULL) {
    treemax(p->right, NULL);
  } else {
    keycpy(&keybuf, p->ptrkey);
  }

  if (k != NULL) {
    keycpy(k, &keybuf);
  }
}

TreeNode *nodemin(TreeNode *p) {
  if (p->left == NULL) {
    return p;
  }
  return nodemin(p->left);
}
TreeNode *nodemax(TreeNode *p) {
  if (p->right == NULL) {
    return p;
  }
  return nodemax(p->right);
}

void putnode(TreeNode *n) {
  keyput(n);
}

TreeNode *search(TreeNode *pt, KeyType *p) {
  if (NULL == pt) {
    return NULL;
  }
  // fprintf(stderr, "%d\n", *pt->ptrkey);
  int cmp;
  if (0 == (cmp = keycmp(p, pt->ptrkey))) {
    return pt;
  }
  if (cmp < 0) {
    return search(pt->left, p);
  } else {
    return search(pt->right, p);
  }
}

TreeNode *predecessor(TreeNode *pn) {
  if (NULL != pn->left) {
    return nodemax(pn->left);
  } else {
    TreeNode *p;
    while (NULL != (p = pn->par)) {
      if (p->right == pn) {
        return p;
      }
      pn = p;
    }
    return NULL;
  }
}

TreeNode *successor(TreeNode *pn) {
  if (NULL != pn->right) {
    return nodemin(pn->right);
  } else {
    TreeNode *p;
    while (NULL != (p = pn->par)) {
      if (p->left == pn) {
        return p;
      }
      pn = p;
    }
    return NULL;
  }
}

// return the root
TreeNode *replace(TreeNode *proot, TreeNode *dst, TreeNode *src) {
  // if (NULL != src) {
  //   fprintf(stderr, "src: %d\n", *src->ptrkey);
  // }
  // if (NULL != dst) {
  //   fprintf(stderr, "dst: %d\n", *dst->ptrkey);
  // }
  if (dst->par == NULL) {
    // dst is root
    free(dst->ptrkey);
    free(dst);
    if (NULL != src) {
      src->par = NULL;
    }
    return src;
  }
  if (NULL != src) {
    src->par = dst->par;
    // fprintf(stderr, "par: %d\n", *src->par->ptrkey);
  }
  if (dst->par->left == dst) {
    dst->par->left = src;
  } else {
    dst->par->right = src;
  }
  free(dst->ptrkey);
  free(dst);
  return proot;
}

// return the root
TreeNode *delnode(TreeNode *proot, TreeNode *p) {
  if (NULL == p->left) {
    // fprintf(stderr, "left is null\n");
    proot = replace(proot, p, p->right);
    return proot;
  }
  if (NULL == p->right) {
    proot = replace(proot, p, p->left);
    return proot;
  }
  TreeNode *succ = successor(p);
  if (succ == p->right) {
    // The successor of p is the right node of it.
    // Set the successor's left (successor has no left) as p's left.
    succ->left = p->left;
    succ->left->par = succ;

    // Replace p with successor.
    proot = replace(proot, p, succ);
  } else {
    // fprintf(stderr, "p: %d\n", *p->ptrkey);
    // fprintf(stderr, "succ: %d\n", *succ->ptrkey);
    static KeyType buf;
    // Buffer the value of successor.
    keycpy(&buf, succ->ptrkey);
    // fprintf(stderr, "buf: %d\n", buf);
    // fprintf(stderr, "succ->right: %p\n", succ->right);
    // 
    // Replace successor with its right.
    proot = replace(proot, succ, succ->right);
    // Set p's value as buffered value.
    keycpy(p->ptrkey, &buf);
  }
  return proot;
}
