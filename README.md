# ABDatabase
**ABDatabase** is used to access a SQLite database from Objective-C.  
Easy wrapper for SQLite which simplify the SQL query into easy to remember methods and its argument.  

    adb = [[ABDatabase alloc]initWithFile:@"database.sqlite"];
    
## Delegate :
Use can use delegate method to track the database update and so that we can update view of the Data.

## Installation :
You can simply drag the ABDatabase.h/.m file in your project to use this library.  
Dont forgot to add libsqlite3.0.dylib from Build Phase.
