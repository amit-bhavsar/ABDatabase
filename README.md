# ABDatabase
**ABDatabase** is used to access a SQLite database from Objective-C.  
Easy wrapper for SQLite which simplify the SQL query into easy to remember methods and its argument.  

    //EmployeeTbl(name,salary,city) 
    adb = [[ABDatabase alloc]initWithFile:@"EmployeeDB.sqlite"];
    
    //Select Query : 
    [adb lookupAllForSQL:@"select * from EmployeeTbl"];
    
    //Insert Query:
    NSDictionary *dictEmployee = @{@"name"   : txtName.text,
								   @"salary" : txtSalary.text,
								   @"city"   : txtCity.text};
	[adb insertDictionary:dictEmployee forTable:@"EmployeeTbl"];
    
    //Update Query: 
    NSDictionary *dictEmployee = @{@"salary" : @"50000”};
	[adb updateDictionary:dictEmployee forTable:@"EmployeeTbl" where:@"name = 'amit'"];
	
	//Delete Query :
    [adb deleteWhere:@"name = 'amit'" forTable:@"EmployeeTbl"];
	


    
## Delegate :
Use can use delegate method to track the database update and so that we can update view of the Data.

## Installation :
You can simply drag the ABDatabase.h/.m file in your project to use this library.  
Dont forgot to add libsqlite3.0.dylib from Build Phase.
