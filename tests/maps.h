#include <stdio.h>
#include <assert.h>

#include "utils/map/map.h"

// !TODO add more tests
void testMaps() {
  printf("Test maps:\n");

  printf("\t- create map\n");
  Map *map = createMap(sizeof(int));
  assert(map != NULL);

  printf("\t- get map size\n");
  assert(mapSize(map) == 0);


  printf("\t- map set element\n");
  int val = 0;
  mapSet(map, "abcd", &val);
  val = 1;
  mapSet(map, "abCd", &val);
  val = 2;
  mapSet(map, "aaCd", &val);
  val = 3;
  mapSet(map, "az", &val);
  val = 4;
  mapSet(map, "aaCd", &val);
  val = 5;
  mapSet(map, "abcd", &val);

  printf("\t- check map size after sel elements\n");
  assert(mapSize(map) == 4);

  printf("\t- check map elements\n");
  assert(1 == *(int*) mapGet(map, "abCd"));
  assert(3 == *(int*) mapGet(map, "az"));
  assert(4 == *(int*) mapGet(map, "aaCd"));
  assert(5 == *(int*) mapGet(map, "abcd"));

  printf("\t- get first prefix key's size\n");
  assert(mapGetFirstPrefixKeySize(map, "abcdefg") == 4);
  assert(mapGetFirstPrefixKeySize(map, "zzz") == 0);
  assert(mapGetFirstPrefixKeySize(map, "abc") == 0);

  printf("\t- ittrerate through map\n");
  Map *map_to_itterate = createMap(sizeof(int));

  MapItterator *it = mapBegin(map_to_itterate);
  assert(mapItteratorIsEnded(it));

  val = 0;
  mapSet(map_to_itterate, "0", &val);
  val = 1;
  mapSet(map_to_itterate, "1", &val);
  val = 2;
  mapSet(map_to_itterate, "2", &val);
  val = 3;
  mapSet(map_to_itterate, "3", &val);

  int size = 0;
  for (MapItterator *i = mapBegin(map_to_itterate); !mapItteratorIsEnded(i); mapItteratorNext(i)) {
    ++size;
    assert(mapItteratorGet(i).key[0] - '0' == *(int*) mapItteratorGet(i).value);
  }

  assert(size == mapSize(map_to_itterate));

  printf("Test maps: OK\n");
}
