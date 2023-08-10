#ifndef Database_H
#define Database_H
#include "Arduino.h"

struct per {
  String name;
  String RFID;
  int fingerID;
  bool isAdmin;
};

class Database {
   public:
Database();
void build();
per get(int index);
bool add(String name, String RFID, int fingerID, bool isAdmin);
bool remove(String name);
int length();
};

#endif
