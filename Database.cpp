#include "Database.h"

Database::Database() {}

per database[32];
int count = 0;

per Michael = {"Michael", "06001227D1", 1, true};
per Harrison = {"Harrison", "0600118D97", 2, true};
per empty = {"", "0000000000", -1, false};

void Database::build() {
  database[count] = Michael;
  count = count + 1;
    
  database[count] = Harrison;
  count = count + 1;
}

per Database::get(int index) {
  return database[index];
} 

bool Database::add(String name, String RFID, int fingerID, bool isAdmin) {
  per added = {name, RFID, fingerID, false};
  database[count] = added;
  count = count + 1;
  if (RFID == added.RFID) {
      return true;
  } else {
      return false;
  }
}

bool Database::remove(String name) {
  for (int i = 1; i < count; i++) {
    if (strcmp(name.c_str(), database[i].name.c_str()) == 0) {
      database[i] = database[count - 1];
      database[count - 1] = empty;
      count = count - 1;
      return true;
    }
  }
    
  return false;
}

int Database::length() {
  return count;
}
