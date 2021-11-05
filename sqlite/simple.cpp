#include <stdio.h>
02  #include <sqlite3.h>
03  
04  static int callback(void *NotUsed, int argc, char **argv, char **azColName){
05    int i;
06    for(i=0; i<argc; i++){
07      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
08    }
09    printf("\n");
10    return 0;
11  }
12  
13  int main(int argc, char **argv){
14    sqlite3 *db;
15    char *zErrMsg = 0;
16    int rc;
17  
18    if( argc!=3 ){
19      fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
20      return(1);
21    }
22    rc = sqlite3_open(argv[1], &db);
23    if( rc ){
24      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
25      sqlite3_close(db);
26      return(1);
27    }
28    rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
29    if( rc!=SQLITE_OK ){
30      fprintf(stderr, "SQL error: %s\n", zErrMsg);
31      sqlite3_free(zErrMsg);
32    }
33    sqlite3_close(db);
34    return 0;
35  }
