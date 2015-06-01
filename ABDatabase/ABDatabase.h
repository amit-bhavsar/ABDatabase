//
//  ABDatabase.h
//  ABDatabase
//
//  Created by Amit on 01/06/15.
//  Copyright (c) 2015 AmitBhavsar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@protocol ABDatabaseDelegate <NSObject>
@optional
- (void)databaseTableWasUpdated:(NSString *)table;
@end


@interface ABDatabase : NSObject
{
	sqlite3 *dbh;
	BOOL dynamic;
}

@property (assign) id<ABDatabaseDelegate> delegate;
@property sqlite3 *dbh;
@property BOOL dynamic;
/**
 *  Initialize the object, copy the sqlite file to Document folder if necessary and open sqlite database
 *
 *  @param dbFile Name of the sqlite file
 *
 *  @return It returns ABDatabase object
 */
- (id)initWithFile:(NSString *)dbFile;

/**
 *  Initialize the object, choose this option if there is only select operation
 *
 *  @param dbFile Name of the sqlite file
 *
 *  @return It returns ABDatabase object
 */
- (id)initWithReadOnlyFile:(NSString *)dbFile;

/**
 *  Initialize the object with NSData object of sqlite file.
 This method write the sqlite file to Document folder from NSData.
 *
 *  @param data   SQLite file in NSData format
 *  @param dbFile Name of the sqlite file
 *
 *  @return It returns ABDatabase object
 */
- (id)initWithData:(NSData *)data andFile:(NSString *)dbFile;

/**
 *  close the Database
 */
- (void)close;

/**
 *  Methods used for Select query purpose
 *
 *
 */
- (id)lookupColForSQL:(NSString *)sql;
- (NSDictionary *)lookupRowForSQL:(NSString *)sql;
- (NSArray *)lookupAllForSQL:(NSString *)sql;

- (int)lookupCountWhere:(NSString *)where forTable:(NSString *)table;

- (int)lookupMax:(NSString *)key forTable:(NSString *)table;
- (int)lookupMax:(NSString *)key Where:(NSString *)where forTable:(NSString *)table;
- (int)lookupSum:(NSString *)key Where:(NSString *)where forTable:(NSString *)table;

/**
 *  Methods used for Insert query purpose
 *
 *
 */
- (void)insertArray:(NSArray *)dbData forTable:(NSString *)table;
- (void)insertDictionary:(NSDictionary *)dbData forTable:(NSString *)table;

/**
 *  Methods used for Update query purpose
 *
 *
 */
- (void)updateArray:(NSArray *)dbData forTable:(NSString *)table;
- (void)updateArray:(NSArray *)dbData forTable:(NSString *)table where:(NSString *)where;
- (void)updateDictionary:(NSDictionary *)dbData forTable:(NSString *)table;
- (void)updateDictionary:(NSDictionary *)dbData forTable:(NSString *)table where:(NSString *)where;
- (void)updateSQL:(NSString *)sql forTable:(NSString *)table;

/**
 *  Methods used for Delete query purpose
 *
 *
 */
- (void)deleteWhere:(NSString *)where forTable:(NSString *)table;
- (void) deleteAllFrom:(NSString *)table;

- (BOOL)runDynamicSQL:(NSString *)sql forTable:(NSString *)table;

- (NSString *)escapeString:(NSString *)dirtyString;
@end
