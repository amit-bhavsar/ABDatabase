//
//  ViewController.h
//  ABDatabase
//
//  Created by Amit on 01/06/15.
//  Copyright (c) 2015 AmitBhavsar. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABDatabase.h"
@interface ViewController : UIViewController<UITextFieldDelegate>
{
	ABDatabase *adb;
	
	IBOutlet UITextField *txtName;
	
	IBOutlet UITextField *txtSalary;
	
	IBOutlet UITextField *txtCity;
	
}

@end

