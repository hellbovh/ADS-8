// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train(): countOp(0), first(nullptr) {}

void Train::addCage(bool light)
{
  Cage* cage = new Cage;
  cage->light = light;
  if (first == nullptr) {
    first = cage;
    first->next = first;
    first->prev = first;
  } else {
    cage->next = first;
    cage->prev = first->prev;
    first->prev = cage;
    cage->prev->next = cage;
  }
}

int Train::getLength() {
  Cage* cage = first;
  cage->light = true;
  int count = 1;
  while (cage) {
    cage = cage->next;
    if (cage->light == false) {
      ++count;
      ++countOp;
    }
    if (cage->light == true) {
      ++countOp;
      cage->light = false;
      for (int i = count; i > 0; i--) {
        cage = cage->prev;
        ++countOp;
      }
      if (cage->light == false) {
        return count;
      } else {
        count = 1;
      }
    }
  }
}

int Train::getOpCount() {
  return countOp;
}
