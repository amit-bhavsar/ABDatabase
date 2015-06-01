//
//  ViewController.m
//  ABDatabase
//
//  Created by Amit on 01/06/15.
//  Copyright (c) 2015 AmitBhavsar. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
	[super viewDidLoad];
	
	adb = [[ABDatabase alloc]initWithFile:@"EmployeeDB.sqlite"];
	
	
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
	[textField resignFirstResponder];
	return YES;
}

- (IBAction)btnInsertTap:(id)sender
{
	NSDictionary *dictEmployee = @{@"name"   : txtName.text,
								   @"salary" : txtSalary.text,
								   @"city"   : txtCity.text};
	[adb insertDictionary:dictEmployee forTable:@"EmployeeTbl"];
	[self getAllData];
	
}

- (IBAction)btnSelectTap:(id)sender
{
	[self getAllData];
}

- (IBAction)btnUpdateTap:(id)sender
{
	NSDictionary *dictEmployee = @{@"salary" : @"5000"};
	[adb updateDictionary:dictEmployee forTable:@"EmployeeTbl" where:@"name = 'amit'"];
	[self getAllData];
}

- (IBAction)btnDeleteTap:(id)sender
{
	[adb deleteWhere:@"name = 'amit'" forTable:@"EmployeeTbl"];
	[self getAllData];
}

- (void)getAllData
{
	NSLog(@"All Data : %@",[adb lookupAllForSQL:@"select * from EmployeeTbl"]);
}

- (void)didReceiveMemoryWarning {
	[super didReceiveMemoryWarning];
	// Dispose of any resources that can be recreated.
}

@end
